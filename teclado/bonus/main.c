#include "util.h"
#include <stdio.h>

#define SCREEN_SIZE_X 128;
#define SCREEN_SIZE_Y 48;

__code unsigned char cap_fonte[3][40] = {{0x80, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE6, 0xFF, 0xFF, 0xFF, 0xF6, 0xF6, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, // andando1
					0x3F, 0x7F, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0x7F, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00},
				   					{0x80, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE6, 0xFF, 0xFF, 0xFF, 0xF6, 0xF6, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, // andando2
					0x3F, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00},
									{0x80, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE6, 0xFF, 0xFF, 0xFF, 0xF6, 0xF6, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, // pulo
					0xBF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xDF, 0x83, 0x03, 0x03, 0x03, 0x01, 0x00}
};

__code unsigned char obs_fonte[1][8] = {{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}; // obstaculo

struct TCapivara
{
	unsigned char X;
	unsigned char Y;
} capi;

struct TObstaculo
{
	unsigned char X;
	unsigned char Y;
} obs;

void draw(unsigned char X, unsigned char Y, unsigned char i)
{
	int col;
	unsigned char _pag = (Y/8)+2; // pagina
	unsigned char _pos = 8-(((_pag-1)*8)-Y); // posicao de escrita na pagina

	unsigned char posX;

	unsigned char aux;

	if (X < 64) posX = X; else posX = X-64;

	conf_pag(_pag, ESQ);
	conf_Y(posX, ESQ);


	// parte de cima do desenho
	for (col = 0; col < 20; col++)
	{
		esc_glcd((cap_fonte[i][col] << _pos) , DA, ESQ);
		// 0b abcd efgh
		// ob 0000 00ab
		// 0b 0011 1111&
		// 0b 00ab cdef
	}

	if ((Y % 8) != 0)
	{
		conf_pag(++_pag, ESQ);
		conf_Y(posX, ESQ);

		for (col = 0; col < 20; col++)
		{
			aux = (cap_fonte[i][col] >> (8-_pos)) | (cap_fonte[i][col+20] << _pos);
			esc_glcd(aux, DA, ESQ);
		}
	}

	conf_pag(++_pag, ESQ);
	conf_Y(posX, ESQ);

	// parte de baixo do desenho
	for (col = 20; col < 40; col++)
	{			
		
		esc_glcd(cap_fonte[i][col] >> (8-_pos), DA, ESQ);//>>
	}
	
}

void obstaculo()
{
	int col;
	unsigned char _lado;

	if (obs.X < 128 && obs.X > 0)
		obs.X -= 3;
	else
		obs.X = 127;

	_lado = obs.X/64; // 0 - esq; 1 - dir

	conf_pag(7, _lado);
	conf_Y(obs.X, _lado);

	if (obs.X < 72 && obs.X > 56)
	;// TODO - implementar frame do obstaculo no meio da divisao da pagina
	else
	for (col = 0; col < 8; col++)
	{
		esc_glcd(obs_fonte[0][col], DA, _lado);
	}

}

// limpa frame da area de jogo
void limpa_frame()
{
	int i, j;
	for(i = 2; i < 8; i++)
	{
		conf_pag(i, ESQ);
		conf_pag(i, DIR);
		conf_Y(0, ESQ);
		conf_Y(0, DIR);
		for(j = 0; j < 64; j++)
		{
			esc_glcd(0x00, DA, ESQ);
			esc_glcd(0x00, DA, DIR);
		}
	}
}


void ISR_ext1(void) __interrupt 2 // INT1
{
	int i;
	for (i = 0; i < 8; i++){		
		limpa_frame();
		capi.Y -= 2;
		draw(capi.X, capi.Y, 2);
		delay_ms(50);
	}
	for (i = 0; i < 8; i++){
		limpa_frame();
		capi.Y += 2;
		draw(capi.X, capi.Y, 2);
		delay_ms(50);
	}
	
	EX1 = 0; // Desabilita interrupcao ext1
	TR2 = 1; // Habilita o timer2
}

void ISR_tc2(void) __interrupt 5 // Timer2
{
	static unsigned char ni = 0; // Conta o numero de interrupcoes

	TF2 = 0; // Zera overflow do timer2
	if (P0_0) // Se o botao estiver pressionado
	{
		ni++;
		if (ni > 2)
		{
			ni = 0;
			TR2 = 0; // Desabilita o timer2
			IE1 = 0; // Zera flag de interrupcao ext1
			EX1 = 1; // Reabilita interrupcao ext1
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

	capi.X = 6;
	capi.Y = 31;

	printf_fast_f("\x01Jogo da Capivara");

	while(1)
	{
		limpa_frame();
		draw(capi.X, capi.Y, 0);
		delay_ms(100);
		
		limpa_frame();
		draw(capi.X, capi.Y, 1);
		delay_ms(100);

		
		limpa_frame();
		obstaculo();
		delay_ms(100);
	}
}