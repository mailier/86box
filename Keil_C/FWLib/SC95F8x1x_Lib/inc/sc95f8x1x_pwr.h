//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_pwr.h
//	作者		: 
//	模块功能	: PWR固件库函数头文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#ifndef _sc95f8x1x_PWR_H_
#define	_sc95f8x1x_PWR_H_

#include "sc95f8x1x.h"
#include <intrins.h>

void PWR_DeInit(void);
void PWR_EnterSTOPMode(void);
void PWR_ExitSTOPMode(void);
void PWR_EnterIDLEMode(void);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/