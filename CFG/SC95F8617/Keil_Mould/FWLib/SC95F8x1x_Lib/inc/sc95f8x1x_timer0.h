//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_timer0.h
//	����		: 
//	ģ�鹦��	: TIMER0�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_TIMER0_H_
#define	_sc95f8x1x_TIMER0_H_

#include "sc95f8x1x.h"

typedef enum
{
  TIM0_PRESSEL_FSYS_D12 = ((uint8_t)0x00),   //TIMER0����Դ����ϵͳʱ��12��Ƶ
  TIM0_PRESSEL_FSYS_D1  = ((uint8_t)0x01)    //TIMER0����Դ����ϵͳʱ��
}TIM0_PresSel_TypeDef;

typedef enum
{
  TIM0_MODE_TIMER   = ((uint8_t)0x01), //TIMER0����ʱ��
  TIM0_MODE_COUNTER = ((uint8_t)0x02)  //TIMER0��������
}TIM0_CountMode_TypeDef;

typedef enum {
	TIM0_WORK_MODE0   = ((uint8_t)0x00),		//TIMER0ѡ����ģʽ0
	TIM0_WORK_MODE1   = ((uint8_t)0x01),		//TIMER0ѡ����ģʽ1
	TIM0_WORK_MODE2   = ((uint8_t)0x02),		//TIMER0ѡ����ģʽ2
	TIM0_WORK_MODE3   = ((uint8_t)0x03)			//TIMER0ѡ����ģʽ3
}TIM0_WorkMode_TypeDef;

void TIM0_DeInit(void);
void TIM0_TimeBaseInit(TIM0_PresSel_TypeDef TIM0_PrescalerSelection,TIM0_CountMode_TypeDef TIM0_CountMode);
void TIM0_WorkMode0Config(uint16_t TIM0_SetCounter);
void TIM0_WorkMode1Config(uint16_t TIM0_SetCounter);
void TIM0_WorkMode2Config(uint8_t TIM0_SetCounter);
void TIM0_WorkMode3Config(uint8_t TIM0_SetCounter, uint8_t TIM1_SetCounter);
void TIM0_Mode0SetReloadCounter(uint16_t TIM0_SetCounter);
void TIM0_Mode1SetReloadCounter(uint16_t TIM0_SetCounter);
void TIM0_SetTL0Counter(uint8_t TIM0_SetCounter);
void TIM0_SetTH0Counter(uint8_t TIM0_SetCounter);
void TIM0_Cmd(FunctionalState NewState);
void TIM0_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus TIM0_GetFlagStatus(void);
void TIM0_ClearFlag(void);
void TIM0_WorkModeConfig(TIM0_WorkMode_TypeDef TIM0_WorkMode, uint16_t TIM0_SetCounter1, uint16_t TIM0_SetCounter2);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/