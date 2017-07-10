#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <REG51.h>
sbit BIT3 = P3^0;
sbit BIT2 = P3^1;
sbit BIT1 = P3^2;
sbit BIT0 = P3^7;
#define BIT_EN	0
#define	BIT_OFF	1

#define LEDNUM P1
sbit LEDa = P1^7;
sbit LEDb = P1^5;
sbit LEDc = P1^2;
sbit LEDd = P1^3;
sbit LEDe = P1^4;
sbit LEDf = P1^6;
sbit LEDg = P1^1;
sbit LEDp = P1^0;

sbit KEY1 = P3^4;
sbit KEY2 = P3^5;
#define KEY_ON	0
#define KEY_OFF	1

sbit BEE = P3^3;
#define BEE_ON	0
#define BEE_OFF	1

#endif