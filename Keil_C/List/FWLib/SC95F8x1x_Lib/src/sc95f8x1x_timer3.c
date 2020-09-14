//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_timerx.c
//	����		: 
//	ģ�鹦��	: TIMER3�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2020/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_timer3.h"

/**************************************************
*�������ƣ�void TIMX_DeInit(void)
*�������ܣ�TIMER3��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void TIM3_DeInit()
{
	TXINX = 0x03;    //TIMER3 ѡ��
	TXCON = 0X00;
	TXMOD = 0X00;
	RCAPXH = 0X00;
	RCAPXL = 0X00;
	THX = 0X00;
	TLX = 0X00;
	IE1 &= 0X3F;
	IP1 &= 0X3F;
	ET2 = 0;
	IPT2 = 0;
}

/**************************************************
*�������ƣ�void TIM3_PrescalerSelection(TIMX_TimerSelect_TypeDef TIMX_TimerSelect, TIMX_PresSel_TypeDef TIMX_PrescalerSelection)
*�������ܣ�TIMER3 Ԥ��Ƶѡ��
*��ڲ�����TIM2_PrescalerSelection	Ԥ��Ƶѡ��
*���ڲ�����void
**************************************************/
void TIM3_PrescalerSelection(TIM3_PresSel_TypeDef TIM3_PrescalerSelection)
{
	TXINX = 0x03;
	if(TIM3_PrescalerSelection == TIM3_PRESSEL_FSYS_D12)
	{
		TXMOD &= 0X7F;
	}
	else if(TIM3_PrescalerSelection == TIM3_PRESSEL_FSYS_D1)
	{
		TXMOD |= 0X80;
	}	
}

/**************************************************
*�������ƣ�void TIM3_WorkMode1Config(uint16_t TIM3_SetCounter)
*�������ܣ�TIMER3����ģʽ1���ú���
*��ڲ�����uint16_t TIM3_SetCounter	���ü�����ֵ
*���ڲ�����void
**************************************************/
void TIM3_WorkMode1Config(uint16_t TIM3_SetCounter)
{	
	TXINX = 0x03;
	RCAPXL = TIM3_SetCounter % 256;
	RCAPXH = TIM3_SetCounter / 256;

	TLX = RCAPXL;
	THX = RCAPXH;
}

/*****************************************************
*�������ƣ�void TIM3_Cmd(FunctionalState NewState)
*�������ܣ�TIMER3���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void TIM3_Cmd(FunctionalState NewState)
{
	TXINX = 0x03;
	if (NewState == DISABLE)
    {
       TRX = 0;
    }
    else
    {
       TRX = 1;
    }
}

/*****************************************************
*�������ƣ�void TIM3_ITConfig(TIM3_TimerSelect_TypeDef TIM3_TimerSelect, FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�TIMER3�жϳ�ʼ��
*��ڲ�����NewState	�ж�ʹ��/�ر�ѡ��
 		   Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void TIM3_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	TXINX = 0x03;
	if(NewState == DISABLE)
	{
   		IE1 &= 0XBF;
	}
	else
	{
   		IE1 |= 0X40;
	}
	if(Priority == LOW)
	{
		IP1 &= 0XBF;
	}
	else
	{
		IP1 |= 0X40;
	}
}

/*****************************************************
*�������ƣ�FlagStatus TIM3_GetFlagStatus(void)
*�������ܣ����TIMER3�жϱ�־״̬
*��ڲ�����TIM3_Flag   	TIMER3��־ѡ��
*���ڲ�����FlagStatus	TIMER3�жϱ�־״̬	
*****************************************************/
FlagStatus TIM3_GetFlagStatus()
{	
	FlagStatus status = RESET;
	TXINX = 0x03;
	if(TFX)
	{
		status = SET; 			
	}
	else
	{
		status = RESET;	
	}
	return status;	
}

/*****************************************************
*�������ƣ�void TIM3_ClearFlag(void)
*�������ܣ����TIMER3�жϱ�־״̬
*��ڲ�����TIM3_Flag   TIMER3��־ѡ��
*���ڲ�����void	
*****************************************************/
void TIM3_ClearFlag()
{
	TXINX = 0x03;
	TXCON &= 0x7F;
}

/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/