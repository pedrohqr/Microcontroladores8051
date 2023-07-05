#include "..\def_pinos.h"
#include "config.c"
#include <string.h>

/*
Pedro Henrique de Queiroz Ramos
Fernando Peixoto
*/

	unsigned char PAux = 0x00; // Porta de LEDs auxiliar entre P3 e P4
	__code unsigned char mat[44][4] = {	{0xFF, 0x81, 0x81, 0xFF}, 
										{0x84, 0x82, 0xFF, 0x80},
										{0xC3, 0xA1, 0x91, 0x8E},
										{0x42, 0x89, 0x89, 0x76},
										{0x18, 0x14, 0x12, 0xFF},
										{0x4F, 0x89, 0x89, 0x71},
										{0x7C, 0x8A, 0x89, 0x71},
										{0x01, 0xF1, 0x09, 0x07},
										{0x76, 0x89, 0x89, 0x76},
										{0x4E, 0x91, 0x91, 0x7E},

										{0x00, 0x66, 0x66, 0x00},
										{0x00, 0x67, 0x64, 0x00},
										{0x10, 0x28, 0x44, 0x00},
										{0x28, 0x28, 0x28, 0x00},
										{0x44, 0x28, 0x10, 0x00},
										{0x06, 0xB1, 0x09, 0x06},
										{0x3C, 0x42, 0x5A, 0x5C},

										{0xFE, 0x11, 0x11, 0xFE},
										{0xFF, 0x89, 0x89, 0x76},
										{0x7E, 0x81, 0x81, 0x42},
										{0xFF, 0x81, 0x81, 0x7E},
										{0x76, 0x89, 0x89, 0x42},
										{0xFF, 0x09, 0x09, 0x01},
										{0x7E, 0x81, 0x91, 0x72},
										{0xFF, 0x08, 0x08, 0xFF},
										{0x81, 0xFF, 0x81, 0x00},
										{0x61, 0x81, 0x7F, 0x01},
										{0xFF, 0x08, 0x14, 0xE3},
										{0xFF, 0x80, 0x80, 0x80},
										{0xFF, 0x04, 0x04, 0xFF},
										{0xFF, 0x0E, 0x70, 0xFF},
										{0x7E, 0x81, 0x81, 0x7E},
										{0xFF, 0x11, 0x11, 0x0E},
										{0x7E, 0xA1, 0xC1, 0xFE},
										{0xFF, 0x11, 0x31, 0xCE},
										{0x46, 0x89, 0x89, 0x72},
										{0x03, 0xFF, 0xFF, 0x03},
										{0x7F, 0x80, 0x80, 0x7F},
										{0x3F, 0xC0, 0xC0, 0x3F},
										{0xFF, 0x18, 0x18, 0xFF},
										{0x81, 0x7E, 0x7E, 0x81},
										{0x07, 0xF8, 0xF8, 0x07},
										{0xE1, 0x91, 0x89, 0x87},
										{0xFF, 0xFF, 0xFF, 0xFF}
										};


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

// Limpa a matriz de led
void clear()
{
	P0 = P1 = P2 = P3 = PAux = 0;
	SFRPAGE = CONFIG_PAGE;
	P4 = P5 = P6 = P7 = 0;
	SFRPAGE = LEGACY_PAGE;
}

// Desloca as colunas para a esquerda de P0 a P6
void copyP0_P6()
{
	P0 = P1;
	P1 = P2;
	P2 = P3;
	P3 = PAux;
	SFRPAGE = CONFIG_PAGE;
	PAux = P4;
	P4 = P5;
	P5 = P6;
	P6 = P7;
	SFRPAGE = LEGACY_PAGE;
}

// Desloca um texto na matriz de LED utilizando as 8 portas em t milisegundos
void desloca_texto(unsigned char* text, unsigned int t)
{
	unsigned int i, j = 0;
	unsigned int len = strlen(text); // Tamanho de "text"
	unsigned int posP7Shown = 0; // Posicao atual mostrada da letra atual exibida em P7

	// Limpa o display
	clear();

	// A cada iteracao, desloca em 1 coluna para a esquerda (consideramos que temos 9 colunas de LEDs)
	for(i = 0; i < (len*5)+4; i++)
	{
		// Se a letra atual for mostada entre primeira e a terceira coluna de digitos
		if(posP7Shown >= 0 && posP7Shown < 3)
		{
			// Copia do P0 ao P6 o valor das portas (Pn+1) e define P7 como a posicao atual da letra atual
			copyP0_P6();
			SFRPAGE = CONFIG_PAGE;
			P7 = mat[text[j] - 48][posP7Shown];
			SFRPAGE = LEGACY_PAGE;

			// Incrementa para a proxima coluna da letra a exibir
			posP7Shown++;
		}
		else if (posP7Shown == 3) // Se a letra atual for mostrada na quarta coluna de digitos
		{
			// Copia do P0 ao P6 o valor das portas (Pn+1) e define P7 como a posicao atual da letra atual
			copyP0_P6();
			SFRPAGE = CONFIG_PAGE;
			P7 = mat[text[j] - 48][posP7Shown];
			SFRPAGE = LEGACY_PAGE;

			// Reseta para a primeira coluna da proxima letra
			posP7Shown = 0;
			j++;
		}


		// Aguarda t ms
		delay_ms(t);
	}

	clear();
}


void main(void)
{
	int i;

	Init_Device();
	SFRPAGE = LEGACY_PAGE;
	clear();

	while(1)
	{
		desloca_texto("PEDRO", 500);
	}
}