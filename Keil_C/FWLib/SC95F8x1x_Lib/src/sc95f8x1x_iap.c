//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_iap.c
//	����		: 
//	ģ�鹦��	: IAP�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_iap.h"

/**************************************************
*�������ƣ�void IAP_DeInit(void)
*�������ܣ�IAP��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void IAP_DeInit(void)
{
	IAPKEY = 0X00;
	IAPADL = 0X00;
	IAPADH = 0X00;
	IAPADE = 0X00;
	IAPDAT = 0X00;
	IAPCTL = 0X00;	
}

/**************************************************
*�������ƣ�void IAP_ProgramByte(uint16_t Address, uint8_t Data, IAP_MemType_TypeDef IAP_MemType, uint8_t WriteTimeLimit)
*�������ܣ�IAPд��һ���ֽ�
*��ڲ�����Address			IAP������ַ
		   Data	   			д�������
		   IAP_MemType  	IAP��������ROM��IFB��
		   WriteTimeLimit	IAP����ʱ��	(ֵ����ڵ���0x40)
*���ڲ�����void
**************************************************/
void IAP_ProgramByte(uint16_t Address, uint8_t Data, IAP_MemType_TypeDef IAP_MemType, uint8_t WriteTimeLimit)
{
	BitStatus tmpbit;
	tmpbit = (BitStatus)EA;
	if(tmpbit != RESET)
	{
		disableInterrupts();
	}
	
	IAPADE = IAP_MemType;
	IAPDAT = Data;
	IAPADH = (uint8_t)(Address >> 8);
	IAPADL = (uint8_t)Address; 
	IAPKEY = WriteTimeLimit;
	IAPCTL = 0x10;
	IAPCTL |= 0x02;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
    _nop_();
	_nop_();
	_nop_();
	_nop_();
	IAPADE = IAP_MEMTYPE_ROM;

	if(tmpbit != RESET)
	{
		enableInterrupts();
	}		
}

/**************************************************
*�������ƣ�uint8_t IAP_ReadByte(uint16_t Address, IAP_MemType_TypeDef IAP_MemType)
*�������ܣ�IAP��һ���ֽ�
*��ڲ�����Address			IAP������ַ
		   FLASH_MemType	IAP��������ROM��IFB��
*���ڲ�����uint8_t			�������ֽ�����
**************************************************/
uint8_t IAP_ReadByte(uint16_t Address,IAP_MemType_TypeDef IAP_MemType)
{
	uint8_t tmpbyte;
	BitStatus tmpbit;
	tmpbit = (BitStatus)EA;
	if(tmpbit != RESET)
	{
		disableInterrupts();
	}

	IAPADE = IAP_MemType;
	tmpbyte = *((uint8_t code*)Address);
 	IAPADE = IAP_MEMTYPE_ROM;

	if(tmpbit != RESET)
	{
		enableInterrupts();
	}
	return tmpbyte;	
}

/**************************************************
*�������ƣ�void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_SectorEraseAddress)
*�������ܣ�IAP��������
*��ڲ�����IAP_MemType		IAP��������ROM��IFB��
		   IAP_SectorEraseAddress  IAP��������Ŀ���ַ
		   WriteTimeLimit	IAP����ʱ��	(ֵ����ڵ���0x40)
*���ڲ�����void
**************************************************/
void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_SectorEraseAddress, uint8_t WriteTimeLimit)
{
	IAPADE = IAP_MemType;
	IAPADH = (uint8_t)(IAP_SectorEraseAddress >> 8);  //����IAPĿ���ַ��λֵ
	IAPADL = (uint8_t)IAP_SectorEraseAddress; 		  //����IAPĿ���ַ��λֵ
	IAPKEY = WriteTimeLimit;
	IAPCTL = 0x20;
	IAPCTL |= 0x02;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
    _nop_();
	_nop_();
	_nop_();
	_nop_();
	IAPADE = IAP_MEMTYPE_ROM; 
}


/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/