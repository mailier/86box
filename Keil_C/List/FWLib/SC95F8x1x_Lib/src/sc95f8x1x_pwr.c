//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_pwr.c
//	����		: 
//	ģ�鹦��	: PWR�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************
#include "sc95f8x1x_pwr.h"
#define	DELAY_TIME	7
unsigned char xdata FirstIntFlag = 0;//�Ƿ��ǻ��Ѻ��һ�ν����жϣ�0����1����
unsigned char xdata OpregTemp = 0;
/**************************************************
*�������ƣ�void SinOne_SleepDelay(void)
*�������ܣ����Ѻ���ʱ
*��ڲ�����DelayTime	���Ѻ����ʱ����
*���ڲ�����void
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
*�������ƣ�void PWR_DeInit(void)
*�������ܣ�PWR��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void PWR_DeInit(void)
{
	PCON &= 0XFC;
}

/**************************************************
*�������ƣ�void PWR_EnterSTOPMode(void)
*�������ܣ�MCU����STOPģʽ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void PWR_EnterSTOPMode(void)
{
	FirstIntFlag = 1;
	EA = 0;					//��ֹ�������ж��������OPINX��OPREG
	OPINX = 0xC1;
	OpregTemp = OPREG&0x30;	//���浱ǰ��Ƶ��Ƶ���
	OPREG |= 0X30;			//����Ƶ�������Ƶ�ʡ�
	EA = 1;					//�ָ��ж�
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	PCON |= 0X02;			//����Stop
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
*�������ƣ�void PWR_EnterSTOPMode(void)
*�������ܣ�MCU�˳�STOPģʽ���ڻ����жϷ��������ʼ���øú����Ա�֤�����˳�STOPģʽ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void PWR_ExitSTOPMode(void)
{
	if(FirstIntFlag)			//ֻ�л��Ѻ�ĵ�һ�ν����ж�ʱ��ִ��
	{
		PWR_SleepDelay(DELAY_TIME);//���Ѻ��ʵ���ʱ
		EA = 0;					//��ֹ�������ж��������OPINX��OPREG
		OPINX = 0xC1;
		OPREG &= 0xCF;
		OPREG |= OpregTemp;		//��ԭԭ������Ƶ
		EA = 1;					//�ָ��ж�
		FirstIntFlag = 0;
	}		
}
/**************************************************
*�������ƣ�void PWR_EnterIDLEMode(void)
*�������ܣ�MCU����IDLEģʽ
*��ڲ�����void
*���ڲ�����void
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