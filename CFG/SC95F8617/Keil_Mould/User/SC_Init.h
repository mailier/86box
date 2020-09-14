//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: SC_Init.h
//	模块功能	: MCU初始化函数H文件
//  说明        :  
//*************************************************************

#ifndef _SC_INIT_H_
#define _SC_INIT_H_

#include "sc95f8x1X_conf.h"


void SC_Init(void);

void SC_OPTION_Init(void);
void SC_GPIO_Init(void);
void SC_UART0_Init(void);
void SC_TIM0_Init(void);
void SC_TIM1_Init(void);
void SC_TIM2_Init(void);
void SC_TIM3_Init(void);
void SC_TIM4_Init(void);
void SC_PWM_Init(void);
void SC_INT_Init(void);
void SC_ADC_Init(void);
void SC_IAP_Init(void);
void SC_USCI0_Init(void);
void SC_USCI1_Init(void);
void SC_USCI2_Init(void);
void SC_BTM_Init(void);
void SC_CRC_Init(void);
void SC_WDT_Init(void);
void SC_PWR_Init(void);
void SC_DDIC_Init(void);
void SC_ACMP_Init(void);
void SC_MDU_Init(void);

#endif