//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_iap.h
//	����		: 
//	ģ�鹦��	: IAP�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_IAP_H_
#define	_sc95f8x1x_IAP_H_

#include "sc95f8x1x.h"
#include "intrins.h"

typedef enum {
    IAP_MEMTYPE_ROM       = (uint8_t)0x00,    //IAP��������ΪROM
    IAP_MEMTYPE_IFB       = (uint8_t)0x01,    //IAP��������ΪIFB
} IAP_MemType_TypeDef;

void IAP_DeInit(void);
void IAP_ProgramByte(uint16_t Address, uint8_t Data, IAP_MemType_TypeDef IAP_MemType, uint8_t WriteTimeLimit);
uint8_t IAP_ReadByte(uint16_t Address,IAP_MemType_TypeDef IAP_MemType);
void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_SectorEraseAddress, uint8_t WriteTimeLimit);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/