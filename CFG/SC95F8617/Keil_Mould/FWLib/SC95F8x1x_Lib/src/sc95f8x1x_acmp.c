//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_acmp.c
//	����		: 
//	ģ�鹦��	: ACMP�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_acmp.h"

/**************************************************
*�������ƣ�void ACMP_DeInit(void)
*�������ܣ�MDU��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void ACMP_DeInit(void)
{
	CMPCON = 0X00;
    CMPCFG = 0X00;
}

/**************************************************
*�������ƣ�void ACMP_Init(ACMP_Vref_Typedef ACMP_Vref, ACMP_Channel_TypeDef ACMP_Channel)
*�������ܣ�ģ��Ƚ�����ʼ�����ú���
*��ڲ�����ACMP_Vref	  ACMP�ο���ѹѡ��
		   ACMP_Channel	  ACMP����ͨ��ѡ��	
*���ڲ�����void
**************************************************/
void ACMP_Init(ACMP_Vref_Typedef ACMP_Vref, ACMP_Channel_TypeDef ACMP_Channel)
{
	CMPCON = CMPCON & 0XF0 | ACMP_Vref;
	CMPCFG = CMPCFG & 0XFC | ACMP_Channel;
}

/**************************************************
*�������ƣ�void ACMP_SetTriggerMode(ACMP_TriggerMode_Typedef ACMP_TriggerMode)
*�������ܣ�ACMP�жϴ�����ʽ���ú���
*��ڲ�����ACMP_TriggerMode	�жϴ�����ʽѡ��
*���ڲ�����void
**************************************************/
void ACMP_SetTriggerMode(ACMP_TriggerMode_Typedef ACMP_TriggerMode)
{
	CMPCFG = CMPCFG & 0X03 | ACMP_TriggerMode; 
}

/*****************************************************
*�������ƣ�void ACMP_Cmd(FunctionalState NewState)
*�������ܣ�ACMP���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void ACMP_Cmd(FunctionalState NewState)
{
	if(NewState == DISABLE)
	{
		CMPCON &= 0X7F;
	}
	else
	{
		CMPCON |= 0x80;
	}	
}

/*****************************************************
*�������ƣ�void ACMP_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�ACMP�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void ACMP_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
    if(NewState == DISABLE)
    {
       IE1 &= 0XBF;
    }
    else
    {
       IE1 |= 0X20;
    }
/************************************************************/
	if(Priority == LOW)
	{
		IP1 &= 0XBF;
	}
	else
	{
		IP1 |= 0X20;
	}
}

/*****************************************************
*�������ƣ�FlagStatus ACMP_GetFlagStatus(ACMP_Flag_TypeDef ACMP_Flag)
*�������ܣ����ACMP��־״̬
*��ڲ�����ACMP_Flag	��־λѡ��
*���ڲ�����FlagStatus   ACMP��־״̬	
*****************************************************/
FlagStatus ACMP_GetFlagStatus(ACMP_Flag_TypeDef ACMP_Flag)
{
	return (FlagStatus)(CMPCON & ACMP_Flag);
}

/*****************************************************
*�������ƣ�void ACMP_ClearFlag(void)
*�������ܣ������־״̬
*��ڲ�����ACMP_Flag	�жϱ�־λѡ��
*���ڲ�����void	
*****************************************************/
void ACMP_ClearFlag(void)
{
   CMPCON &= (~ACMP_FLAG_CMPIF);
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/