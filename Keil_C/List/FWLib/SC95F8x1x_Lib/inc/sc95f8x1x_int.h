//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_INT.h
//	����		: 
//	ģ�鹦��	: INT�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_INT_H_
#define	_sc95f8x1x_INT_H_

#include "sc95f8x1x.h"

typedef enum {
  INT_TRIGGER_RISE_ONLY = (uint8_t)0x01,	//�ⲿ�жϴ�����ʽΪ������
  INT_TRIGGER_FALL_ONLY = (uint8_t)0x02,	//�ⲿ�жϴ�����ʽΪ�½���
  INT_TRIGGER_RISE_FALL = (uint8_t)0x03,	//�ⲿ�жϴ�����ʽΪ���������½���
  INT_TRIGGER_DISABLE   = (uint8_t)0x04	//�ر��ⲿ�жϴ���
}INT_TriggerMode_Typedef;

typedef enum {
  INT0 = (uint8_t)0x00,			//�ⲿ�ж�0
  INT1 = (uint8_t)0x01,			//�ⲿ�ж�1
  INT2 = (uint8_t)0x02			//�ⲿ�ж�2
}INTx_Typedef;

typedef enum {
  INT04 = (uint8_t)0x10,		//��P04����Ϊ�ⲿ�жϽ�
  INT05 = (uint8_t)0x20,		//��P05����Ϊ�ⲿ�жϽ�
  INT06 = (uint8_t)0x40,	 	//��P06����Ϊ�ⲿ�жϽ�
  INT07 = (uint8_t)0x80			//��P07����Ϊ�ⲿ�жϽ�
}INT0x_Typedef;

typedef enum {
  INT10 = (uint8_t)0x01,		//��P40����Ϊ�ⲿ�жϽ�
  INT11 = (uint8_t)0x02,		//��P41����Ϊ�ⲿ�жϽ�
  INT12 = (uint8_t)0x04,		//��P42����Ϊ�ⲿ�жϽ�
  INT13 = (uint8_t)0x08,		//��P43����Ϊ�ⲿ�жϽ�
  INT14 = (uint8_t)0x10,		//��P14����Ϊ�ⲿ�жϽ�
  INT15 = (uint8_t)0x20,		//��P15����Ϊ�ⲿ�жϽ�
  INT16 = (uint8_t)0x40,		//��P16����Ϊ�ⲿ�жϽ�
  INT17 = (uint8_t)0x80 		//��P17����Ϊ�ⲿ�жϽ�
}INT1x_Typedef;

typedef enum {
  INT20 = (uint8_t)0x01,		//��P20����Ϊ�ⲿ�жϽ�
  INT21 = (uint8_t)0x02,		//��P21����Ϊ�ⲿ�жϽ�
  INT22 = (uint8_t)0x04,		//��P22����Ϊ�ⲿ�жϽ�
  INT23 = (uint8_t)0x08 		//��P23����Ϊ�ⲿ�жϽ�
}INT2x_Typedef;

void INT_DeInit(INTx_Typedef INTx);
void INT0_SetTriggerMode(uint8_t INT0x, INT_TriggerMode_Typedef TriggerMode);
void INT1_SetTriggerMode(uint8_t INT1x, INT_TriggerMode_Typedef TriggerMode);
void INT2_SetTriggerMode(uint8_t INT2x, INT_TriggerMode_Typedef TriggerMode);
void INT0_ITConfig(FunctionalState NewState, PriorityStatus Priority);
void INT1_ITConfig(FunctionalState NewState, PriorityStatus Priority);
void INT2_ITConfig(FunctionalState NewState, PriorityStatus Priority);
#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/