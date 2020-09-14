//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_wdt.h
//	����		: 
//	ģ�鹦��	: WDT�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_WDT_H_
#define	_sc95f8x1x_WDT_H_

#include "sc95f8x1x.h"

typedef enum {
  WDT_OverflowTime_500MS   = (uint8_t)0x00, 	   //���Ź����ʱ��Ϊ500MS
  WDT_OverflowTime_250MS   = (uint8_t)0x01, 	   //���Ź����ʱ��Ϊ250MS
  WDT_OverflowTime_125MS   = (uint8_t)0x02, 	   //���Ź����ʱ��Ϊ125MS
  WDT_OverflowTime_62_5MS  = (uint8_t)0x03, 	   //���Ź����ʱ��Ϊ62.5MS
  WDT_OverflowTime_31_5MS  = (uint8_t)0x04, 	   //���Ź����ʱ��Ϊ31.5MS
  WDT_OverflowTime_15_75MS = (uint8_t)0x05, 	   //���Ź����ʱ��Ϊ15.75MS
  WDT_OverflowTime_7_88MS  = (uint8_t)0x06, 	   //���Ź����ʱ��Ϊ7.88MS
  WDT_OverflowTime_3_94MS  = (uint8_t)0x07  	   //���Ź����ʱ��Ϊ3.94MS
} WDT_OverflowTime_TypeDef;

void WDT_DeInit(void);
void WDT_Init(WDT_OverflowTime_TypeDef OverflowTime);
void WDT_SetReload(void);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/