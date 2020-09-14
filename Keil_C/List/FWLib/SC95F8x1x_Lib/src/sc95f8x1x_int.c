//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_int.c
//	����		: 
//	ģ�鹦��	: INT�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_int.h"

/**************************************************
*�������ƣ�void INT_DeInit(INTx_Typedef INTx)
*�������ܣ�INTx��ؼĴ�����λ��ȱʡֵ
*��ڲ�����INTx		INTxѡ��
*���ڲ�����void
**************************************************/
void INT_DeInit(INTx_Typedef INTx)
{
	switch(INTx)
	{
		case INT0:
			INT0R = 0x00;
			INT0F = 0x00;
			IE &= (~0X01);
			IP &= ~0X01;
			TCON &= (~0X02);
			break;

		case INT1:
			INT1R = 0x00;
			INT1F = 0x00;
			IE &= (~0X04);
			IP &= ~0X04;
			TCON &= (~0X08);
			break;

		case INT2:
			INT2R = 0x00;
			INT2F = 0x00;
			IE1 &= (~0X08);
			IP1 &= ~0X08;
			break;

		default:
			break;
	}		
}

/**************************************************
*�������ƣ�void INT0_SetTriggerMode(uint8_t INT0x, INT_TriggerMode_Typedef TriggerMode)
*�������ܣ�INT0x�жϴ�����ʽ���ú���
*��ڲ�����INT0x		INT0xѡ��
		   TriggerMode	�жϴ�����ʽѡ��
*���ڲ�����void
**************************************************/
void INT0_SetTriggerMode(uint8_t INT0x, INT_TriggerMode_Typedef TriggerMode)
{
	switch(TriggerMode)
	{
		case INT_TRIGGER_RISE_ONLY:
			INT0R |= INT0x;
			INT0F &= (~INT0x);
			break;
		case INT_TRIGGER_FALL_ONLY:
			INT0R &= (~INT0x);
			INT0F |= INT0x;
			break;
		case INT_TRIGGER_RISE_FALL:
			INT0R |= INT0x;
			INT0F |= INT0x;
			break;
		case INT_TRIGGER_DISABLE:
			INT0R &= (~INT0x);
			INT0F &= (~INT0x); 
		default:
			break;
	}
}

/**************************************************
*�������ƣ�void INT1_SetTriggerMode(uint8_t INT1x, INT_TriggerMode_Typedef TriggerMode)
*�������ܣ�INT1x�жϴ�����ʽ���ú���
*��ڲ�����INT1x		INT1xѡ��
		   TriggerMode	�жϴ�����ʽѡ��
*���ڲ�����void
**************************************************/
void INT1_SetTriggerMode(uint8_t INT1x, INT_TriggerMode_Typedef TriggerMode)
{
	switch(TriggerMode)
	{
		case INT_TRIGGER_RISE_ONLY:
			INT1R |= INT1x;
			INT1F &= (~INT1x);
			break;
		case INT_TRIGGER_FALL_ONLY:
			INT1R &= (~INT1x);
			INT1F |= INT1x;
			break;
		case INT_TRIGGER_RISE_FALL:
			INT1R |= INT1x;
			INT1F |= INT1x;
			break;
		case INT_TRIGGER_DISABLE:
			INT1R &= (~INT1x);
			INT1F &= (~INT1x);
		default:
			break;
	}
}

/**************************************************
*�������ƣ�void INT2_SetTriggerMode(uint8_t INT2x, INT_TriggerMode_Typedef TriggerMode)
*�������ܣ�INT2x�жϴ�����ʽ���ú���
*��ڲ�����INT2x		INT2xѡ��
		   TriggerMode	�жϴ�����ʽѡ��
*���ڲ�����void
**************************************************/
void INT2_SetTriggerMode(uint8_t INT2x, INT_TriggerMode_Typedef TriggerMode)
{
	switch(TriggerMode)
	{
		case INT_TRIGGER_RISE_ONLY:
			INT2R |= INT2x;
			INT2F &= (~INT2x);
			break;
		case INT_TRIGGER_FALL_ONLY:
			INT2R &= (~INT2x);
			INT2F |= INT2x;
			break;
		case INT_TRIGGER_RISE_FALL:
			INT2R |= INT2x;
			INT2F |= INT2x;
			break;
		case INT_TRIGGER_DISABLE:
			INT2R &= (~INT2x);
			INT2F &= (~INT2x); 	
		default:
			break;
	}
}

/*****************************************************
*�������ƣ�void INT0_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�INT0�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void INT0_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{	
	if(NewState != DISABLE)
	{
		IE |= 0X01;
	}
	else
	{
		IE &= (~0X01);
	}

	if(Priority == LOW)
	{
		IP &= ~0X01;	
	}
	else
	{
		IP |= 0X01;	
	}		
}

/*****************************************************
*�������ƣ�void INT1_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�INT1�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void INT1_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{	
	if(NewState != DISABLE)
	{
		IE |= 0X04;
	}
	else
	{
		IE &= (~0X04);
	}

	if(Priority == LOW)
	{
		IP &= ~0X04;	
	}
	else
	{
		IP |= 0X04;	
	}		
}

/*****************************************************
*�������ƣ�void INT2_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�INT0�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void INT2_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{	
	if(NewState != DISABLE)
	{
		IE1 |= 0X08;
	}
	else
	{
		IE1 &= (~0X08);
	}

	if(Priority == LOW)
	{
		IP1 &= ~0X08;	
	}
	else
	{
		IP1 |= 0X08;	
	}		
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/

