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

#ifndef _OPERATION_H_
#define	_OPERATION_H_

#include "sc95f8x1x.h"

extern bit sect_blink_flag;

typedef struct _NOW_{
	
	u8 week;				//����
	u8 mode;			    //ģʽ
	u16 temper;				//�¶�
	u8 state;				//״̬
	u8 wind;				//����
	u8 hour;				//ʱ��
	u8 min;				
	u8 group;				//���
	
} NOW;

extern NOW  now;
	
void MainFuction(void);

void main_part(void);		//��ʾ�����棨ʱ��״̬��

void hotcool_part(void);

void wind_part(void);

void holiday_part(void);
	
void clock_part(void);

void menu_bar(void);

void time6_part(void);

void copy_part(void);

void FCtemper_part(void);

#endif