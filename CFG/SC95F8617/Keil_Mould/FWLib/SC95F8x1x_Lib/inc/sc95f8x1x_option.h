//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_option.h
//	����		: 
//	ģ�鹦��	: Customer Option�Ĵ�������ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_OPTION_H_
#define	_sc95f8x1x_OPTION_H_

#include "sc95f8x1x.h"

typedef enum {
	SYSCLK_PRESSEL_FOSC_D1  = (uint8_t)0x00,	//Ԥ��Ƶ Fsys = Fosc/1
	SYSCLK_PRESSEL_FOSC_D2  = (uint8_t)0x10,	//Ԥ��Ƶ Fsys = Fosc/2
	SYSCLK_PRESSEL_FOSC_D4  = (uint8_t)0x20,	//Ԥ��Ƶ Fsys = Fosc/4
	SYSCLK_PRESSEL_FOSC_D12 = (uint8_t)0x30 	//Ԥ��Ƶ Fsys = Fosc/12 
} SYSCLK_PresSel_TypeDef;

typedef enum {
	LVR_INVALID	= (uint8_t)0x04,	//LVR��Ч
	LVR_1_9V    = (uint8_t)0x00,	//LVR 1.9V��λ
	LVR_2_9V    = (uint8_t)0x01,	//LVR 2.9V��λ
	LVR_3_7V    = (uint8_t)0x02,	//LVR 3.7V��λ
	LVR_4_3V    = (uint8_t)0x03 	//LVR 4.3V��λ
} LVR_Config_TypeDef;

typedef enum {
	IAP_OPERATERANGE__LAST_1K_CODEREGION 	= (uint8_t)0x00,	//����ROM���1k����IAP����
	IAP_OPERATERANGE__LAST_2K_CODEREGION  	= (uint8_t)0x04,	//����ROM���2k����IAP����
	IAP_OPERATERANGE__LAST_4K_CODEREGION    = (uint8_t)0x08,	//����ROM���4k����IAP����
	IAP_OPERATERANGE__ALL_CODEREGION 	    = (uint8_t)0x0c		//����ROM�����������IAP����
} IAP_OperateRange_TypeDef;

typedef enum 
{
	ADC_VREF_VDD  = 0x00,		//VDD���ο�ADC��ѹ
	ADC_VREF_2_048V = 0x40,     //�ڲ�2.048V��ADC�ο���ѹ
	ADC_VREF_1_024V = 0x80    	//�ڲ�1.024V��ADC�ο���ѹ
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