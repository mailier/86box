//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_CRC.h
//	����		: 
//	ģ�鹦��	: CRC�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_CRC_H_
#define	_sc95f8x1x_CRC_H_

#include "sc95f8x1x.h"

uint32_t CRC_All(void);//����IAP Rangeѡ�Ӳ��CRC����CODE���ݣ�����CRC���
uint32_t CRC_Frame(uint8_t* buff,uint8_t Length);//���CRC����buffָ����������CRC���㣬����CRC���

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/