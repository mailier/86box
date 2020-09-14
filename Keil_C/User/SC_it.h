//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: SC_it.h
//	作者		: 
//	模块功能	: sc95f8x1x 中断服务程序头文件
//	局部函数列表:
//  最后更正日期: 2019/1/21
// 	版本		: V1.0   
//*************************************************************
#ifndef _SC_IT_H_
#define	_SC_IT_H_

#include "sc95f8x1x_conf.h"



extern unsigned int blink_start_count;

extern bit  TIME_3msFlag;
extern bit  TIME_5msFlag;
extern bit  TIME_10msFlag;

extern bit  TIME_50msFlag;
extern bit  TIME_100msFlag;

extern bit  TIME_150msFlag;

extern bit  TIME_200msFlag;
extern bit  TIME_300msFlag;
extern bit  TIME_400msFlag;
extern bit  TIME_500msFlag;
extern bit  TIME_1000msFlag;

void delay_ms(uint16_t ms);


#endif