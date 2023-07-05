/*
Pedro Henrique de Queiroz Ramos
Gustavo Felipe Gon�alves Reis
*/

#include "..\util.h"
#include <stdio.h>
#include <stdlib.h>

#define R 1
#define W 0

const char pos = 50;

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
BotaoP0_2() interrupt 0
{
	float f = 3.2;

	//while(!P0_2);

	printf_fast_f("\02 Status W: 0x%x", esc_eeprom(0xA0, pos, ((char)f)>>3));
	printf_fast_f("\02 Status W: 0x%x", esc_eeprom(0xA0, pos+1, ((char)f)>>2));
	printf_fast_f("\02 Status W: 0x%x", esc_eeprom(0xA0, pos+2, ((char)f)>>1));
	printf_fast_f("\02 Status W: 0x%x", esc_eeprom(0xA0, pos+3, (char)f));

	IE0 = 0;
}

void 
main(void)
{
	float f = 0;

	Init_Device();
	SFRPAGE = LEGACY_PAGE;

	// Gera reset no barramento I2C
	SMB0CN &= ~0x40; // Desabilita SMBus
	SMB0CN |=  0x40; // Habilita SMBus

	glcd_init();

	printf_fast_f("\01 Hello World");

	while(1)
	{
		f = 0;
		le_eeprom(0xA1, pos);
		f += SMB0DAT;
		f = (char)f << 1;

		le_eeprom(0xA1, pos+1);
		f += SMB0DAT;
		f = (char)f << 1;

		le_eeprom(0xA1, pos+2);
		f += SMB0DAT;
		f = (char)f << 1;

		le_eeprom(0xA1, pos+3);
		f += SMB0DAT;
		f = (char)f << 1;


		//printf_fast_f("\02 Status R: 0x%x", );
		printf_fast_f("\03 Lido: %.2f", f);
	}
}