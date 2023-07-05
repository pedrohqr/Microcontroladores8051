#include "..\util.h"
#include <stdio.h>

volatile float cont_t = 0;

// Segundos
float le_pulso(void)
{
	unsigned int th_tl;

	cont_t = 0;
	TL1 = 0;
	TH1 = 0;
	IE1 = 0; // Zera flag da INT1
	TR1 = 1; // Liga Timer1 que contar� s� quando o pino INT1=1

	// Enquanto n�o tem borda 1 para 0
	while(IE1 == 0);

	TR1 = 0; // Desliga Timer1
	TF1 = 0; // Zera overflow no Timer1
	th_tl = (unsigned int)TH1*256 + (unsigned int)TL1;
	TL1 = 0;
	TH1 = 0;
	cont_t += (float)th_tl/25000000;
	return cont_t;
}

void int_tcl(void) interrupt 3 // Ocorre a cada 2,62411ms
{
	TF1 = 0;
	cont_t += 0.00262144;
	if(cont_t > 1)
		IE1=1;
}

unsigned int le_hcsr04(void)
{
	// P0_1 -> Trigger; P0_0 -> Echo
	unsigned int lp = 0;
	// Emite um pulso de 10us
	P0_1 = 1;
	delay_us(10);
	P0_1 = 0;

	lp = (unsigned int)(le_pulso()*1000000);

	return lp;
}

void main(void)
{
	unsigned int p = 0;
	Init_Device();
	SFRPAGE = LEGACY_PAGE;

	glcd_init();	

	while(1)
	{
		p = le_hcsr04();
		printf_fast_f("\x01 Distancia:\x02 %5.1f %d", (float)p/58, p);
		delay_ms(500);
	}
}