//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_iap.c
//	作者		: 
//	模块功能	: IAP固件库函数C文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#include "sc95f8x1x_iap.h"

/**************************************************
*函数名称：void IAP_DeInit(void)
*函数功能：IAP相关寄存器复位至缺省值
*入口参数：void
*出口参数：void
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
*函数名称：void IAP_ProgramByte(uint16_t Address, uint8_t Data, IAP_MemType_TypeDef IAP_MemType, uint8_t WriteTimeLimit)
*函数功能：IAP写入一个字节
*入口参数：Address			IAP操作地址
		   Data	   			写入的数据
		   IAP_MemType  	IAP操作对象（ROM、IFB）
		   WriteTimeLimit	IAP操作时限	(值需大于等于0x40)
*出口参数：void
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
*函数名称：uint8_t IAP_ReadByte(uint16_t Address, IAP_MemType_TypeDef IAP_MemType)
*函数功能：IAP读一个字节
*入口参数：Address			IAP操作地址
		   FLASH_MemType	IAP操作对象（ROM、IFB）
*出口参数：uint8_t			读到的字节数据
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
*函数名称：void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_SectorEraseAddress)
*函数功能：IAP扇区擦除
*入口参数：IAP_MemType		IAP操作对象（ROM、IFB）
		   IAP_SectorEraseAddress  IAP扇区擦除目标地址
		   WriteTimeLimit	IAP操作时限	(值需大于等于0x40)
*出口参数：void
**************************************************/
void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_SectorEraseAddress, uint8_t WriteTimeLimit)
{
	IAPADE = IAP_MemType;
	IAPADH = (uint8_t)(IAP_SectorEraseAddress >> 8);  //擦除IAP目标地址高位值
	IAPADL = (uint8_t)IAP_SectorEraseAddress; 		  //擦除IAP目标地址低位值
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