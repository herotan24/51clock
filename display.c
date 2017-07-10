#include "display.h"

uint8	str[4] = {0};
uint8	numbit = 0;
uint8	dot = 1;
uint8	dotcount = 0;
uint8	sec_change;
uint8	ledp = 0;
//uint8 cursepos = 6;
//uint8 cursecount = 0;
//uint8 curseonflag = 0;

//#define CURSEMAX	20


//void delay_ms(int ms)
//{
//	int tmp;
//	while(ms--)
//	{
//		tmp = 80;
//		while(tmp--);
//	}
//}

//void dis_init()
//{
//	EA = 0;
//	ET0 = 0;
//	TF0 = 0;
//
//	TMOD |= 0x01;
//	TH0 = T0_TH0;
//	TL0 = T0_TL0;
//
////	str[0] = 0x00;
////	str[1] = 0x00;
////	str[2] = 0x00;
////	str[3] = 0x00;
//
//	numbit = 0;
//
//	LEDNUM = 0xFF;
//	//cursesetpos(5);
//
//
//	TR0 = 1;
//	ET0 = 1;
//	EA = 1;
//}

void disnum(uint8 n)
{
	switch(n)
	{
		case N0:
		case NO:
		case ND:	LEDNUM = NUM0;	break;
		case N1:	LEDNUM = NUM1;	break;
		case N2:	LEDNUM = NUM2;	break;
		case N3:	LEDNUM = NUM3;	break;
		case N4:	LEDNUM = NUM4;	break;
		case N5:	LEDNUM = NUM5;	break;
		case N6:	LEDNUM = NUM6;	break;
		case N7:	LEDNUM = NUM7;	break;
		case N8:
		case NB:	LEDNUM = NUM8;	break;
		case N9:	LEDNUM = NUM9;	break;
		case NA:	LEDNUM = NUMA;	break;
//		case NB:	LEDNUM = NUMB;	break;
		case NC:	LEDNUM = NUMC;	break;
//		case ND:	LEDNUM = NUMD;	break;
		case NE:	LEDNUM = NUME;	break;
		case NF:	LEDNUM = NUMF;	break;
		case NG:	LEDNUM = NUMG;	break;
		case NH:	LEDNUM = NUMH;	break;
		case NI:	LEDNUM = NUMI;	break;
		case NN:	LEDNUM = NUMN;	break;
//		case NO:	LEDNUM = NUMO;	break;
		case NON:	LEDNUM = NONTHING;	break;
		default: break;
	}	
}

void disstr_isr() interrupt 1
{
//	TR0 = 0;
	TH0 = T0_TH0;
	TL0 = T0_TL0;


	switch(numbit)
	{
		case 0:
			BIT3 = BIT_OFF;
			disnum(str[0]);
//			if(	cursepos != 0 || curseonflag)
				BIT0=BIT_EN;
			numbit++;
//			if(curseonflag)
//				cursecountplus();
			break;		
//			if(cursepos != 0)
//			{
//				disnum(str[0]);
//				BIT0=BIT_EN;
//				numbit++;
//				break;
//			}
//			cursecountplus();
//			if(curseonflag)
//			{
//				disnum(str[0]);
//				BIT0=BIT_EN;
//			}
//			numbit++;
//			break;
		case 1:
			BIT0 = BIT_OFF;
			disnum(str[1]);
//			if(	cursepos != 1 || curseonflag)
				BIT1=BIT_EN;
			numbit++;
//			if(curseonflag)
//				cursecountplus();
			break;		
//			if(cursepos != 1)
//			{
//				disnum(str[1]);
//				BIT1=BIT_EN;
//				numbit++;
//				break;
//			}
//			cursecountplus();
//			if(curseonflag)
//			{
//				disnum(str[1]);
//				BIT1=BIT_EN;
//			}
//			numbit++;
//			break;
		case 2:
			BIT1 = BIT_OFF;
			disnum(str[2]);
			if(dot)
				LEDp = ledp;
			if(second == sec_change)
			{
				ledp = ~ledp;
				sec_change = second + 1;
				sec_change %= 60;
			}
//				dotcount ++;
//				dotcount %= 83;
//				if(dotcount == 0)
//				{
//					LEDp = ~LEDp;
//				}
			
//			if(	cursepos != 2 || curseonflag)
				BIT2=BIT_EN;
			numbit++;
//			if(curseonflag)
//				cursecountplus();
			break;		
//			BIT1 = BIT_OFF;
//			if(cursepos != 2)
//			{
//				disnum(str[2]);
//				BIT2=BIT_EN;
//				numbit++;
//				break;
//			}
//			cursecountplus();
//			if(curseonflag)
//			{
//				disnum(str[2]);
//				BIT2=BIT_EN;
//			}
//			numbit++;
//			break;
		case 3:
			BIT2 = BIT_OFF;
			disnum(str[3]);
//			if(	cursepos != 3 || curseonflag)
				BIT3=BIT_EN;
			numbit=0;
//			if(curseonflag)
//				cursecountplus();
			break;		
//			BIT2 = BIT_OFF;
//			if(cursepos != 3)
//			{
//				disnum(str[3]);
//				BIT3=BIT_EN;
//				numbit++;
//				break;
//			}
//			cursecountplus();
//			if(curseonflag)
//			{
//				disnum(str[3]);
//				BIT3=BIT_EN;
//			}
//			numbit = 0;
//			break;
		default:
			//numbit %= 4;
			break;
	}
//	TR0 = 1;
}

//void cursecountplus()
//{
//	cursecount ++;
//	if(cursecount > CURSEMAX)
//	{
//		cursecount = 0;
//		curseonflag++;
//		curseonflag %= 2;
//	}
//}

//void cursesetpos(int pos)
//{
//	if(pos >= 0 && pos <= 3)
//		cursepos = pos;
//	else
//		cursepos = 5;
//}
