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

#ifndef _NST1001_H_
#define	_NST1001_H_

#include "sc95f8x1x.h"


sbit NST1001_IO = P5^3;  //NST1001上拉引脚
sbit NST1001_DQ = P0^6;  //NST1001的DQ引脚

extern bit int1_first_flag;
extern bit temp_judge_flag;

extern bit temp_start_flag;
extern bit temp_over_flag;

extern unsigned char temp_collect_timer2;
extern unsigned char temp_over_timer2;
extern unsigned int temp_num;

extern unsigned int N_Temper;

//extern unsigned int moment_num;


void GetNST1001Temp();



#endif