//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_btm.c
//	����		: 
//	ģ�鹦��	: BTM�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_btm.h"

/**************************************************
*�������ƣ�void BTM_DeInit(void)
*�������ܣ�BTM��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void BTM_DeInit(void)
{
	BTMCON = 0x00;	
}

/**************************************************
*�������ƣ�void BTM_Init(BTM_Timebase_TypeDef BTM_Timebase)
*�������ܣ�BTM��ʼ�����ú���
*��ڲ�����BTM_Timebase		BTM���ʱ��ѡ��
*���ڲ�����void
**************************************************/
void BTM_Init(BTM_Timebase_TypeDef BTM_Timebase)
{
	BTMCON = (BTMCON & 0xF0) | BTM_Timebase;
}

/*****************************************************
*�������ƣ�void BTM_Cmd(FunctionalState NewState)
*�������ܣ�BTM���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void BTM_Cmd(FunctionalState NewState)
{
	if(NewState == DISABLE)
	{
		BTMCON &= 0x7f;	
	}
	else
	{
		BTMCON |= 0x80;
	}
}

/*****************************************************
*�������ƣ�void BTM_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�BTM�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void BTM_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	//�ж�ʹ������
	if(NewState == DISABLE)
    {
       IE1 &= 0xfb;		
    }
    else
    {
       IE1 |= 0x04;		
    }

	//�ж����ȼ�����
	if(Priority == LOW)
	{
		IP1 &= 0xfb;	
	}
	else
	{
		IP1 |= 0x04;	
	}	
}

/*****************************************************
*�������ƣ�FlagStatus BTM_GetFlagStatus(void)
*�������ܣ����BTM�жϱ�־״̬
*��ڲ�����void
*���ڲ�����FlagStatus	BTM�жϱ�־״̬	
*****************************************************/
FlagStatus BTM_GetFlagStatus(void)
{
	return (FlagStatus)(BTMCON & 0x40);
}

/*****************************************************
*�������ƣ�void BTM_ClearFlag(void)
*�������ܣ����BTM�жϱ�־״̬
*��ڲ�����void
*���ڲ�����void	
*****************************************************/
void BTM_ClearFlag(void)
{
	BTMCON &= 0xbf;
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/