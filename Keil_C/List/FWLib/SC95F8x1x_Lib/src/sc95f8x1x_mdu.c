//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_mdu.c
//	����		: 
//	ģ�鹦��	: MDU�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_mdu.h"

/**************************************************
*�������ƣ�void MDU_DeInit(void)
*�������ܣ�MDU��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void MDU_DeInit(void)
{
	OPERCON &= 0X3F;
	EXA0 = 0X00;
	EXA1 = 0X00;
	EXA2 = 0X00;
	EXA3 = 0X00;
	EXBL = 0X00;
	EXBH = 0X00;
}

/**************************************************
*�������ƣ�void MDU_MultiplicationConfig(uint16_t Multiplicand, uint16_t Multiplier)
*�������ܣ�MDU�˷��������ú���
*��ڲ�����Multiplicand		������
		   Multiplier		����
*���ڲ�����void
**************************************************/
void MDU_MultiplicationConfig(uint16_t Multiplicand,uint16_t Multiplier)
{
	OPERCON &= 0XBF;	
	EXBL = Multiplier ;
	EXBH = Multiplier >> 8;
	EXA0 = Multiplicand ;
	EXA1 = Multiplicand >> 8;
}

/**************************************************
*�������ƣ�void MDU_DivisionConfig(uint32_t Dividend, uint16_t Divisor)
*�������ܣ�MDU�����������ú���
*��ڲ�����Dividend		������
		   Divisor		����
*���ڲ�����void
**************************************************/
void MDU_DivisionConfig(uint32_t Dividend,uint16_t Divisor)
{
	MDU_Temp_Union MDU_DivisionTemp;
	MDU_DivisionTemp.MDU_Temp = Dividend;

	OPERCON |= 0X40;
	EXA0 = MDU_DivisionTemp.MDU_EXAxReg.MDU_EXA0Reg;
	EXA1 = MDU_DivisionTemp.MDU_EXAxReg.MDU_EXA1Reg;
	EXA2 = MDU_DivisionTemp.MDU_EXAxReg.MDU_EXA2Reg;
	EXA3 = MDU_DivisionTemp.MDU_EXAxReg.MDU_EXA3Reg;
	EXBL = Divisor;
	EXBH = Divisor >> 8;
}

/**************************************************
*�������ƣ�void MDU_StartOperation(void)
*�������ܣ�MDU����һ������
*��ڲ�����void	
*���ڲ�����void
**************************************************/
void MDU_StartOperation(void)
{
	OPERCON |= 0x80;
	while(OPERCON & 0x80);
}

/**************************************************
*�������ƣ�uint32_t MDU_GetProduct(void)
*�������ܣ���ȡ�˻�
*��ڲ�����void	
*���ڲ�����uint32_t		�˻�
**************************************************/
uint32_t MDU_GetProduct(void)
{
	MDU_Temp_Union MDU_ProductTemp;
	MDU_ProductTemp.MDU_EXAxReg.MDU_EXA0Reg = EXA0;
	MDU_ProductTemp.MDU_EXAxReg.MDU_EXA1Reg = EXA1;
	MDU_ProductTemp.MDU_EXAxReg.MDU_EXA2Reg = EXA2;
	MDU_ProductTemp.MDU_EXAxReg.MDU_EXA3Reg = EXA3;
	return MDU_ProductTemp.MDU_Temp;
}

/**************************************************
*�������ƣ�uint32_t MDU_GetQuotient(void)
*�������ܣ���ȡ��
*��ڲ�����void	
*���ڲ�����uint32_t		��
**************************************************/
uint32_t MDU_GetQuotient(void)
{
	MDU_Temp_Union MDU_QuotientTemp;
	MDU_QuotientTemp.MDU_EXAxReg.MDU_EXA0Reg = EXA0;
	MDU_QuotientTemp.MDU_EXAxReg.MDU_EXA1Reg = EXA1;
	MDU_QuotientTemp.MDU_EXAxReg.MDU_EXA2Reg = EXA2;
	MDU_QuotientTemp.MDU_EXAxReg.MDU_EXA3Reg = EXA3;
	return MDU_QuotientTemp.MDU_Temp;
}

/**************************************************
*�������ƣ�uint16_t MDU_GetRemainder(void)
*�������ܣ���ȡ����
*��ڲ�����void	
*���ڲ�����uint16_t		����
**************************************************/
uint16_t MDU_GetRemainder(void)
{
	uint16_t MDU_RemainderTemp;
	MDU_RemainderTemp = EXBH*256+ EXBL;
	return MDU_RemainderTemp;
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/