//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_timerx.c
//	����		: 
//	ģ�鹦��	: TIMER2�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2020/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_timer2.h"

/**************************************************
*�������ƣ�void TIM2_DeInit(void)
*�������ܣ�TIMER2
*��ڲ�����void
*���ڲ�����void
**************************************************/
void TIM2_DeInit()
{
	TXINX = 0x02;    //TIMER2ѡ��
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
*�������ƣ�void TIM2_PrescalerSelection(TIM2_PresSel_TypeDef TIM2_PrescalerSelection)
*�������ܣ�TIMER2 Ԥ��Ƶѡ��
*��ڲ�����TIM2_PrescalerSelection	Ԥ��Ƶѡ��
*���ڲ�����void
**************************************************/
void TIM2_PrescalerSelection(TIM2_PresSel_TypeDef TIM2_PrescalerSelection)
{
	TXINX = 0x02;
	if(TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D12)
	{
		TXMOD &= 0X7F;
	}
	else if(TIM2_PrescalerSelection == TIM2_PRESSEL_FSYS_D1)
	{
		TXMOD |= 0X80;
	}	
}

/**************************************************
*�������ƣ�void TIM2_TimeBaseInit(TIM2_CountMode_TypeDef TIM2_CountMode, TIM2_CountDirection_TypeDef TIM2_CountDirection)
*�������ܣ�TIM2�����������ú���
*��ڲ�����
		   TIM2_CountMode			����/��ʱģʽѡ��
		   TIM2_CountDirection		��������ѡ��
*���ڲ�����void
**************************************************/
void TIM2_TimeBaseInit(TIM2_CountMode_TypeDef TIM2_CountMode, TIM2_CountDirection_TypeDef TIM2_CountDirection)
{	
	TXINX = 0x02;
	if(TIM2_CountMode == TIM2_MODE_TIMER)
	{
		TXCON &= 0XFD;
	}
	else if(TIM2_CountMode == TIM2_MODE_COUNTER)
	{
		TXCON |= 0X02;
	}
/************************************************************/
	if(TIM2_CountDirection == TIM2_COUNTDIRECTION_UP)
	{
		TXMOD &= 0XFE;
	}
	else if(TIM2_CountDirection == TIM2_COUNTDIRECTION_DOWN_UP)
	{
		TXMOD |= 0X01;
	} 			
}

/**************************************************
*�������ƣ�void TIM2_WorkMode0Config(uint16_t TIM2_SetCounter)
*�������ܣ�TIMER2����ģʽ0���ú���
*��ڲ�����uint16_t TIM2_SetCounter	���ü�����ֵ
*���ڲ�����void
**************************************************/
void TIM2_WorkMode0Config(uint16_t TIM2_SetCounter)
{
	TXINX = 0x02;
	TXCON = 0x0D;

	TLX = TIM2_SetCounter % 256;
	THX = TIM2_SetCounter / 256;	
}

/**************************************************
*�������ƣ�void TIM2_WorkMode1Config(uint16_t TIM2_SetCounter)
*�������ܣ�TIMER2����ģʽ1���ú���
*��ڲ�����uint16_t TIM2_SetCounter	���ü�����ֵ
*���ڲ�����void
**************************************************/
void TIM2_WorkMode1Config(uint16_t TIM2_SetCounter)
{	
	TXINX = 0x02;
	RCAPXL = TIM2_SetCounter % 256;
	RCAPXH = TIM2_SetCounter / 256;

	TLX = RCAPXL;
	THX = RCAPXH;
}

/**************************************************
*�������ƣ�void TIM2_WorkMode3Config(uint16_t TIM2_SetCounter)
*�������ܣ�TIMER2����ģʽ3���ú���
*��ڲ�����uint16_t TIM2_SetCounter		���ü�����ֵ
*���ڲ�����void
**************************************************/
void TIM2_WorkMode3Config(uint16_t TIM2_SetCounter)
{
	TXINX = 0x02;
	RCAPXL = TIM2_SetCounter % 256;
	RCAPXH = TIM2_SetCounter / 256;
	TXMOD |= 0X02;			
}
/**************************************************
*�������ƣ�void TIM2_WorkModeConfig(TIM2_WorkMode_TypeDef TIM2_WorkMode, uint16_t TIM2_SetCounter)
*�������ܣ�TIMER2����ģʽ���ú���
*��ڲ�����TIM2_WorkMode_TypeDef TIM2_WorkMode 	TIMER2����ģʽѡ��
		   uint16_t TIM2_SetCounter	        	TIMER2������ֵ����	
*���ڲ�����void
**************************************************/
void TIM2_WorkModeConfig(TIM2_WorkMode_TypeDef TIM2_WorkMode, uint16_t TIM2_SetCounter)
{	
	switch (TIM2_WorkMode)
	{
		case TIM2_WORK_MODE0:
			TIM2_WorkMode0Config(TIM2_SetCounter);
		break;

		case TIM2_WORK_MODE1:
			TIM2_WorkMode1Config(TIM2_SetCounter);
		break;

		case TIM2_WORK_MODE3:
			TIM2_WorkMode3Config(TIM2_SetCounter);
		break;

		default:
		break;
	}		
}
/*****************************************************
*�������ƣ�void TIM2_SetEXEN2(FunctionalState NewState)
*�������ܣ�TIMER2_EXEN2���ú���
*��ڲ�����FunctionalState NewState		EXEN2ʹ��ѡ��
*���ڲ�����void
*****************************************************/
void TIM2_SetEXEN2(FunctionalState NewState)
{
	TXINX = 0x02;
	if (NewState == DISABLE)
    {
       EXENX = 0;
    }
    else
    {
       EXENX = 1;
    }
}

/*****************************************************
*�������ƣ�void TIM2_Cmd(FunctionalState NewState)
*�������ܣ�TIMER2���ܿ��غ���
*��ڲ�����NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void TIM2_Cmd(FunctionalState NewState)
{
	TXINX = 0x02;
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
*�������ƣ�void TIM2_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�TIMER2
*��ڲ�����NewState	�ж�ʹ��/�ر�ѡ��
 		   Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void TIM2_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	TXINX = 0x02;
	if(NewState == DISABLE)
	{
   		ET2 = 0;
	}
	else
	{
   		ET2 = 1;
	}
	if(Priority == LOW)
	{
		IPT2 = 0;
	}
	else
	{
		IPT2 = 1;
	}
}

/*****************************************************
*�������ƣ�FlagStatus TIM2_GetFlagStatus(void)
*�������ܣ����TIMER2�жϱ�־״̬
*��ڲ�����TIM2_Flag  		TIMER2��־ѡ��
*���ڲ�����FlagStatus	    TIMER2�жϱ�־״̬	
*****************************************************/
FlagStatus TIM2_GetFlagStatus(TIM2_Flag_TypeDef TIM2_Flag)
{	
	FlagStatus status = RESET;
	TXINX = 0x02;
	if((TIM2_Flag & TXCON) != (uint8_t)RESET)
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
*�������ƣ�void TIMX_ClearFlag(void)
*�������ܣ����TIMER2�жϱ�־״̬
*��ڲ�����TIM2_Flag   TIMER2��־ѡ��
*���ڲ�����void	
*****************************************************/
void TIM2_ClearFlag(TIM2_Flag_TypeDef TIM2_Flag)
{
	TXINX = 0x02;
	TXCON &= (~TIM2_Flag);
}

/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/