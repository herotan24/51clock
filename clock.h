#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <reg51.h>
#include "mytype.h"
#include "config.h"
#include "intrins.h" //for _nop_

#define T1_TH1 0x3D
#define T1_TL1 0x04

extern uint8 hour;
extern uint8 minute;
extern uint8 second;
extern uint8 editing;

extern uint8 count_20ms; 
//static uint32 totalsec = 0;

//static uint8 hour_now = hour_start;
//static uint8 minute_now = 0;
//static uint8 second_now = 0;

//void time_init();
void time_stop();
void time_go();
void time_get(uint8* h, uint8* m, uint8* s);
void time_set(uint8* h, uint8* m);
void time_isr();

#endif