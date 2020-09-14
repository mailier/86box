//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_timer4.c
//	����		: 
//	ģ�鹦��	: TIMER4�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2020/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_timer4.h"

/**************************************************
*�������ƣ�void TIM4_DeInit(void)
*�������ܣ�TIMER4��ؼĴ�����λ��ȱʡֵ
*��ڲ�����TIM4_TimerSelect  TIMER4�Ĵ�����ָ��TIMER4
*���ڲ�����void
**************************************************/
void TIM4_DeInit()
{
	TXINX = 0x04;    //TIMER4 ѡ��
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
*�������ƣ�void TIM4_PrescalerSelection(TIM4_PresSel_TypeDef TIM4_PrescalerSelection)
*�������ܣ�TIMER4 Ԥ��Ƶѡ��
*��ڲ�����TIM2_PrescalerSelection	Ԥ��Ƶѡ��
*���ڲ�����void
**************************************************/
void TIM4_PrescalerSelection(TIM4_PresSel_TypeDef TIM4_PrescalerSelection)
{
	TXINX = 0x04;
	if(TIM4_PrescalerSelection == TIM4_PRESSEL_FSYS_D12)
	{
		TXMOD &= 0X7F;
	}
	else if(TIM4_PrescalerSelection == TIM4_PRESSEL_FSYS_D1)
	{
		TXMOD |= 0X80;
	}	
}

/**************************************************
*�������ƣ�void TIM4_WorkMode1Config(uint16_t TIM4_SetCounter)
*�������ܣ�TIMER4����ģʽ1���ú���
*��ڲ�����uint16_t TIM4_SetCounter	���ü�����ֵ
*���ڲ�����void
**************************************************/
void TIM4_WorkMode1Config(uint16_t TIM4_SetCounter)
{	
	TXINX = 0x04;
	RCAPXL = TIM4_SetCounter % 256;
	RCAPXH = TIM4_SetCounter / 256;

	TLX = RCAPXL;
	THX = RCAPXH;
}
/*****************************************************
*�������ƣ�void TIM4_Cmd(FunctionalState NewState)
*�������ܣ�TIMER4���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void TIM4_Cmd(FunctionalState NewState)
{
	TXINX = 0x04;
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
*�������ƣ�void TIMX_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�TIMER4�жϳ�ʼ��
*��ڲ�����NewState	�ж�ʹ��/�ر�ѡ��
 		   Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void TIM4_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	TXINX = 0x04;
	if(NewState == DISABLE)
	{
   		IE1 &= 0X7F;
	}
	else
	{
   		IE1 |= 0X80;
	}
	if(Priority == LOW)
	{
		IP1 &= 0X7F;
	}
	else
	{
		IP1 |= 0X80;
	}

}

/*****************************************************
*�������ƣ�FlagStatus TIM4_GetFlagStatus(void)
*�������ܣ����TIMER4�жϱ�־״̬
*��ڲ�����void
*���ڲ�����FlagStatus	TIMER4�жϱ�־״̬	
*****************************************************/
FlagStatus TIM4_GetFlagStatus()
{	
	FlagStatus status = RESET;
	TXINX = 0x04;
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
*�������ƣ�void TIM4_ClearFlag(void)
*�������ܣ����TIMER4�жϱ�־״̬
*��ڲ�����void
*���ڲ�����void	
*****************************************************/
void TIM4_ClearFlag()
{
	TXINX = 0x04;
	TXCON &= 0x7f;
}

/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/