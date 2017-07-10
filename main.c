#include "config.h"
#include "mytype.h"
#include "clock.h"
#include "display.h"
#include "task.h"
#include "key.h"
#include "clock.h"

void main(void)
{
//	key_init();
//	dis_init();
//	EA = 0;
//	ET0 = 0;
//	TF0 = 0;

//	TMOD |= 0x01;
//	TH0 = T0_TH0;
//	TL0 = T0_TL0;

//	str[0] = 0x00;
//	str[1] = 0x00;
//	str[2] = 0x00;
//	str[3] = 0x00;

//	numbit = 0;

//	LEDNUM = 0xFF;
	//cursesetpos(5);


//	TR0 = 1;
	ET0 = 1;
	
//	time_init();
//	ET1 = 0;
//	TF1 = 0;
//	TR1 = 0;

//	TMOD |= 0x10;
	TMOD = 0x11;
	TH1 = T1_TH1;
	TL1 = T1_TL1;

	PT1 = 1;
//	TR1 = 1;
	TCON = 0x50;
//	ET1 = 1;

	IE = 0x8A ;

	sec_change = second;
	while(1)
	{
		task_setall();
		task_showsec();
		task_showtime();
		task_clock_zheng();
		task_clock(clock1_h, clock1_m, &clock1_on, clock1_sw);
		task_clock(clock2_h, clock2_m, &clock2_on, clock2_sw);
	}
	//return;
}