/*
Pedro Henrique de Queiroz Ramos
Gustavo Felipe Gon�alves Reis
*/

#include "..\util.h"
#include <stdio.h>

#define R 1
#define W 0

unsigned char 
esc_byte_cntr(unsigned char end_disp, __bit RW)
{
	STA = 1; // Gera start
	SI = 0; // Zera flag Status
	while(SI == 0); // Enquanto n�o devolve um status
	if(SMB0STA != 0x08 && SMB0STA != 0x10) // Se n�o foi enviado o Start, retorna status de erro
		return SMB0STA;
	
	SMB0DAT = (end_disp & 0xFE) | RW; // Passa o endere�o do dispositivo e define bit de controle para leitura ou escrita
	STA = 0;
	SI = 0;
	while(SI == 0); // Enquanto n�o devolve status
	if(RW == W) // Escrita do Master
	{
		if(SMB0STA != 0x18) // Se n�o devolveu ACK, retorna erro
			return SMB0STA;
	}
	else // Leitura do Master
	{
		if(SMB0STA != 0x40) // Se n�o devolveu ACK, retorna erro
			return SMB0STA;
	}

	return 0;
}

unsigned char 
esc_byte_dado(unsigned char dado)
{
	// Transmite o byte
	SMB0DAT = dado;
	STA = 0; // Limpa a flag do Start
	SI = 0;
	while(SI == 0); // Enquanto n�o devolve o status
	if(SMB0STA != 0x28) // Se dado n�o foi transmitido ou n�o devolveu ACK, retorna erro
		return SMB0STA;

	return 0;
}

int 
esc_eeprom(unsigned char end_disp, unsigned char end, unsigned char dado)
{
	unsigned char status = 0;

	status = esc_byte_cntr(end_disp, W); // Byte de controle

	if(status != 0) // Se houver erro, retorna
		return -status;

	status = esc_byte_dado(end); // Endere�o do dispositivo

	if(status != 0) // Se houver erro, retorna
		return -status;

	status = esc_byte_dado(dado); // Dado

	if(status != 0) // Se houver erro, retorna
		return -status;
	
	// Gera Stop
	STO = 1;
	SI = 0;
	while(STO == 1);

	return 0;
}

int 
le_eeprom(unsigned char end_disp, unsigned char end)
{
	unsigned char status = 0;

	status = esc_byte_cntr(end_disp, W); // Byte de controle
	
	if(status != 0) // Se houver erro, retorna
		return -status;

	status = esc_byte_dado(end);

	if(status != 0) // Se houver erro, retorna
		return -status;

	status = esc_byte_cntr(0xA0, R);

	if(status != 0) // Se houver erro, retorna
		return -status;

	// Recebe o byte
	AA = 0; // Configura MCU para gerar NACK apos reber o byte
	SI = 0;
	while(SI == 0);
	if(SMB0STA != 0x58)
		return -SMB0STA;

	// Obtem o dado em SMB0DAT
	return SMB0DAT;
}

void
Timer4_ISR(void) interrupt 16
{
	SMB0CN &= ~0x40; // Desabilita SMBus
	SMB0CN |=  0x40; // Habilita SMBus
	TF4 = 0; // Zera flag de interrup��o do Timer4
}

void 
main(void)
{
	int i = 0;
	unsigned char end = 127;
	int status = 0;

	Init_Device();
	SFRPAGE = LEGACY_PAGE;

	// Gera reset no barramento I2C
	SMB0CN &= ~0x40; // Desabilita SMBus
	SMB0CN |=  0x40; // Habilita SMBus

	glcd_init();

	printf_fast_f("\01 Hello World");

	i = le_eeprom(0xA1, end); // Leitura inicial para o contador

	if( i >= 0) // Se n�o deu erro na leitura inicial, procede com o incremento
		for(; i < 256; ++i)
		{
			status = le_eeprom(0xA1, end); // Leitura
			if(status < 0) // Se houver erro na leitura
			{
				printf_fast_f("\03 R Error: 0x%x", -status);
				break;
			}

			// Imprime o conteudo do endereco lido
			printf_fast_f("\02 %d", SMB0DAT);

			status = esc_eeprom(0xA0, end, i); // Escrita
			if(status < 0) // Se houver erro na escrita
			{
				printf_fast_f("\03 W Error: 0x%x", -status);
				break;
			}

			delay_ms(500); // Delay 0,5 segundos

			if(i >= 255) // Se chegar no ultimo valor, zera
			{
				i = 0;
				status = esc_eeprom(0xA0, end, i); // Escrita
				if(status < 0) // Se houver erro na escrita
				{
					printf_fast_f("\03 W Error: 0x%x", -status);
					break;
				}
			}	
		}
	else
		printf_fast_f("\03 R Error: 0x%x", i);

	while(1)
	{
	}
}
