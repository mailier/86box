//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_adc.c
//	����		: 
//	ģ�鹦��	: ADC�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_adc.h"

/**************************************************
*�������ƣ�void ADC_DeInit(void)
*�������ܣ�ADC��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void ADC_DeInit(void)
{
	ADCCON = 0x00;
	ADCCFG0 = 0X00;
	ADCCFG1 = 0X00;
	ADCCFG2 = 0X00;
	ADCVL = 0X00;
	ADCVH = 0X00;
	EADC = 0;
	IPADC = 0;
}

/**************************************************
*�������ƣ�void ADC_Init(ADC_Cycle_TypeDef ADC_Cycle)
*�������ܣ�ADC��ʼ�����ú���
*��ڲ�����ADC_Cycle		����ʱ��ѡ��
*���ڲ�����void
**************************************************/
void ADC_Init(ADC_Cycle_TypeDef ADC_Cycle)
{
	ADCCFG2 = ADC_Cycle;			
}

/**************************************************
*�������ƣ�void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
*�������ܣ�ADC��������ú���
*��ڲ�����ADC_Channel				 ADC�����ѡ��
		   FunctionalState NewState	 ADCxʹ��/�ر�ѡ��	
*���ڲ�����void
**************************************************/
void ADC_ChannelConfig(ADC_Channel_TypeDef ADC_Channel, FunctionalState NewState)
{
	uint16_t tmpreg;

	ADCCON = (ADCCON & 0XE0) | ADC_Channel;
	tmpreg = (0x0001 << ADC_Channel);

	if(ADC_Channel < ADC_CHANNEL_VDD_D4)
	{
		if(NewState == DISABLE)
		{
			ADCCFG0 &= (~(uint8_t)tmpreg);
			ADCCFG1 &= (~(uint8_t)(tmpreg>>8)); 	
		}
		else
		{
			ADCCFG0 |= ((uint8_t)tmpreg);
			ADCCFG1 |= ((uint8_t)(tmpreg>>8));
		}
	} 		
}
/**************************************************
*�������ƣ�void ADC_EAINConfig(ADC_EAIN_TypeDef ADC_Channel, FunctionalState NewState)
*�������ܣ�����Ӧ��ADC���������Ϊģ������ģʽ
*��ڲ�����ADC_EAIN_Select		     ѡ����Ҫ���õ�ADC��
		   FunctionalState NewState	 ADCͨ��ʹ��/�ر�ѡ��	
*���ڲ�����void
**************************************************/
void ADC_EAINConfig(uint16_t ADC_EAIN_Select, FunctionalState NewState)
{
	if(NewState == DISABLE)
	{
		ADCCFG0 &= (~(uint8_t)ADC_EAIN_Select);
		ADCCFG1 &= (~(uint8_t)(ADC_EAIN_Select>>8)); 	
	}
	else
	{
		ADCCFG0 |= ((uint8_t)ADC_EAIN_Select);
		ADCCFG1 |= ((uint8_t)(ADC_EAIN_Select>>8));
	}
}
/*****************************************************
*�������ƣ�void ADC_Cmd(FunctionalState NewState)
*�������ܣ�ADC���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void ADC_Cmd(FunctionalState NewState)
{
	if(NewState == DISABLE)
	{
		ADCCON &= 0X7F;
	}
	else
	{
		ADCCON |= 0x80;
	}	
}

/*****************************************************
*�������ƣ�void ADC_StartConversion(void)
*�������ܣ���ʼһ��ADת��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void ADC_StartConversion(void)
{
	ADCCON |= 0X40;
}

/*****************************************************
*�������ƣ�uint16_t ADC_GetConversionValue(void)
*�������ܣ����һ��ADת������
*��ڲ�����void
*���ڲ�����uint16_t
*****************************************************/
uint16_t ADC_GetConversionValue(void)
{
	uint16_t temp;
	temp = (uint16_t)(ADCVH<<4) + (ADCVL>>4);
	return temp;
}

/*****************************************************
*�������ƣ�void ADC_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�ADC�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void ADC_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
    if(NewState == DISABLE)
    {
       EADC = 0;
    }
    else
    {
       EADC = 1;
    }
/************************************************************/
	if(Priority == LOW)
	{
		IPADC = 0;
	}
	else
	{
		IPADC = 1;
	}
}

/*****************************************************
*�������ƣ�FlagStatus ADC_GetFlagStatus(void)
*�������ܣ����ADC�жϱ�־״̬
*��ڲ�����void
*���ڲ�����FlagStatus	ADC�жϱ�־״̬	
*****************************************************/
FlagStatus ADC_GetFlagStatus(void)
{
	return (FlagStatus)(ADCCON & 0x20);
}

/*****************************************************
*�������ƣ�void ADC_ClearFlag(void)
*�������ܣ����ADC�жϱ�־״̬
*��ڲ�����void
*���ڲ�����void	
*****************************************************/
void ADC_ClearFlag(void)
{
   ADCCON &= 0xdf;
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/