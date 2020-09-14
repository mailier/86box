//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_INT.h
//	作者		: 
//	模块功能	: INT固件库函数头文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#ifndef _sc95f8x1x_INT_H_
#define	_sc95f8x1x_INT_H_

#include "sc95f8x1x.h"

typedef enum {
  INT_TRIGGER_RISE_ONLY = (uint8_t)0x01,	//外部中断触发方式为上升沿
  INT_TRIGGER_FALL_ONLY = (uint8_t)0x02,	//外部中断触发方式为下降沿
  INT_TRIGGER_RISE_FALL = (uint8_t)0x03,	//外部中断触发方式为上升沿与下降沿
  INT_TRIGGER_DISABLE   = (uint8_t)0x04	//关闭外部中断触发
}INT_TriggerMode_Typedef;

typedef enum {
  INT0 = (uint8_t)0x00,			//外部中断0
  INT1 = (uint8_t)0x01,			//外部中断1
  INT2 = (uint8_t)0x02			//外部中断2
}INTx_Typedef;

typedef enum {
  INT04 = (uint8_t)0x10,		//将P04设置为外部中断脚
  INT05 = (uint8_t)0x20,		//将P05设置为外部中断脚
  INT06 = (uint8_t)0x40,	 	//将P06设置为外部中断脚
  INT07 = (uint8_t)0x80			//将P07设置为外部中断脚
}INT0x_Typedef;

typedef enum {
  INT10 = (uint8_t)0x01,		//将P40设置为外部中断脚
  INT11 = (uint8_t)0x02,		//将P41设置为外部中断脚
  INT12 = (uint8_t)0x04,		//将P42设置为外部中断脚
  INT13 = (uint8_t)0x08,		//将P43设置为外部中断脚
  INT14 = (uint8_t)0x10,		//将P14设置为外部中断脚
  INT15 = (uint8_t)0x20,		//将P15设置为外部中断脚
  INT16 = (uint8_t)0x40,		//将P16设置为外部中断脚
  INT17 = (uint8_t)0x80 		//将P17设置为外部中断脚
}INT1x_Typedef;

typedef enum {
  INT20 = (uint8_t)0x01,		//将P20设置为外部中断脚
  INT21 = (uint8_t)0x02,		//将P21设置为外部中断脚
  INT22 = (uint8_t)0x04,		//将P22设置为外部中断脚
  INT23 = (uint8_t)0x08 		//将P23设置为外部中断脚
}INT2x_Typedef;

void INT_DeInit(INTx_Typedef INTx);
void INT0_SetTriggerMode(uint8_t INT0x, INT_TriggerMode_Typedef TriggerMode);
void INT1_SetTriggerMode(uint8_t INT1x, INT_TriggerMode_Typedef TriggerMode);
void INT2_SetTriggerMode(uint8_t INT2x, INT_TriggerMode_Typedef TriggerMode);
void INT0_ITConfig(FunctionalState NewState, PriorityStatus Priority);
void INT1_ITConfig(FunctionalState NewState, PriorityStatus Priority);
void INT2_ITConfig(FunctionalState NewState, PriorityStatus Priority);
#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/