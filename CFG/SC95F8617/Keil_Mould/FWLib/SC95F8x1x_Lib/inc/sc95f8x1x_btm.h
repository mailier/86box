//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_btm.h
//	����		: 
//	ģ�鹦��	: BTM�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************
#ifndef _sc95f8x1x_BTM_H_
#define	_sc95f8x1x_BTM_H_

#include "sc95f8x1x.h"

typedef enum {
	BTM_TIMEBASE_15_625MS = (uint8_t)0x00,		//BTMÿ15.625MS����һ���ж�
	BTM_TIMEBASE_31_25MS  = (uint8_t)0x01,		//BTMÿ31.25MS����һ���ж�
	BTM_TIMEBASE_62_5MS   = (uint8_t)0x02,		//BTMÿ62.5MS����һ���ж�
	BTM_TIMEBASE_125MS    = (uint8_t)0x03,		//BTMÿ125MS����һ���ж�
	BTM_TIMEBASE_250MS    = (uint8_t)0x04,		//BTMÿ0.25S����һ���ж�
	BTM_TIMEBASE_500MS    = (uint8_t)0x05,		//BTMÿ0.5S����һ���ж�
	BTM_TIMEBASE_1S       = (uint8_t)0x06,		//BTMÿ1S����һ���ж�
	BTM_TIMEBASE_2S       = (uint8_t)0x07,		//BTMÿ2S����һ���ж�
	BTM_TIMEBASE_4S       = (uint8_t)0x08,		//BTMÿ4S����һ���ж�
	BTM_TIMEBASE_8S       = (uint8_t)0x09,		//BTMÿ8S����һ���ж�
	BTM_TIMEBASE_16S      = (uint8_t)0x0a,		//BTMÿ16S����һ���ж�
	BTM_TIMEBASE_32S      = (uint8_t)0x0b		//BTMÿ32S����һ���ж�
} BTM_Timebase_TypeDef;

void BTM_DeInit(void);
void BTM_Init(BTM_Timebase_TypeDef BTM_Timebase);
void BTM_Cmd(FunctionalState NewState);
void BTM_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus BTM_GetFlagStatus(void);
void BTM_ClearFlag(void);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/