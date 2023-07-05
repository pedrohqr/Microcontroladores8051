#include "..\util.h"
#include <stdio.h>

const char fonte[96][5] = {
{0x00, 0x00, 0x00, 0x00, 0x00},// (space)
{0x00, 0x00, 0x5F, 0x00, 0x00},// !
{0x00, 0x07, 0x00, 0x07, 0x00},// "
{0x14, 0x7F, 0x14, 0x7F, 0x14},// #
{0x24, 0x2A, 0x7F, 0x2A, 0x12},// $
{0x23, 0x13, 0x08, 0x64, 0x62},// %
{0x36, 0x49, 0x55, 0x22, 0x50},// &
{0x00, 0x05, 0x03, 0x00, 0x00},// '
{0x00, 0x1C, 0x22, 0x41, 0x00},// (
{0x00, 0x41, 0x22, 0x1C, 0x00},// )
{0x08, 0x2A, 0x1C, 0x2A, 0x08},// *
{0x08, 0x08, 0x3E, 0x08, 0x08},// +
{0x00, 0x50, 0x30, 0x00, 0x00},// ,
{0x08, 0x08, 0x08, 0x08, 0x08},// -
{0x00, 0x30, 0x30, 0x00, 0x00},// .
{0x20, 0x10, 0x08, 0x04, 0x02},// /
{0x3E, 0x51, 0x49, 0x45, 0x3E},// 0
{0x00, 0x42, 0x7F, 0x40, 0x00},// 1
{0x42, 0x61, 0x51, 0x49, 0x46},// 2
{0x21, 0x41, 0x45, 0x4B, 0x31},// 3
{0x18, 0x14, 0x12, 0x7F, 0x10},// 4
{0x27, 0x45, 0x45, 0x45, 0x39},// 5
{0x3C, 0x4A, 0x49, 0x49, 0x30},// 6
{0x01, 0x71, 0x09, 0x05, 0x03},// 7
{0x36, 0x49, 0x49, 0x49, 0x36},// 8
{0x06, 0x49, 0x49, 0x29, 0x1E},// 9
{0x00, 0x36, 0x36, 0x00, 0x00},// :
{0x00, 0x56, 0x36, 0x00, 0x00},// ;
{0x00, 0x08, 0x14, 0x22, 0x41},// <
{0x14, 0x14, 0x14, 0x14, 0x14},// =
{0x41, 0x22, 0x14, 0x08, 0x00},// >
{0x02, 0x01, 0x51, 0x09, 0x06},// ?
{0x32, 0x49, 0x79, 0x41, 0x3E},// @
{0x7E, 0x11, 0x11, 0x11, 0x7E},// A
{0x7F, 0x49, 0x49, 0x49, 0x36},// B
{0x3E, 0x41, 0x41, 0x41, 0x22},// C
{0x7F, 0x41, 0x41, 0x22, 0x1C},// D
{0x7F, 0x49, 0x49, 0x49, 0x41},// E
{0x7F, 0x09, 0x09, 0x01, 0x01},// F
{0x3E, 0x41, 0x41, 0x51, 0x32},// G
{0x7F, 0x08, 0x08, 0x08, 0x7F},// H
{0x00, 0x41, 0x7F, 0x41, 0x00},// I
{0x20, 0x40, 0x41, 0x3F, 0x01},// J
{0x7F, 0x08, 0x14, 0x22, 0x41},// K
{0x7F, 0x40, 0x40, 0x40, 0x40},// L
{0x7F, 0x02, 0x04, 0x02, 0x7F},// M
{0x7F, 0x04, 0x08, 0x10, 0x7F},// N
{0x3E, 0x41, 0x41, 0x41, 0x3E},// O
{0x7F, 0x09, 0x09, 0x09, 0x06},// P
{0x3E, 0x41, 0x51, 0x21, 0x5E},// Q
{0x7F, 0x09, 0x19, 0x29, 0x46},// R
{0x46, 0x49, 0x49, 0x49, 0x31},// S
{0x01, 0x01, 0x7F, 0x01, 0x01},// T
{0x3F, 0x40, 0x40, 0x40, 0x3F},// U
{0x1F, 0x20, 0x40, 0x20, 0x1F},// V
{0x7F, 0x20, 0x18, 0x20, 0x7F},// W
{0x63, 0x14, 0x08, 0x14, 0x63},// X
{0x03, 0x04, 0x78, 0x04, 0x03},// Y
{0x61, 0x51, 0x49, 0x45, 0x43},// Z
{0x00, 0x00, 0x7F, 0x41, 0x41},// [
{0x02, 0x04, 0x08, 0x10, 0x20},// "\"
{0x41, 0x41, 0x7F, 0x00, 0x00},// ]
{0x04, 0x02, 0x01, 0x02, 0x04},// ^
{0x40, 0x40, 0x40, 0x40, 0x40},// _
{0x00, 0x01, 0x02, 0x04, 0x00},// `
{0x20, 0x54, 0x54, 0x54, 0x78},// a
{0x7F, 0x48, 0x44, 0x44, 0x38},// b
{0x38, 0x44, 0x44, 0x44, 0x20},// c
{0x38, 0x44, 0x44, 0x48, 0x7F},// d
{0x38, 0x54, 0x54, 0x54, 0x18},// e
{0x08, 0x7E, 0x09, 0x01, 0x02},// f
{0x08, 0x14, 0x54, 0x54, 0x3C},// g
{0x7F, 0x08, 0x04, 0x04, 0x78},// h
{0x00, 0x44, 0x7D, 0x40, 0x00},// i
{0x20, 0x40, 0x44, 0x3D, 0x00},// j
{0x00, 0x7F, 0x10, 0x28, 0x44},// k
{0x00, 0x41, 0x7F, 0x40, 0x00},// l
{0x7C, 0x04, 0x18, 0x04, 0x78},// m
{0x7C, 0x08, 0x04, 0x04, 0x78},// n
{0x38, 0x44, 0x44, 0x44, 0x38},// o
{0x7C, 0x14, 0x14, 0x14, 0x08},// p
{0x08, 0x14, 0x14, 0x18, 0x7C},// q
{0x7C, 0x08, 0x04, 0x04, 0x08},// r
{0x48, 0x54, 0x54, 0x54, 0x20},// s
{0x04, 0x3F, 0x44, 0x40, 0x20},// t
{0x3C, 0x40, 0x40, 0x20, 0x7C},// u
{0x1C, 0x20, 0x40, 0x20, 0x1C},// v
{0x3C, 0x40, 0x30, 0x40, 0x3C},// w
{0x44, 0x28, 0x10, 0x28, 0x44},// x
{0x0C, 0x50, 0x50, 0x50, 0x3C},// y
{0x44, 0x64, 0x54, 0x4C, 0x44},// z
{0x00, 0x08, 0x36, 0x41, 0x00},// {
{0x00, 0x00, 0x7F, 0x00, 0x00},// |
{0x00, 0x41, 0x36, 0x08, 0x00},// }
{0x08, 0x08, 0x2A, 0x1C, 0x08},// ->
{0x08, 0x1C, 0x2A, 0x08, 0x08} // <-
};

// Marca o numero de caracteres escritos na linha atual
static short carac_esc;
// Numero da pagina atual onde está ocorrendo a escrita
static short pag_esc;

void delay_160ns()
{
	NOP();
	NOP();
	NOP();
	NOP();
}

void delay_320ns()
{
	delay_160ns();
	delay_160ns();
}

void delay_480ns()
{
	delay_320ns();
	delay_160ns();
}



unsigned char le_glcd(__bit cd, __bit cs)
{
	unsigned char byte;
	RW = 1;
	CS1 = cs;
	CS2 = !cs;
	RS = cd;

	delay_160ns();

	E = 1;

	delay_320ns();

	// Le o byte
	SFRPAGE = CONFIG_PAGE;
	byte = DB;
	SFRPAGE = LEGACY_PAGE;

	delay_160ns();
	E = 0;
	delay_480ns();

	return byte;

}

void esc_glcd(unsigned char byte, __bit cd, __bit cs)
{
	// Enquanto estiver ocupado, espera desocupar para escrever
//	while(le_glcd(cd, cs) >> 7)
	while(le_glcd(CD, cs) & 0x80);
		;

	RW = 0;
	CS1 = cs;
	CS2 = !cs;
	RS = cd;

	SFRPAGE = CONFIG_PAGE;
	DB = byte;
	SFRPAGE = LEGACY_PAGE;
	
	delay_160ns();
	E = 1;
	delay_480ns();
	E = 0;

	SFRPAGE = CONFIG_PAGE;
	DB = 0xFF;
	SFRPAGE = LEGACY_PAGE;
	delay_480ns();
}

void glcd_init()
{
	E = 0;
	RST = 1;
	CS1 = 1;
	CS2 = 1;
	SFRPAGE = CONFIG_PAGE;
	DB = 0xFF;
	SFRPAGE = LEGACY_PAGE;

	// Aguarda o display sair do status de reset
	while((le_glcd(CD, ESQ) & 0x10) && (le_glcd(CD, DIR) & 0x10))
		;

	// Liga o display
	esc_glcd(0x3F, CD, ESQ);
	esc_glcd(0x3F, CD, DIR);

	// PROBLEMA AQUI
	// set Y
	esc_glcd(0x40, CD, ESQ);
	esc_glcd(0x40, CD, DIR);
	// set X
	esc_glcd(0xB8, CD, ESQ);
	esc_glcd(0xB8, CD, DIR);
	// set Z
	esc_glcd(0xC0, CD, ESQ);
	esc_glcd(0xC0, CD, DIR);

}

void conf_Y(unsigned char y, __bit cs)
{
	y &= 0x3F; // protecao para valores > 63
	esc_glcd(0x40|y, CD, cs);
}

void conf_pag(unsigned char pag, __bit cs)
{
	pag &= 0x07;// protecao para valores > 7
	esc_glcd(0xB8|pag, CD, cs);
}

void limpa_glcd(__bit cs)
{
	int i, j;
	for(i = 0; i < 8; i++)
	{
		conf_pag(i, cs);
		conf_Y(0, cs);
		for(j = 0; j < 64; j++)
			esc_glcd(0x00, DA, cs);
	}
}

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


void main(void)
{	
	carac_esc = 0;
	pag_esc = 0;
	
	Init_Device();
	SFRPAGE = LEGACY_PAGE;


	glcd_init();
	
	limpa_glcd(ESQ);
	limpa_glcd(DIR);

	conf_pag(0x00, ESQ); // pagina 0
	conf_Y(0x00, ESQ);   // Y = 0

	printf_fast_f("\x01#fechadoscomVP");

	while(1);

}