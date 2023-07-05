#include "..\util.h"
#include <stdio.h>

unsigned char botao;

void putchar(char c)
{
	__bit lado;

	if (c < 9)
	{
		pag_esc = c-1;
		conf_pag(pag_esc, ESQ);
		conf_pag(pag_esc, DIR);
		conf_Y(0, ESQ);
		conf_Y(0, DIR);
		carac_esc = 0;
	}
	else
	{
		if (carac_esc < 8) lado = ESQ; else lado = DIR;

		// escreve na coluna

		esc_glcd(fonte[c-32][0], DA, lado);
		esc_glcd(fonte[c-32][1], DA, lado);
		esc_glcd(fonte[c-32][2], DA, lado);
		esc_glcd(fonte[c-32][3], DA, lado);
		esc_glcd(fonte[c-32][4], DA, lado);
		esc_glcd(0x00, DA, lado);
		esc_glcd(0x00, DA, lado);
		esc_glcd(0x00, DA, lado);
		carac_esc++;

		if (carac_esc >= 16)
		{
			carac_esc = 0;
			conf_pag(++pag_esc, ESQ);
			conf_pag(pag_esc, DIR);
			conf_Y(0, ESQ);
			conf_Y(0, DIR);
		}
	}
}

// Le a porta P1 e retorna o botao pressionado
unsigned char le_tec(void)
{

	// se algum botao da P1 for pressionado
	if (!P1_0) return 0;
	else if (!P1_1) return 1;
	else if (!P1_2) return 2;
	else if (!P1_3) return 3;
	else if (!P1_4) return 4;
	else if (!P1_5) return 5;
	else if (!P1_6) return 6;
	else if (!P1_7) return 7;
	else return 127; // Valor de protecao, caso se nao for pressionado nenhuma tecla
	
	/*
	TF2 = 0; // zera overflow
	TR2 = 1; // habilita timer2
	while (TF2 == 0); // 20ms
	TR2 = 0; // desabilita timer2
	*/
}

void ISR_tc2(void) __interrupt 5 // Timer2
{
	botao = le_tec();

	TF2 = 0;
	IE = 0;
}

void main(void)
{
	carac_esc = 0;
	pag_esc = 0;
	botao = 127;
	
	Init_Device();
	SFRPAGE = LEGACY_PAGE;


	glcd_init();
	
	limpa_glcd(ESQ);
	limpa_glcd(DIR);

	conf_pag(0x00, ESQ); // pagina 0
	conf_Y(0x00, ESQ);   // Y = 0

	//TR2 = 1;

	while(1)
	{
		printf_fast_f("\x01var=%d", botao);
	}
}