//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: SC_it.h
//	����		: 
//	ģ�鹦��	: sc95f8x1x �жϷ������ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/1/21
// 	�汾		: V1.0   
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