#include "..\util.h"
#include <stdio.h>

#define LED P0_7

char byte_serial;

void putchar(char c)
{
	SBUF0 = c;
	while(TI0 != 1); // Enquanto n�o transmitiu, espera
	TI0 = 0; // Limpa flag de interrup��o
}

void int_uart(void) interrupt 4 // Interrup��o UART
{
	if(RI0) // Se recebeu um byte
	{
		if(SBUF0 == 'b') // Se byte for 'b'
			LED = !LED;
		else if(SBUF0 == 'a') // Se byte for 'a'
			printf_fast_f("P1 = %d\n", P1);
		else if(SBUF0 == 'm') // Se byte for 'b'
			printf_fast_f("Menu:\na - Le P1 de P1\nb - Inverte P0_7");
		else // Se for qualquer outra tecla
		{
			byte_serial = SBUF0; // Armazena byte recebido em variavel global
			printf_fast_f("Tecla: '%c'\n", SBUF0); //Imprime a tecla pressionada no PC
		}

		RI0 = 0; // Zera flag de interurp��o 
	}
}

void main(void)
{
	Init_Device();
	SFRPAGE = LEGACY_PAGE;

	while(1)
	{
	}
}