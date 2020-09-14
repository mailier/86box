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

#ifndef _OPERATION_H_
#define	_OPERATION_H_

#include "sc95f8x1x.h"

extern bit sect_blink_flag;

typedef struct _NOW_{
	
	u8 week;				//星期
	u8 mode;			    //模式
	u16 temper;				//温度
	u8 state;				//状态
	u8 wind;				//风量
	u8 hour;				//时间
	u8 min;				
	u8 group;				//组别
	
} NOW;

extern NOW  now;
	
void MainFuction(void);

void main_part(void);		//显示主界面（时间状态）

void hotcool_part(void);

void wind_part(void);

void holiday_part(void);
	
void clock_part(void);

void menu_bar(void);

void time6_part(void);

void copy_part(void);

void FCtemper_part(void);

#endif