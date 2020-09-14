//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_timerx.h
//	作者		: 
//	模块功能	: TIMER4固件库函数头文件
//	局部函数列表:
//  最后更正日期: 2019/04/16
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#ifndef _sc95f8x1x_TIMER4_H_
#define	_sc95f8x1x_TIMER4_H_

#include "sc95f8x1x.H"

typedef enum
{
	TIM4_PRESSEL_FSYS_D12  = ((uint8_t)0x00), //TIMER4计数源来自系统时钟12分频
	TIM4_PRESSEL_FSYS_D1   = ((uint8_t)0x01)  //TIMER4计数源来自系统时钟
}TIM4_PresSel_TypeDef;


void TIM4_DeInit();
void TIM4_PrescalerSelection(TIM4_PresSel_TypeDef TIM4_PrescalerSelection);
void TIM4_WorkMode1Config(uint16_t TIM4_SetCounter);
void TIM4_Cmd(FunctionalState NewState);
void TIM4_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus TIM4_GetFlagStatus();
void TIM4_ClearFlag();

#endif