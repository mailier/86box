//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_timerx.h
//	����		: 
//	ģ�鹦��	: TIMER3�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_TIMER3_H_
#define	_sc95f8x1x_TIMER3_H_

#include "sc95f8x1x.H"

typedef enum
{
	TIM3_PRESSEL_FSYS_D12  = ((uint8_t)0x00), //TIMER3����Դ����ϵͳʱ��12��Ƶ
	TIM3_PRESSEL_FSYS_D1   = ((uint8_t)0x01)  //TIMER3����Դ����ϵͳʱ��
}TIM3_PresSel_TypeDef;

void TIM3_DeInit();
void TIM3_PrescalerSelection(TIM3_PresSel_TypeDef TIM3_PrescalerSelection);
void TIM3_WorkMode1Config(uint16_t TIM3_SetCounter);
void TIM3_Cmd(FunctionalState NewState);
void TIM3_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus TIM3_GetFlagStatus();
void TIM3_ClearFlag();

#endif

/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/