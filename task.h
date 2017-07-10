#ifndef __TASK_H__
#define __TASK_H__

#include <reg51.h>
#include "mytype.h"
#include "config.h"
#include "clock.h"
#include "display.h"
#include "key.h"

#define SHOWSEC	0
#define	HIDESEC	1
extern uint8 showsec;

#define CLOCK_ZHENG_ON		0
#define CLOCK_ZHENG_OFF	1

extern uint8 clock_start;
extern uint8 clock_end;
extern uint8 clock_zheng_sw;
#define CLOCK_ZHENG_HAS_RING	0
#define CLOCK_ZHENG_NOT_YET		1
static uint8 clock_zheng_on[13] = {CLOCK_ZHENG_NOT_YET, CLOCK_ZHENG_NOT_YET,CLOCK_ZHENG_NOT_YET, CLOCK_ZHENG_NOT_YET,
									CLOCK_ZHENG_NOT_YET, CLOCK_ZHENG_NOT_YET,CLOCK_ZHENG_NOT_YET, CLOCK_ZHENG_NOT_YET,
									CLOCK_ZHENG_NOT_YET, CLOCK_ZHENG_NOT_YET,CLOCK_ZHENG_NOT_YET, CLOCK_ZHENG_NOT_YET,
									CLOCK_ZHENG_NOT_YET};

#define CLOCK_ON	0
#define CLOCK_OFF	1
#define CLOCK_HAS_RING	0
#define CLOCK_NOT_YET	1

extern uint8 clock1_h;
extern uint8 clock1_m;
extern uint8 clock1_sw;
extern uint8 clock1_on;
//
extern uint8 clock2_h;
extern uint8 clock2_m;
extern uint8 clock2_sw;
extern uint8 clock2_on;

void task_showtime(void);
void task_showsec(void);
void task_setall(void);
void task_clock_zheng(void);
//void task_clock1(void);
//void task_clock2(void);
void task_bee(uint8 times, uint16 nms);

void task_clock(uint8 ch, uint8 cm, uint8* on, uint8 sw);

void task_delaynms(uint16 nms);

#endif