//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_iap.h
//	作者		: 
//	模块功能	: IAP固件库函数头文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#ifndef _sc95f8x1x_IAP_H_
#define	_sc95f8x1x_IAP_H_

#include "sc95f8x1x.h"
#include "intrins.h"

typedef enum {
    IAP_MEMTYPE_ROM       = (uint8_t)0x00,    //IAP操作区域为ROM
    IAP_MEMTYPE_IFB       = (uint8_t)0x01,    //IAP操作区域为IFB
} IAP_MemType_TypeDef;

void IAP_DeInit(void);
void IAP_ProgramByte(uint16_t Address, uint8_t Data, IAP_MemType_TypeDef IAP_MemType, uint8_t WriteTimeLimit);
uint8_t IAP_ReadByte(uint16_t Address,IAP_MemType_TypeDef IAP_MemType);
void IAP_SectorErase(IAP_MemType_TypeDef IAP_MemType, uint16_t IAP_SectorEraseAddress, uint8_t WriteTimeLimit);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/