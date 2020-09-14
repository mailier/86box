//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_pwr.c
//	作者		: 
//	模块功能	: PWR固件库函数C文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************
#include "sc95f8x1x_pwr.h"
#define	DELAY_TIME	7
unsigned char xdata FirstIntFlag = 0;//是否是唤醒后第一次进入中断，0：否；1：是
unsigned char xdata OpregTemp = 0;
/**************************************************
*函数名称：void SinOne_SleepDelay(void)
*函数功能：唤醒后延时
*入口参数：DelayTime	唤醒后的延时长度
*出口参数：void
**************************************************/
void PWR_SleepDelay(unsigned int DelayTime)
{
	unsigned int i=0;
	for(i=0;i<DelayTime;i++)
	{
		_nop_();
	}
}
/**************************************************
*函数名称：void PWR_DeInit(void)
*函数功能：PWR相关寄存器复位至缺省值
*入口参数：void
*出口参数：void
**************************************************/
void PWR_DeInit(void)
{
	PCON &= 0XFC;
}

/**************************************************
*函数名称：void PWR_EnterSTOPMode(void)
*函数功能：MCU进入STOP模式
*入口参数：void
*出口参数：void
**************************************************/
void PWR_EnterSTOPMode(void)
{
	FirstIntFlag = 1;
	EA = 0;					//防止发生的中断里操作了OPINX和OPREG
	OPINX = 0xC1;
	OpregTemp = OPREG&0x30;	//保存当前主频分频情况
	OPREG |= 0X30;			//将主频调到最低频率。
	EA = 1;					//恢复中断
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	PCON |= 0X02;			//进入Stop
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();		
}
/**************************************************
*函数名称：void PWR_EnterSTOPMode(void)
*函数功能：MCU退出STOP模式，在唤醒中断服务函数的最开始调用该函数以保证正常退出STOP模式
*入口参数：void
*出口参数：void
**************************************************/
void PWR_ExitSTOPMode(void)
{
	if(FirstIntFlag)			//只有唤醒后的第一次进入中断时才执行
	{
		PWR_SleepDelay(DELAY_TIME);//唤醒后适当延时
		EA = 0;					//防止发生的中断里操作了OPINX和OPREG
		OPINX = 0xC1;
		OPREG &= 0xCF;
		OPREG |= OpregTemp;		//还原原来的主频
		EA = 1;					//恢复中断
		FirstIntFlag = 0;
	}		
}
/**************************************************
*函数名称：void PWR_EnterIDLEMode(void)
*函数功能：MCU进入IDLE模式
*入口参数：void
*出口参数：void
**************************************************/
void PWR_EnterIDLEMode(void)
{
	PCON |= 0X01;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();		
}
/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/