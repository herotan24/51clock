#ifndef __KEY_H__
#define __KEY_H__

#include <reg51.h>
#include "mytype.h"
#include "config.h"

void key_init(void);
//uint8 key_get(void);
uint8 key1_isdown(void);
uint8 key2_isdown(void);
void key_bee();

#define KEYCODE_N	0
#define KEYCODE_1	1
#define KEYCODE_2	2

//void key_delaynms_bee(uint16 nms);
void key_delaynms(uint8 nms);

#endif