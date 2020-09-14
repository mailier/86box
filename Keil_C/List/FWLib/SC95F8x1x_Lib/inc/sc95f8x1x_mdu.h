//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_mdu.h
//	作者		: 
//	模块功能	: MDU固件库函数头文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#ifndef _sc95f8x1x_MDU_H_
#define	_sc95f8x1x_MDU_H_

#include "sc95f8x1x.h"

typedef struct 
{
	uint8_t MDU_EXA3Reg;	 //EXA3寄存器
	uint8_t MDU_EXA2Reg;	 //EXA2寄存器
	uint8_t MDU_EXA1Reg;	 //EXA1寄存器
	uint8_t MDU_EXA0Reg;	 //EXA0寄存器
} MDU_EXAxReg_Typedef;

typedef union
{
	MDU_EXAxReg_Typedef MDU_EXAxReg;
	uint32_t MDU_Temp;	
} MDU_Temp_Union;

void MDU_DeInit(void);
void MDU_MultiplicationConfig(uint16_t Multiplicand,uint16_t Multiplier);
void MDU_DivisionConfig(uint32_t Dividend,uint16_t Divisor);
void MDU_StartOperation(void);
uint32_t MDU_GetProduct(void);
uint32_t MDU_GetQuotient(void);
uint16_t MDU_GetRemainder(void);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/