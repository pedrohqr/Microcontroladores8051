#include "util.h"

#define BUZZER P2_7

#define LA 3520
#define MI 2637
#define FAsus 2960
#define SOLsus 3323

#define TEMPO_MS 480

void toca() interrupt 0
{
	while(!P0_0)
	{
		BUZZER = !BUZZER;
		delay_us(284);
	}

	IE0 = 1;
}

void main(void)
{
	Init_Device();
	SFRPAGE = LEGACY_PAGE;

	while(1)
	{
	}
}