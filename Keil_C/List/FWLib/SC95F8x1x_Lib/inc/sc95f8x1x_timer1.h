//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_timer1.h
//	����		: 
//	ģ�鹦��	: TIMER1�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_TIMER1_H_
#define	_sc95f8x1x_TIMER1_H_

#include "sc95f8x1x.h"

typedef enum
{
  TIM1_PRESSEL_FSYS_D12 = ((uint8_t)0x00),   //TIMER1����Դ����ϵͳʱ��12��Ƶ
  TIM1_PRESSEL_FSYS_D1  = ((uint8_t)0x01)    //TIMER1����Դ����ϵͳʱ��
}TIM1_PresSel_TypeDef;

typedef enum
{
  TIM1_MODE_TIMER   = ((uint8_t)0x01), //TIMER1����ʱ��
  TIM1_MODE_COUNTER = ((uint8_t)0x02)  //TIMER1��������
}TIM1_CountMode_TypeDef;

typedef enum {
	TIM1_WORK_MODE0   = ((uint8_t)0x00),		//TIMER1ѡ����ģʽ0
	TIM1_WORK_MODE1   = ((uint8_t)0x01),		//TIMER1ѡ����ģʽ1
	TIM1_WORK_MODE2   = ((uint8_t)0x02),		//TIMER1ѡ����ģʽ2
}TIM1_WorkMode_TypeDef;

void TIM1_DeInit(void);
void TIM1_TimeBaseInit(TIM1_PresSel_TypeDef TIM1_PrescalerSelection,TIM1_CountMode_TypeDef TIM1_CountMode);
void TIM1_WorkMode0Config(uint16_t TIM1_SetCounter);
void TIM1_WorkMode1Config(uint16_t TIM1_SetCounter);
void TIM1_WorkMode2Config(uint8_t TIM1_SetCounter);
void TIM1_Mode0SetReloadCounter(uint16_t TIM1_SetCounter);
void TIM1_Mode1SetReloadCounter(uint16_t TIM1_SetCounter);
void TIM1_Cmd(FunctionalState NewState);
void TIM1_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus TIM1_GetFlagStatus(void);
void TIM1_ClearFlag(void);
void TIM1_WorkModeConfig(TIM1_WorkMode_TypeDef TIM1_WorkMode, uint16_t TIM1_SetCounter);


#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/