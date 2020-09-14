//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_option.c
//	����		: 
//	ģ�鹦��	: Customer Option�Ĵ�������C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_option.h"

/*****************************************************
*�������ƣ�void OPTION_WDT_Cmd(FunctionalState NewState)
*�������ܣ�WDT���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void OPTION_WDT_Cmd(FunctionalState NewState)
{
	OPINX = 0XC1;
	if(NewState == DISABLE)
    {
       OPREG &= 0X7F;
    }
    else
    {
       OPREG |= 0X80;
    }	
}

/*****************************************************
*�������ƣ�void OPTION_XTIPLL_Cmd(FunctionalState NewState)
*�������ܣ��ⲿ��Ƶ����ʹ��
*��ڲ�����FunctionalState NewState	����/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void OPTION_XTIPLL_Cmd(FunctionalState NewState)
{
	OPINX = 0XC1;
	if(NewState == DISABLE)
    {
       OPREG &= 0XBF;
    }
    else
    {
       OPREG |= 0X40;
    }	
}

/*****************************************************
*�������ƣ�void OPTION_SYSCLK_Init(SYSCLK_PresSel_TypeDef SYSCLK_PresSel)
*�������ܣ�ϵͳʱ�ӷ�Ƶ��ʼ��
*��ڲ�����SYSCLK_PresSel	ѡ��ϵͳʱ�ӷ�Ƶ
*���ڲ�����void
*****************************************************/
void OPTION_SYSCLK_Init(SYSCLK_PresSel_TypeDef SYSCLK_PresSel)
{
	OPINX = 0XC1;
	OPREG = OPREG & 0XCF | SYSCLK_PresSel;	
}

/*****************************************************
*�������ƣ�void OPTION_RST_PIN_Cmd(FunctionalState NewState)
*�������ܣ��ⲿ��λ�ܽţ�P17��ʹ��
*��ڲ�����FunctionalState NewState	ʹ��/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void OPTION_RST_PIN_Cmd(FunctionalState NewState)
{
	OPINX = 0XC1;
	if(NewState == DISABLE)
    {
		OPREG |= 0X08;
    }
    else
    {
        OPREG &= 0XF7;
    }					
}

/*****************************************************
*�������ƣ�void OPTION_LVR_Init(LVR_Config_TypeDef LVR_Config)
*�������ܣ�LVR ��ѹѡ��
*��ڲ�����LVR_Config	 ѡ��LVR��ѹ
*���ڲ�����void	
*****************************************************/
void OPTION_LVR_Init(LVR_Config_TypeDef LVR_Config)
{
	OPINX = 0XC1;
	OPREG = OPREG & 0XF8 | LVR_Config; 	
}

/*****************************************************
*�������ƣ�void OPTION_ADC_VrefConfig(ADC_Vref_TypeDef ADC_Vref)
*�������ܣ�ADC �ο���ѹѡ��
*��ڲ�����ADC_Vref		ѡ��ADC�ο���ѹ
*���ڲ�����void	
*****************************************************/
void OPTION_ADC_VrefConfig(ADC_Vref_TypeDef ADC_Vref)
{
	OPINX = 0xC2;		
	if(ADC_Vref == ADC_VREF_2_048V)
	{
		OPREG &= 0x3f;
		OPREG |= 0x40;		//ѡ��ο��ڲ���ѹ2.048V��
	}
	if(ADC_Vref == ADC_VREF_1_024V)
	{
		OPREG &= 0x3f;
		OPREG |= 0x80;		//ѡ��ο��ڲ���ѹ1.024V��
	}
	if(ADC_Vref == ADC_VREF_VDD)
	{
		OPREG &= 0x3f;		//ѡ��ο���ѹVDD��
	}
}

/**************************************************
*�������ƣ�void OPTION_IAP_SetOperateRange(IAP_OperateRange_TypeDef IAP_OperateRange)
*�������ܣ�����IAP�����ķ�Χ����
*��ڲ�����IAP_OperateRange		IAP������Χ
*���ڲ�����void
**************************************************/
void OPTION_IAP_SetOperateRange(IAP_OperateRange_TypeDef IAP_OperateRange)
{
	OPINX = 0xC2;
	OPREG = (OPREG & 0xF3) | IAP_OperateRange;
}
/**************************************************
*�������ƣ�void OPTION_JTG_Cmd(FunctionalState NewState)
*�������ܣ�JTAG/IO���л�����
*��ڲ�����ENABLE��P11��P13��Ϊ������IOʹ��
		   DISABLE��P11��P13��ΪtCK/tDIOʹ��
*���ڲ�����void
**************************************************/
void OPTION_JTG_Cmd(FunctionalState NewState)
{
	OPINX = 0xC2;
	if(NewState == DISABLE)
    {
		OPREG |= 0X10;
    }
    else
    {
        OPREG &= 0XEF;
    }	
}


