#include "clock.h"

#define COUNT_1S_FOR_50MS	20
uint8 editing = 0;
uint8 hour = 12;
uint8 minute = 59;
uint8 second = 30;
uint8 count_20ms = 0;
//void time_init(void)
//{
//	ET1 = 0;
//	TF1 = 0;
//	TR1 = 0;
//
//	TMOD |= 0x10;
//	TH1 = T1_TH1;
//	TL1 = T1_TL1;
//
//	PT1 = 1;
//	TR1 = 1;
//	ET1 = 1;	
//}
void time_stop()
{
//	ET1 = 0;
//	TF1 = 0;
	TR1 = 0;
}

void time_go()
{
//	ET1 = 1;
	TR1 = 1;
}

void time_get(uint8* h, uint8* m, uint8* s)
{
	*h = hour;
	*m = minute;
	if(s != 0x00)
		*s = second;
}

void time_set(uint8* h, uint8* m)
{
//	ET1 = 0;
//	TF1 = 0;
	TH1 = T1_TH1;
	TL1 = T1_TL1;
	hour = *h;
	minute = *m;
	second = 0;
	count_20ms = 0;
//	TR1 = 1;
//	ET1 = 1;
}

void time_isr(void) interrupt 3
{
	editing = 1;
	TR1 = 0;
	TH1 = T1_TH1;
	TL1 = T1_TL1;

	count_20ms ++;

	second += count_20ms / COUNT_1S_FOR_50MS;
	count_20ms %= COUNT_1S_FOR_50MS;	

	minute += second / 60;
	second %= 60;

	hour += minute / 60;
	minute %= 60;

	hour %= 24;

	editing = 0;
	_nop_();
	TR1 = 1;
}