//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: interface.h
//	����		: 
//	ģ�鹦��	: ������ʾ����ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _NST1001_H_
#define	_NST1001_H_

#include "sc95f8x1x.h"


sbit NST1001_IO = P5^3;  //NST1001��������
sbit NST1001_DQ = P0^6;  //NST1001��DQ����

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