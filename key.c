#include "key.h"

//void key_init(void)
//{
//	KEY1 = 1;
//	KEY2 = 1;	
//}

uint8 key1_isdown(void)
{
	uint8 down = 0;
	uint8 delay;

	if(KEY1 == KEY_OFF)
		return 0;
	while(delay--);

	if(KEY1 == KEY_ON)
	{
		key_bee();
//		BEE = BEE_ON;
//		key_delaynms(100);
//		BEE = BEE_OFF;
//		key_delaynms(400);
		return 1;
	}
	return 0;	
}

uint8 key2_isdown(void)
{
	uint8 down = 0;
	uint8 delay = 5;

	if(KEY2 == KEY_OFF)
		return 0;
	while(delay--);

	if(KEY2 == KEY_ON)
	{
		key_bee();
//		BEE = BEE_ON;
//		key_delaynms(100);
//		BEE = BEE_OFF;
//		key_delaynms(400);
		return 1;
	}
	return 0;
}

void key_bee()
{
	BEE = BEE_ON;
	key_delaynms(100);
	BEE = BEE_OFF;
	key_delaynms(400);
}

//uint8 key_get(void)
//{
//	uint8 keycode = 0;
//	uint8 s1;
//	uint8 s2;
//	uint8 delay = 5;
//
//	s1 = KEY1;
//	s2 = KEY2;
//	
//	if( s1 == KEY_OFF && s2 == KEY_OFF)
//		return KEYCODE_N;
//	while(delay--);
//		
//	s1 = KEY1;
//	s2 = KEY2;
//	
//	if(s1 == KEY_ON)
//	{
//		BEE = BEE_ON;
//		key_delaynms(100);
//		BEE = BEE_OFF;
//		key_delaynms(400);
//		return KEYCODE_1;
//	}
//	if(s2 == KEY_ON)
//	{
//		BEE = BEE_ON;
//		key_delaynms(100);
//		BEE = BEE_OFF;
//		key_delaynms(400);
//		return KEYCODE_2;
//	}
//	return KEYCODE_N;
//}

//void key_delaynms_bee(uint16 nms)
//{
//	uint8 bee = 0;
//	uint16 i,j;
//	for(i=0;i<nms;i++)
//	{
//		for(j=0;j<60;j++)
//		{
//			bee += 1;
//			bee %= 2;
//			BEE = bee;
//		}
//	}
//}

void key_delaynms(uint8 nms)
{
	uint8 bee = 0;
	uint16 i,j;
	for(i=0;i<nms;i++)
		for(j=0;j<120;j++);
}
