/*
	Pedro Henrique de Queiroz Ramos
	Gustavo Felipe Gon�alves Reis
*/

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
		if(SBUF0 == 'i') // Se byte for 'i'
			LED = !LED;
		else if(SBUF0 == 'a') // Se byte for 'a'
		{	if (PCA0CPH0 > 0)
				printf_fast_f("Carga de trabalho: %.3f%%\n", (256-(float)(--PCA0CPH0))*100/256);}
		else if(SBUF0 == 'd') // Se byte for 'd'
		{	if (PCA0CPH0 < 255)
				printf_fast_f("Carga de trabalho: %.3f%%\n", (256-(float)(++PCA0CPH0))*100/256);}
		else if(SBUF0 == 'm') // Se byte for 'm'
			printf_fast_f("Menu:\ni - Inverte LED\na - Aumenta RPM do motor\nd - Diminui RPM do motor");
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

	printf_fast_f("\n\nInicio\n\n");
	TR0 = 1; // Liga o timer0

	while(1)
	{
	}
}