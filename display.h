#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <reg51.h>
#include "mytype.h"
#include "config.h"
#include "clock.h"

#define N0	0
#define N1	1
#define N2	2
#define N3	3
#define N4	4
#define N5	5
#define N6	6
#define N7	7
#define N8	8
#define N9	9
#define NA	10
#define NB	11
#define NC	12
#define ND	13
#define NE	14
#define NF	15
#define NG	16
#define NH	17
#define NI	18
#define NJ	19
#define NK	20
#define NL	21
#define NM	22
#define NN	23
#define NO	24
#define NON	30
#define NUM0	0xFC
#define	NUM1	0x24
#define NUM2	0xBA
#define	NUM3	0xAE
#define NUM4	0x66
#define	NUM5	0xCE
#define NUM6	0xDE
#define	NUM7	0xA4
#define NUM8	0xFE
#define	NUM9	0xEE
#define NUMA	0xF6
#define NUMB	0xFE
#define NUMC	0xD8
#define NUMD	0xFC
#define NUME	0xDA
#define NUMF	0xD2
#define NUMG	0xDC
#define NUMH	0x76
#define NUMI	0x50
#define NUMN	0xF4
#define NUMO	0xFC



#define NONTHING		0x00

#define T0_TH0	0xf4	//3ms
#define T0_TL0	0x48	//3ms

extern uint8	str[4];
extern uint8	dot;
extern uint8	sec_change;

//void delay_ms(int ms);
void disnum(uint8 n);
//void dis_init(void);
void dis_isr(void);

//void cursecountplus();
//void cursesetpos(int pos);

#endif