
#include<REG2051.H>

code senen_seg[10]={0x81,0xe7,0x92,0xa2,0xe4,0xa8,0x88,0xe3,0x80,0xa0};	        //P1.7(冒号)口高电平

bit key1_enter=0,key2_enter=0,key3_enter=0,countdown_mark=0,stopwatch_mark=0,count_mark=0,bell_mark=0;	  //状态标志
unsigned char program=0,program_variable=0,count_bit=0,count=0;
unsigned char hour=10,minute=10,second=0;									    //时间变量
unsigned char delayed_hour=22,delayed_minute=10,delayed_second=0;				//定时变量					  
unsigned char count_hour=0,count_minute=0,count_second=0;					    //计时计数变量
unsigned char count_time=0,count_count=0;																		 		  

void delay(unsigned int t)										//延时子程序
{ 
   unsigned int i,j;
   for(i=0;i<t;i++)
   for(j=0;j<10;j++)
   ;
}   

void time0_init(void){										   //定时计数0器初始化
EA=0;														  
TR0=0;
TMOD=0x01;
TH0=0xec;
TL0=0x73;
ET0=1;
TR0=1;
EA=1;
}
																			    	   
static void timer0_isr(void) interrupt TF0_VECTOR using 1	   //定时计数0器中断函数
{
TR0=0;
TH0=0xec;
TL0=0x73;
TR0=1;
count_time++;												   //时钟计时程序
if(count_time>=199){
  count_time=0;
  second++;
  if(second>=60){
    second=0;
    minute++;
    if(minute>=60){
      minute=0;
      hour++;
      if(hour>=24)hour=0;
    }
  }
}
if(delayed_hour==hour && delayed_minute==minute && second<4) P3_7=0;
else P3_7=1;
if(countdown_mark==1){										   //倒计时程序
  count_count++;
    if(count_count>=199 && (count_second!=0|count_minute!=0|count_hour!=0)){
	count_count=0;
	count_second--;
	if(count_second>=60){
	  count_second=59;
	  count_minute--;
	  if(count_minute>=60){
	    count_minute=59;
	    count_hour--;
	    if(count_hour>=100) count_hour=99;
	  }
	}
    }
if(count_second==0&&count_minute==0&&count_hour==0&&count_count<=12000) P3_7=0;
else P3_7=1;
if(count_count>=15000) count_count=14000; 
}
if(stopwatch_mark==1){										   //秒表程序
  count_count++;
    if(count_count>=2){
	count_count=0;
	count_second++;
	if(count_second>=100){
	  count_second=0;
	  count_minute++;
	  if(count_minute>=60){
	    count_minute=0;
	    count_hour++;
	    if(count_hour>=60) count_hour=0;
	  }
	}
    }
}
}

unsigned char show_key (void){
unsigned char x=0,y=0;
switch (program){
case 0: P1&=senen_seg[second%10];	            	    //时钟秒的个位
        break;
case 1: if(count_time>=90) P1&=senen_seg[second%10];  //校正秒的个位
        break;
case 2: if(delayed_hour==24) P1=0xfe;					//闹钟秒的个位
        else P1&=senen_seg[delayed_second%10];		  	    
		break;
case 3: if(count_bit>=0) P1&=senen_seg[count_second%10];//倒计时秒的个位
        else P1=0xff;
        break;
case 4: P1&=senen_seg[count_second%10];				    //秒表秒的个位
		break;
case 5: P1&=senen_seg[count_second%10];				    //计数器个位
		break;
}
  P3_3=0;
  delay(10);
  if(P3_5==0){					//功能键1识别
    key1_enter=1;
	if(count<=254)count++;
	}
  if(P3_4==0) key2_enter=1;		//功能键2识别
  if(P3_2==0) key3_enter=1;     //功能键3识别   
  P3_3=1;
  P1|=0xff;

switch (program){  
case 0: P1&=senen_seg[second/10];	            	    //时钟秒的十位
		break;
case 1: if(count_time>=90) P1&=senen_seg[second/10];  //校正秒的十位
	    break;
case 2: if(delayed_hour==24) P1=0xfe;   			    //闹钟秒的十位
        else P1&=senen_seg[delayed_second/10]; 
		break;
case 3: if(count_bit>=1) P1&=senen_seg[count_second/10];//倒计时秒的十位
		else P1=0xff;
       	break;
case 4: P1&=senen_seg[count_second/10];				    //秒表秒的十位
		break;
case 5: P1&=senen_seg[count_second/10];				    //计数器十位
		break;
}						    
  P3_1=0;
  delay(10);
  P3_1=1;
  P1|=0xff;

switch (program){   
case 0: P1&=senen_seg[minute%10];	            	    //时钟分的个位
		break;
case 1: if(count_time>=90) P1&=senen_seg[minute%10];  //校正分的个位
		break;
case 2: if(delayed_hour==24) P1=0xfe;					//闹钟分的个位
        else P1&=senen_seg[delayed_minute%10];			    
		break;
case 3: if(count_bit>=2) P1&=senen_seg[count_minute%10];//倒计时分的个位
		else P1=0xff;
		break;
case 4: P1&=senen_seg[count_minute%10];				    //秒表分的个位
		break;
case 5: P1&=senen_seg[count_minute%10];				    //计数器百位
		break;
}
  P3_2=0;
  delay(10);
  P3_2=1;
  P1|=0xff;

switch (program){
case 0: P1&=senen_seg[minute/10];	            	    //时钟秒的个位
		break;
case 1: if(count_time>=90) P1&=senen_seg[minute/10];  //校正秒的个位
	    break;
case 2: if(delayed_hour==24) P1=0xfe;					//闹钟秒的个位
        else P1&=senen_seg[delayed_minute/10];			    
		break;
case 3: if(count_bit>=3) P1&=senen_seg[count_minute/10];//倒计时秒的个位
		else P1=0xff;
		break;									    
case 4: P1&=senen_seg[count_minute/10];				    //秒表秒的个位
		break;
case 5: P1&=senen_seg[count_minute/10];				    //计数器千位
		break;
}
  P3_5=0;
  delay(10);
  P3_5=1;
  P1|=0xff;

switch (program){
case 0: P1&=senen_seg[hour%10];	            	      //时钟时的个位
		break;
case 1: if(count_time>=90) P1&=senen_seg[hour%10];  //校正时的个位
		break;
case 2: if(delayed_hour==24) P1=0xfe;				  //闹钟时的个位
        else P1&=senen_seg[delayed_hour%10];			      
		break;
case 3: if(count_bit>=4) P1&=senen_seg[count_hour%10];//倒计时时的个位
		else P1=0xff;
		break;
case 4: P1&=senen_seg[count_hour%10];				  //秒表时的个位
		break;
case 5: P1&=senen_seg[count_hour%10];				  //计数器万位
		break;
}
  P3_0=0;
  delay(10);
  if(P3_4==1 && key2_enter==1){
  x=3;                                         //确认功能键2识别，返回3
  key2_enter=0;
  }
  P3_0=1;
  P1|=0xff;

switch (program){ 
case 0: P1&=senen_seg[hour/10];	            	      //时钟时的个位
		break;
case 1: if(count_time>=90) P1&=senen_seg[hour/10];  //校正时的个位
		break;
case 2: if(delayed_hour==24) P1=0xfe;				  //闹钟时的个位
        else P1&=senen_seg[delayed_hour/10];			      
		break;
case 3: if(count_bit>=5)P1&=senen_seg[count_hour/10];  //倒计时时的个位
		else P1=0xff;
		break;
case 4: P1&=senen_seg[count_hour/10];				  //秒表时的个位
		break;
case 5: P1&=senen_seg[count_hour/10];				  //计数器万位
		break;
}
  P3_4=0;
  delay(10);
  if(P3_5==1 && key1_enter==1){		//确认功能键1识别，执行退出或进入下一个功能
    if(count>=127) x=1;		        //确认功能键1为长按，返回1
	else x=2;					    //确认功能键1为短按，返回2
    key1_enter=0;
	count=0;
    }
  if(P3_2==1 && key3_enter==1){
  x=4;                              //确认功能键3识别，返回4
  key3_enter=0;
  }   
  P3_4=1;
  P1|=0xff;
if(program<=1 && count_time>=100) P1&=0xff;		//校时和显示功能时钟时冒号闪烁
if(program<=1 && count_time<=100) P1&=0x7f;
if(program==2) P1&=0x7f;		//设置闹钟功能时冒号长亮
if(program==3) P1&=0xff;		//设置倒计时功能时冒号长灭
if(program==4) P1&=0x7f;		//设置秒表功能时冒号长亮
if(program==5) P1&=0xff;		//设置计数时冒号长灭
y=x;
x=0;
return y;
}

void main(){					//主程序
P1=0xff;																    	       
P3=0xff;
time0_init();
while(1){
switch(program){
case 0: while(program==0){						   //时钟菜单
        switch(show_key()){
        case 0: break;
		case 1:	program=0;
		        break;
		case 2:	program=1;
		        break;
		}
		}
        break;									   //校时菜单
case 1: while(program==1){
		switch(show_key()){
        case 0: break;
		case 1:	program=0;
		        break;
		case 2:	program=2;
				break;
		case 3: hour++;
		        if(hour>=24)hour=0;
				break;
		case 4: minute++;
		        if(minute>=60)minute=0;
				break;
		}
		}
        break;
case 2: while(program==2){						    //闹钟菜单
        switch(show_key()){
        case 0: break;
		case 1:	program=0;
		        break;
		case 2:	program=3;
				break;
		case 3:	delayed_hour++;
				if(delayed_hour>=25)delayed_hour=0;
				break;
		case 4:	delayed_minute++;
		        if(delayed_minute>=60)delayed_minute=0;
				break;
		}
		}
        break;
case 3: while(program==3){									 //倒计时菜单
        switch(show_key()){
        case 0: break;
		case 1:	program=0;
		        break;
		case 2:	program=4;
				break;
		case 3:	count_bit++;
		        if(count_bit>=7)count_bit=0;
				break;
		case 4:	switch(count_bit){
		          case 0: count_second+=1;
						  break;
			  	  case 1: count_second+=10;
						  break;
				  case 2: count_minute+=1;
						  break;
				  case 3: count_minute+=10;
						  break;
				  case 4: count_hour+=1;
						  break;
				  case 5: count_hour+=10;
						  break;
				  case 6: break;
		          }
				if(count_hour>=100) count_hour-=100;
	 	        if(count_minute>=60) count_minute-=60;
		        if(count_second>=60) count_second-=60;
	            break;
		}
		if(count_bit==6) countdown_mark=1;
		else countdown_mark=0;
		}
        break;
case 4: count_hour=0;								//秒表菜单
        count_minute=0;
		count_second=0;
        while(program==4){
        switch(show_key()){
        case 0: break;
		case 1:	program=0;
		        break;
		case 2:	program=5;
				break;
		case 3:	stopwatch_mark=~stopwatch_mark;
				break;
		case 4:	if(stopwatch_mark==0){				 
		        count_hour=0;								
                count_minute=0;
		        count_second=0;
				}
				break;
		}
		}
        break;										 //计数器菜单
case 5: count_hour=0;
        count_minute=0;
		count_second=0;
        while(program==5){
        switch(show_key()){
        case 0: break;
		case 1:	program=0;
		        break;
		case 2:	program=0;
				break;
		case 3:	count_second++;
		        if(count_second>=100){
				  count_second=0;
				  count_minute++;
				  if(count_minute>=100){
				    count_minute=0;
				    count_hour++;
				    if(count_hour>=100)count_hour=0;
				  }
				  }  
				break;
		case 4:	count_hour=0;
                count_minute=0;
		        count_second=0;
				break;
		}
		if(P3_7==0){
		while(P3_7==0) show_key();
		    count_second++;
		      if(count_second>=100){
			    count_second=0;
				count_minute++;
				if(count_minute>=100){
				  count_minute=0;
				  count_hour++;
				  if(count_hour>=100)count_hour=0;
				  }
				}  
		}
		}
        break;
}
if(program!=3) countdown_mark=0;
if(program!=4) stopwatch_mark=0;
}		
}