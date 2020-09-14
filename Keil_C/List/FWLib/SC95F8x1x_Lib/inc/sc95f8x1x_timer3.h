//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_timerx.h
//	作者		: 
//	模块功能	: TIMER3固件库函数头文件
//	局部函数列表:
//  最后更正日期: 2019/04/16
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#ifndef _sc95f8x1x_TIMER3_H_
#define	_sc95f8x1x_TIMER3_H_

#include "sc95f8x1x.H"

typedef enum
{
	TIM3_PRESSEL_FSYS_D12  = ((uint8_t)0x00), //TIMER3计数源来自系统时钟12分频
	TIM3_PRESSEL_FSYS_D1   = ((uint8_t)0x01)  //TIMER3计数源来自系统时钟
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