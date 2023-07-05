#include "config.c"
#include "..\def_pinos.h"

void delay_ms(unsigned int t)
{
	// Ativa o modo 1 de opera��o de Timer 0 e mantem o valor antigo dos outros bits
	TMOD |= 0x01;
	TMOD &= 0xFD; // 0b11111101
	
	// Para 1 ms
	for(;t > 0; t--)
	{
		TR0 = 0; // Desabilita contagem do Timer0
		TF0 = 0; // Define flag de interrupcao de overflow para 0
		// Define o MSB para 88d
		TL0 = 0x58;
		// Define o LSB para 158d
		TH0 = 0x9E;
		// Habilita a contagem
		TR0 = 1;
		// Enquanto nao ha interrupcao por overflow
		while(TF0 != 1)
			;
	}
}

void delay_us(unsigned int t)
{
	// Desativa o Timer0
	TR0 = 0;

	// Define o modo de operacao do Timer0 para modo 2 (auto reload)
	TMOD |= 0x02;
	TMOD &= 0xFE;

	// Define o valor de recarga
	TH0 = 0xE7; // 256 - 25 = 231
	TL0 = 0xE7;

	for(;t > 0; t--)
	{
		// Ativa o Timer0
		TR0 = 1;
		// Enquanto nao ha interrupcao do T0
		while(TF0 != 1)
			;
		// Desabilita o Timer0
		TR0 = 0;
	}
}

void main(void)
{
	Init_Device();
	SFRPAGE = LEGACY_PAGE;
	P0 = 0;

	while(1){

		P0_0 = 1;
		delay_ms(500);
		P0_0 = 0;
		delay_ms(500);

		// Teste de funcao em us
		/*
		P0_0 = 1;
		delay_us(60000);
		P0_0 = 0;
		delay_us(60000);
		*/
	}

}