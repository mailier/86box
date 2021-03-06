//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_option.h
//	作者		: 
//	模块功能	: Customer Option寄存器配置头文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#ifndef _sc95f8x1x_OPTION_H_
#define	_sc95f8x1x_OPTION_H_

#include "sc95f8x1x.h"

typedef enum {
	SYSCLK_PRESSEL_FOSC_D1  = (uint8_t)0x00,	//预分频 Fsys = Fosc/1
	SYSCLK_PRESSEL_FOSC_D2  = (uint8_t)0x10,	//预分频 Fsys = Fosc/2
	SYSCLK_PRESSEL_FOSC_D4  = (uint8_t)0x20,	//预分频 Fsys = Fosc/4
	SYSCLK_PRESSEL_FOSC_D12 = (uint8_t)0x30 	//预分频 Fsys = Fosc/12 
} SYSCLK_PresSel_TypeDef;

typedef enum {
	LVR_INVALID	= (uint8_t)0x04,	//LVR无效
	LVR_1_9V    = (uint8_t)0x00,	//LVR 1.9V复位
	LVR_2_9V    = (uint8_t)0x01,	//LVR 2.9V复位
	LVR_3_7V    = (uint8_t)0x02,	//LVR 3.7V复位
	LVR_4_3V    = (uint8_t)0x03 	//LVR 4.3V复位
} LVR_Config_TypeDef;

typedef enum {
	IAP_OPERATERANGE__LAST_1K_CODEREGION 	= (uint8_t)0x00,	//允许ROM最后1k进行IAP操作
	IAP_OPERATERANGE__LAST_2K_CODEREGION  	= (uint8_t)0x04,	//允许ROM最后2k进行IAP操作
	IAP_OPERATERANGE__LAST_4K_CODEREGION    = (uint8_t)0x08,	//允许ROM最后4k进行IAP操作
	IAP_OPERATERANGE__ALL_CODEREGION 	    = (uint8_t)0x0c		//允许ROM所有区域进行IAP操作
} IAP_OperateRange_TypeDef;

typedef enum 
{
	ADC_VREF_VDD  = 0x00,		//VDD做参考ADC电压
	ADC_VREF_2_048V = 0x40,     //内部2.048V做ADC参考电压
	ADC_VREF_1_024V = 0x80    	//内部1.024V做ADC参考电压
} ADC_Vref_TypeDef;

void OPTION_WDT_Cmd(FunctionalState NewState);
void OPTION_XTIPLL_Cmd(FunctionalState NewState);
void OPTION_SYSCLK_Init(SYSCLK_PresSel_TypeDef SYSCLK_PresSel);
void OPTION_RST_PIN_Cmd(FunctionalState NewState);
void OPTION_LVR_Init(LVR_Config_TypeDef LVR_Config);
void OPTION_ADC_VrefConfig(ADC_Vref_TypeDef ADC_Vref);
void OPTION_IAP_SetOperateRange(IAP_OperateRange_TypeDef IAP_OperateRange);
void OPTION_JTG_Cmd(FunctionalState NewState);
#endif