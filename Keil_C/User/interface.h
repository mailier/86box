//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: interface.h
//	作者		: 
//	模块功能	: 界面显示函数头文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#ifndef _INTERFACE_H_
#define	_INTERFACE_H_


#include "sc95f8x1x_ddic.h"


#define  TEMPER   	0
#define  TIMER  	1
#define  HOTCOOL    2
#define  WIND       3
#define  STATE    	4
#define  MODE    	5
#define  GROUP  	6 

void LCD_cleanALL(void);
void LCD_clean(uint8_t bits);

void LCD_group(uint8_t bits);
void LCD_week(uint8_t week,bit blink);
void LCD_mode(uint8_t mode);
void LCD_state(uint8_t state);
void LCD_wind(uint8_t DDIC_windControl);
void LCD_power(uint8_t DDIC_powerControl);
void LCD_signal(uint8_t DDIC_signalControl);

void LCD_number(uint8_t bits,uint8_t num,bit blink);	
void LCD_time(uint8_t LCD_time_hour,uint8_t LCD_time_min,uint8_t LCD_time_week,bit LCD_time_hour_flag,bit LCD_time_min_flag,bit LCD_time_week_flag);
void LCD_sTemperature(uint16_t DDIC_temperature);
void LCD_hTemperature(uint16_t DDIC_temperature);
	
void LCD_Temper_error(void);	
#endif
