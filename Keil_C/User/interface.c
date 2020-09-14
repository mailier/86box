//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: interface.c
//	作者		: 
//	模块功能	: 界面交互
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#include "interface.h"
#include "SC_it.h"
#include "BM8563.h"




unsigned char code LCD_number_SEG[][7]=
{
	//对应界面数字位数；1--3位温度位，4--7位时间位
	{0},						//num0
	{22,21,21,22,23,23,22},		//num1	
	{19,18,18,19,20,20,19},		//num2
	{16,15,15,16,17,17,16},		//num3
	{11,10,10,11,14,14,11}, 	//num4
	{8,7,7,8,9,9,8},			//num5
	{5,4,4,5,6,6,5},			//num6
	{2,1,1,2,3,3,2},			//num7
};
unsigned char code LCD_number_COM[][7]=
{
	//对应数字0,1,2,3,4,5,6,7,8,9
	{0x80,0x40,0x20,0x20,0x20,0x40,0x00},	//0
	{0x00,0x40,0x20,0x00,0x00,0x00,0x00},	//1
	{0x80,0x40,0x00,0x20,0x20,0x00,0x40},	//2
	{0x80,0x40,0x20,0x20,0x00,0x00,0x40},	//3
	{0x00,0x40,0x20,0x00,0x00,0x40,0x40},	//4
	{0x80,0x00,0x20,0x20,0x00,0x40,0x40},	//5
	{0x80,0x00,0x20,0x20,0x20,0x40,0x40},	//6
	{0x80,0x40,0x20,0x00,0x00,0x00,0x00},	//7
	{0x80,0x40,0x20,0x20,0x20,0x40,0x40},	//8		//用来清屏
	{0x80,0x40,0x20,0x20,0x00,0x40,0x40},	//9
};
unsigned char code LCD_bits_SEG[]=
{
	//对应界面数标A,1,2,3,4,5,6,copy,paste
	23,21,18,15,10,7,1,24,25
};
unsigned char code LCD_week_SEG[]=
{
	//对应界面星期日，一，二，三，四，五，六
	14,23,21,20,18,17,15
};

/**************************************************
*函数名称：void LCD_cleanALL(void)
*函数功能：LCD清除
*入口参数：uint8_t bits
*出口参数：void
**************************************************/

void LCD_cleanALL(void)
{
	LCD_clean(TEMPER);
	LCD_clean(TIMER);
	LCD_clean(HOTCOOL);
	LCD_clean(WIND);
	LCD_clean(STATE);
	LCD_clean(MODE);
	LCD_clean(GROUP);
	DDIC_Control(DDIC_SEG6,DDIC_COM4,DDIC_Control_OFF);			//S23":"
	DDIC_Control(DDIC_SEG20,DDIC_COM4,DDIC_Control_OFF);		//风挡
	
}

/**************************************************
*函数名称：void LCD_clean(void)
*函数功能：LCD清除
*入口参数：uint8_t bits
*出口参数：void
**************************************************/

void LCD_clean(uint8_t bits)
{
	uint8_t select;
	if(bits == TEMPER)
	{
		
		DDIC_Control(DDIC_SEG3,DDIC_COM7,DDIC_Control_OFF);			//S22"F"
		DDIC_Control(DDIC_SEG1,DDIC_COM7,DDIC_Control_OFF);			//S21"C"
		DDIC_Control(DDIC_SEG17,DDIC_COM4,DDIC_Control_OFF);		//S20"."
		
		for(select=0;select<7;select++)
		{	
			DDIC_Control(DDIC_SEG24,DDIC_COM6,DDIC_Control_OFF);			//S19"1"				//温度
			DDIC_Control(LCD_number_SEG[1][select],LCD_number_COM[8][select],DDIC_Control_OFF);
			DDIC_Control(LCD_number_SEG[2][select],LCD_number_COM[8][select],DDIC_Control_OFF);
			DDIC_Control(LCD_number_SEG[3][select],LCD_number_COM[8][select],DDIC_Control_OFF);
			
		}
		
	}	
	else if(bits == TIMER)
	{
		
//			DDIC_Control(DDIC_SEG6,DDIC_COM4,DDIC_Control_OFF);										//S23":"
		for(select=0;select<7;select++)
		{	
			DDIC_Control(LCD_number_SEG[4][select],LCD_number_COM[8][select],DDIC_Control_OFF);		//时钟
			DDIC_Control(LCD_number_SEG[5][select],LCD_number_COM[8][select],DDIC_Control_OFF);		
			DDIC_Control(LCD_number_SEG[6][select],LCD_number_COM[8][select],DDIC_Control_OFF);		//分钟
			DDIC_Control(LCD_number_SEG[7][select],LCD_number_COM[8][select],DDIC_Control_OFF);		
		
			DDIC_Control(LCD_week_SEG[select],DDIC_COM7,DDIC_Control_OFF);							//星期
		}	
		
	}
	else if(bits == HOTCOOL)
	{
		DDIC_Control(DDIC_SEG24,DDIC_COM7,DDIC_Control_OFF);
		DDIC_Control(DDIC_SEG27,DDIC_COM7,DDIC_Control_OFF);
		DDIC_Control(DDIC_SEG27,DDIC_COM6,DDIC_Control_OFF);
	}	
	else if(bits == WIND)
	{
		LCD_wind(0);
//		DDIC_Control(DDIC_SEG20,DDIC_COM4,DDIC_Control_OFF);		//风挡
		
	}
	else if(bits == STATE)
	{
		DDIC_Control(DDIC_SEG27,DDIC_COM5,DDIC_Control_OFF);		//S11"ST"
		DDIC_Control(DDIC_SEG24,DDIC_COM5,DDIC_Control_OFF);		//S12"RT"
		DDIC_Control(DDIC_SEG22,DDIC_COM4,DDIC_Control_OFF);		//S13"RH"
	}	
	else if(bits == MODE)
	{
		DDIC_Control(DDIC_SEG24,DDIC_COM7,DDIC_Control_OFF);		//S8"日"
		DDIC_Control(DDIC_SEG25,DDIC_COM7,DDIC_Control_OFF);		//S9"雪"
		DDIC_Control(DDIC_SEG25,DDIC_COM6,DDIC_Control_OFF);		//S10"叶"
	}	
	else if(bits == GROUP)
	{
		for(select=0;select<9;select++)
		{	
			DDIC_Control(LCD_bits_SEG[select],DDIC_COM4,DDIC_Control_OFF);
		}
	}	
	
}

/**************************************************
*函数名称：void LCD_group(void)
*函数功能：LCD显示数标
*入口参数：uint8_t bits
*出口参数：void
**************************************************/

void LCD_group(uint8_t bits)
{

	DDIC_Control(LCD_bits_SEG[bits],DDIC_COM4,DDIC_Control_ON);

}	

/**************************************************
*函数名称：void LCD_week(void)
*函数功能：LCD显示星期
*入口参数：uint8_t week
*出口参数：void
**************************************************/

void LCD_week(uint8_t week,bit blink)
{

	DDIC_Control(LCD_week_SEG[week],DDIC_COM7,blink);

}

/**************************************************
*函数名称：void LCD_mode(uint8_t mode)
*函数功能：LCD显示设备模式
*入口参数：uint8_t mode
*出口参数：void
**************************************************/

void LCD_mode(uint8_t mode)
{
	static bit DDIC_Control1,
				DDIC_Control2,
				DDIC_Control3;

	switch(mode)
	{
		case 1: 		
			DDIC_Control1 = 1;
			DDIC_Control2 = 0;
			DDIC_Control3 = 0;
		break;
		case 2: 		
			DDIC_Control1 = 0;
			DDIC_Control2 = 1;
			DDIC_Control3 = 0;
		break;
		case 3: 		
			DDIC_Control1 = 0;
			DDIC_Control2 = 0;
			DDIC_Control3 = 1;
		break;
		default:
			break;
	}

	 DDIC_Control(DDIC_SEG24,DDIC_COM7,DDIC_Control1);		//S8"日"
	 DDIC_Control(DDIC_SEG25,DDIC_COM7,DDIC_Control2);		//S9"雪"
	 DDIC_Control(DDIC_SEG25,DDIC_COM6,DDIC_Control3);		//S10"叶"
}

/**************************************************
*函数名称：void LCD_state(uint8_t state)
*函数功能：LCD显示状态模式
*入口参数：uint8_t state
*出口参数：void
**************************************************/

void LCD_state(uint8_t state)
{
	static bit DDIC_Control1,
				DDIC_Control2,
				DDIC_Control3;
	
	switch(state)
	{
		case 1: 			
			DDIC_Control1 = 1;
			DDIC_Control2 = 0;
			DDIC_Control3 = 0;
		break;
		
		case 2: 			
			DDIC_Control1 = 0;
			DDIC_Control2 = 1;
			DDIC_Control3 = 0;
		break;
		
		case 3: 			
			DDIC_Control1 = 0;
			DDIC_Control2 = 0;
			DDIC_Control3 = 1;
		break;
		
		default:
			break;
	}
	DDIC_Control(DDIC_SEG25,DDIC_COM5,DDIC_Control1);		//S11"ST"
	DDIC_Control(DDIC_SEG24,DDIC_COM5,DDIC_Control2);		//S12"RT"
	DDIC_Control(DDIC_SEG22,DDIC_COM4,DDIC_Control3);		//S13"RH"
	

}

/**************************************************
*函数名称：void LCD_wind(uint8_t DDIC_windControl)
*函数功能：LCD显示风挡
*入口参数：uint8_t DDIC_windControl
*出口参数：void
**************************************************/

void LCD_wind(uint8_t DDIC_windControl)
{
	static bit DDIC_Control1,
				DDIC_Control2,
				DDIC_Control3,
				DDIC_Control4;


	switch(DDIC_windControl)
	{
		case 0: 
			DDIC_Control1 = 0;
			DDIC_Control2 = 0;
			DDIC_Control3 = 0;
			DDIC_Control4 = 0;	
		break;
				
		case 1: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 0;
			DDIC_Control3 = 0;
			DDIC_Control4 = 0;	
		break;
		
		case 2: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 1;
			DDIC_Control3 = 0;
			DDIC_Control4 = 0;		
		break;
		
		case 3: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 1;
			DDIC_Control3 = 1;
			DDIC_Control4 = 0;		
		break;
		
		case 4: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 1;
			DDIC_Control3 = 1;
			DDIC_Control4 = 1;		
		break;
		
		default:
			break;
	}
	DDIC_Control(DDIC_SEG19,DDIC_COM4,DDIC_Control1);		//S15"1档"
	DDIC_Control(DDIC_SEG16,DDIC_COM4,DDIC_Control2);		//S16"2档"
	DDIC_Control(DDIC_SEG14,DDIC_COM4,DDIC_Control3);		//S17"3档"
	DDIC_Control(DDIC_SEG11,DDIC_COM4,DDIC_Control4);		//S18"4档"


}

/**************************************************
*函数名称：void LCD_power(uint8_t DDIC_powerControl)
*函数功能：LCD显示电量
*入口参数：uint8_t DDIC_powerControl
*出口参数：void
**************************************************/

void LCD_power(uint8_t DDIC_powerControl)
{
	
	bit DDIC_Control1;
	bit	DDIC_Control2;
	bit	DDIC_Control3;

	
	DDIC_Control(DDIC_SEG0,DDIC_COM4,DDIC_Control_ON);		//S36"电量"
	
	switch(DDIC_powerControl)
	{
		case 0:
			DDIC_Control1 = 0;
			DDIC_Control2 = 0;
			DDIC_Control3 = 0;
		
		break;
		
		case 1: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 0;
			DDIC_Control3 = 0;

		break;
		
		case 2: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 1;
			DDIC_Control3 = 0;

		break;
		
		case 3: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 1;
			DDIC_Control3 = 1;
	
		break;
		
		default:
			break;
	}

	DDIC_Control(DDIC_SEG0,DDIC_COM6,DDIC_Control1);		//S34"电量1"
	DDIC_Control(DDIC_SEG0,DDIC_COM5,DDIC_Control2);		//S35"电量2"
	DDIC_Control(DDIC_SEG0,DDIC_COM7,DDIC_Control3);		//S36"电量3"
	
}	

/**************************************************
*函数名称：void LCD_signal(uint8_t DDIC_signalControl)
*函数功能：LCD显示信号
*入口参数：uint8_t DDIC_signalControl
*出口参数：void
**************************************************/

void LCD_signal(uint8_t DDIC_signalControl)
{
	
	bit DDIC_Control1;
	bit	DDIC_Control2;
	bit	DDIC_Control3;

	
	DDIC_Control(DDIC_SEG10,DDIC_COM7,DDIC_Control_ON);		//S37"信号"
	
	switch(DDIC_signalControl)
	{
		case 0:
			DDIC_Control1 = 0;
			DDIC_Control2 = 0;
			DDIC_Control3 = 0;
		
		
		break;
		
		case 1: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 0;
			DDIC_Control3 = 0;

		break;
		
		case 2: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 1;
			DDIC_Control3 = 0;

		break;
		
		case 3: 
			DDIC_Control1 = 1;
			DDIC_Control2 = 1;
			DDIC_Control3 = 1;
	
		break;
		
		default:
			break;
	}

	DDIC_Control(DDIC_SEG9,DDIC_COM7,DDIC_Control1);		//S38"信号1"
	DDIC_Control(DDIC_SEG7,DDIC_COM7,DDIC_Control2);		//S39"信号2"
	DDIC_Control(DDIC_SEG6,DDIC_COM7,DDIC_Control3);		//S40"信号3"
	
	
}	

/**************************************************
*函数名称：void LCD_number(uint8_t bits,uint8_t num,bit blink)
*函数功能：LCD显示数字
*入口参数：uint8_t bits,uint8_t num
*出口参数：void
**************************************************/

void LCD_number(uint8_t bits,uint8_t num,bit blink)
{
	uint8_t select;
	
	for(select=0;select<7;select++)
	{	
		DDIC_Control(LCD_number_SEG[bits][select],LCD_number_COM[num][select],blink);
	}		
}

/**************************************************
*函数名称：void LCD_time(uint8_t hour,uint8_t min)
*函数功能：LCD显示时间
*入口参数：uint8_t hour,uint8_t min
*出口参数：void
**************************************************/

void LCD_time(uint8_t LCD_time_hour,uint8_t LCD_time_min,uint8_t LCD_time_week,bit LCD_time_hour_flag,bit LCD_time_min_flag,bit LCD_time_week_flag)
{	

		LCD_number(4,LCD_time_hour/10,LCD_time_hour_flag);
		LCD_number(5,LCD_time_hour%10,LCD_time_hour_flag);

		LCD_number(6,LCD_time_min/10,LCD_time_min_flag);
		LCD_number(7,LCD_time_min%10,LCD_time_min_flag);

		DDIC_Control(LCD_week_SEG[LCD_time_week],DDIC_COM7,LCD_time_week_flag);
	
}

/**************************************************
*函数名称：void LCD_sTemperature(uint8_t DDIC_temperature)
*函数功能：LCD显示摄氏度
*入口参数：uint8_t DDIC_temperature
*出口参数：void
**************************************************/

void LCD_Temper_error(void)
{
	DDIC_Control(DDIC_SEG21,DDIC_COM6,DDIC_Control_OFF);		//1B""
	DDIC_Control(DDIC_SEG21,DDIC_COM5,DDIC_Control_OFF);		//1C""
	DDIC_Control(DDIC_SEG19,DDIC_COM5,DDIC_Control_OFF);		//2D""
	DDIC_Control(DDIC_SEG16,DDIC_COM5,DDIC_Control_OFF);		//3D""
}

/**************************************************
*函数名称：void LCD_sTemperature(uint8_t DDIC_temperature)
*函数功能：LCD显示摄氏度
*入口参数：uint8_t DDIC_temperature
*出口参数：void
**************************************************/

void LCD_sTemperature(uint16_t DDIC_temperature)
{
	
	if(DDIC_temperature>999)	//这是摄氏度
	DDIC_Control(DDIC_SEG24,DDIC_COM6,DDIC_Control_ON);		//S19"1"
	
	DDIC_Control(DDIC_SEG1,DDIC_COM7,DDIC_Control_ON);		//S21"C"
		LCD_number(1,DDIC_temperature%1000/100,1);
		LCD_number(2,(DDIC_temperature%100)/10,1);
		LCD_number(3,DDIC_temperature%10,1);
	
	DDIC_Control(DDIC_SEG17,DDIC_COM4,DDIC_Control_ON);		//S20"."
	
}

//sTemperature = 5/9.0*(hTemperature-32);

/**************************************************
*函数名称：void LCD_hTemperature(uint8_t DDIC_temperature)
*函数功能：LCD显示华氏度
*入口参数：uint8_t DDIC_temperature
*出口参数：void
**************************************************/

void LCD_hTemperature(uint16_t DDIC_temperature)
{
	LCD_clean(TEMPER);
	if(DDIC_temperature>999)	//这是华氏度
	DDIC_Control(DDIC_SEG24,DDIC_COM6,DDIC_Control_ON);		//S19"1"
	
	DDIC_Control(DDIC_SEG3,DDIC_COM7,DDIC_Control_ON);		//S22"F"
		LCD_number(1,DDIC_temperature%1000/100,1);
		LCD_number(2,DDIC_temperature%100/10,1);
		LCD_number(3,DDIC_temperature%10,1);
	
	DDIC_Control(DDIC_SEG17,DDIC_COM4,DDIC_Control_ON);		//S20"."
	
}
