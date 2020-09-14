//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_timerx.h
//	����		: 
//	ģ�鹦��	: TIMER4�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_TIMER4_H_
#define	_sc95f8x1x_TIMER4_H_

#include "sc95f8x1x.H"

typedef enum
{
	TIM4_PRESSEL_FSYS_D12  = ((uint8_t)0x00), //TIMER4����Դ����ϵͳʱ��12��Ƶ
	TIM4_PRESSEL_FSYS_D1   = ((uint8_t)0x01)  //TIMER4����Դ����ϵͳʱ��
}TIM4_PresSel_TypeDef;


void TIM4_DeInit();
void TIM4_PrescalerSelection(TIM4_PresSel_TypeDef TIM4_PrescalerSelection);
void TIM4_WorkMode1Config(uint16_t TIM4_SetCounter);
void TIM4_Cmd(FunctionalState NewState);
void TIM4_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus TIM4_GetFlagStatus();
void TIM4_ClearFlag();

#endif