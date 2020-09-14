//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_gpio.c
//	����		: 
//	ģ�鹦��	: GPIO�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_gpio.h"

/**************************************************
*�������ƣ�void GPIO_DeInit(void)
*�������ܣ�GPIO��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void GPIO_DeInit(void)
{
	P0CON = 0x00;
	P1CON = 0x00;
	P2CON = 0x00;
	P3CON = 0x00;
	P4CON = 0x00;
	P5CON = 0x00;
	P0PH = 0x00;
	P1PH = 0x00;
	P2PH = 0x00;
	P3PH = 0x00;
	P4PH = 0x00;
	P5PH = 0x00;
	P0 = P1 = P2 = P3 = P4 = P5 = 0;
}

/**************************************************
*�������ƣ�void GPIO_Init(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins, GPIO_Mode_TypeDef GPIO_Mode)
*�������ܣ�GPIO��ģʽ���ó�ʼ��
*��ڲ�����GPIOx		ѡ�������GPIO��
		   PortPins		ѡ��GPIO�ܽ�Pxy
		   GPIO_Mode	ѡ��GPIO��ģʽ���������롢�������롢���������
*���ڲ�����void
**************************************************/
void GPIO_Init(GPIO_TypeDef GPIOx, uint8_t PortPins, GPIO_Mode_TypeDef GPIO_Mode)
{
	if(GPIOx == GPIO0)
	{
		if(GPIO_Mode == GPIO_MODE_IN_HI)
		{
			P0CON &= ~PortPins;
			P0PH  &= ~PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_IN_PU)
		{
			P0CON &= ~PortPins;
			P0PH  |= PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_OUT_PP)
		{
			P0CON |= PortPins;
		}		
	}
	else if(GPIOx == GPIO1)
	{
		if(GPIO_Mode == GPIO_MODE_IN_HI)
		{
			P1CON &= ~PortPins;
			P1PH  &= ~PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_IN_PU)
		{
			P1CON &= ~PortPins;
			P1PH  |= PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_OUT_PP)
		{
			P1CON |= PortPins;
		}	
	}
	else if(GPIOx == GPIO2)
	{
		if(GPIO_Mode == GPIO_MODE_IN_HI)
		{
			P2CON &= ~PortPins;
			P2PH  &= ~PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_IN_PU)
		{
			P2CON &= ~PortPins;
			P2PH  |= PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_OUT_PP)
		{
			P2CON |= PortPins;
		}	
	}
	else if(GPIOx == GPIO3)
	{
		if(GPIO_Mode == GPIO_MODE_IN_HI)
		{
			P3CON &= ~PortPins;
			P3PH  &= ~PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_IN_PU)
		{
			P3CON &= ~PortPins;
			P3PH  |= PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_OUT_PP)
		{
			P3CON |= PortPins;
		}	
	}
	else if(GPIOx == GPIO4)
	{
		if(GPIO_Mode == GPIO_MODE_IN_HI)
		{
			P4CON &= ~PortPins;
			P4PH  &= ~PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_IN_PU)
		{
			P4CON &= ~PortPins;
			P4PH  |= PortPins;
		}
		if(GPIO_Mode == GPIO_MODE_OUT_PP)
		{
			P4CON |= PortPins;
		}	
	}
	else
	{
		if(GPIOx == GPIO5)
		{
			if(GPIO_Mode == GPIO_MODE_IN_HI)
			{
				P5CON &= ~PortPins;
				P5PH  &= ~PortPins;
			}
			if(GPIO_Mode == GPIO_MODE_IN_PU)
			{
				P5CON &= ~PortPins;
				P5PH  |= PortPins;
			}
			if(GPIO_Mode == GPIO_MODE_OUT_PP)
			{
				P5CON |= PortPins;
			}		
		}
	}
}

/**************************************************
*�������ƣ�void GPIO_Write(GPIO_TypeDef GPIOx, uint8_t PortVal)
*�������ܣ�GPIO�ڸ�ֵ
*��ڲ�����GPIOx	ѡ�������GPIO��
		   PortVal  GPIO�ڵ�ֵ
*���ڲ�����void
**************************************************/
void GPIO_Write(GPIO_TypeDef GPIOx, uint8_t PortVal)
{
    if(GPIOx == GPIO0)
	{
		P0 = PortVal;
	}
	if(GPIOx == GPIO1)
	{
		P1 = PortVal;
	}
	if(GPIOx == GPIO2)
	{ 
		P2 = PortVal;
	}
	if(GPIOx == GPIO3)
	{ 
		P3 = PortVal;
	}
	if(GPIOx == GPIO4)
	{ 
		P4 = PortVal;
	}
	if(GPIOx == GPIO5)
	{ 
		P5 = PortVal;
	}
}

/**************************************************
*�������ƣ�void GPIO_WriteHigh(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins)
*�������ܣ�GPIO�ڹܽ�Pxy��λ
*��ڲ�����GPIOx		ѡ�������GPIO��
		   PortPins		ѡ��GPIO�ڹܽ�Pxy
*���ڲ�����void
**************************************************/
void GPIO_WriteHigh(GPIO_TypeDef GPIOx, uint8_t PortPins)
{
	if(GPIOx == GPIO0)
	{
		P0 |= PortPins;
	}
	if(GPIOx == GPIO1)
	{
		P1 |= PortPins;
	}
	if(GPIOx == GPIO2)
	{   
		P2 |= PortPins;	
	} 
	if(GPIOx == GPIO3)
	{   
		P3 |= PortPins;	
	} 
	if(GPIOx == GPIO4)
	{   
		P4 |= PortPins;	
	} 
	if(GPIOx == GPIO5)
	{   
		P5 |= PortPins;	
	}    
}

/**************************************************
*�������ƣ�void GPIO_WriteLow(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins)
*�������ܣ�GPIO�ڹܽ�Pxy��λ
*��ڲ�����GPIOx		ѡ�������GPIO��
		   PortPins		ѡ��GPIO�ڹܽ�Pxy
*���ڲ�����void
**************************************************/
void GPIO_WriteLow(GPIO_TypeDef GPIOx, uint8_t PortPins)
{
	if(GPIOx == GPIO0)
	{
		P0 &= ~PortPins;
	}
	if(GPIOx == GPIO1)
	{
		P1 &= ~PortPins;
	}
	if(GPIOx == GPIO2)
	{   
		P2 &= ~PortPins;	
	} 
	if(GPIOx == GPIO3)
	{   
		P3 &= ~PortPins;	
	} 
	if(GPIOx == GPIO4)
	{   
		P4 &= ~PortPins;
	} 
	if(GPIOx == GPIO5)
	{   
		P5 &= ~PortPins;	
	}  
}

/**************************************************
*�������ƣ�uint8_t GPIO_ReadPort(GPIO_TypeDef GPIOx)
*�������ܣ���GPIO��Px��ֵ
*��ڲ�����GPIOx	ѡ�������GPIO��
*���ڲ�����uint8_t	����Px��ֵ
**************************************************/
uint8_t GPIO_ReadPort(GPIO_TypeDef GPIOx)
{
    if(GPIOx == GPIO0)
	{
		return P0;
	}
	else if(GPIOx == GPIO1)
	{
		return P1;
	}
	else if(GPIOx == GPIO2)
	{
		return P2;
	}
	else if(GPIOx == GPIO3)
	{
		return P3;
	}
	else if(GPIOx == GPIO4)
	{
		return P4;
	}
	else 
	{
		return P5;
	}
}

/**************************************************
*�������ƣ�BitStatus GPIO_ReadPin(GPIO_TypeDef GPIOx, uint8_t PortPins)
*�������ܣ���GPIO�ڹܽ�Pxy��ֵ
*��ڲ�����GPIOx		ѡ�������GPIO��
		   PortPins		ѡ��GPIO�ڹܽ�Pxy
*���ڲ�����BitStatus	����Pxy��ֵ
**************************************************/
uint8_t GPIO_ReadPin(GPIO_TypeDef GPIOx, uint8_t PortPins)
{
	if(GPIOx == GPIO0)
	{
		return (P0 & PortPins);
	}
	else if(GPIOx == GPIO1)
	{
		return (P1 & PortPins);
	}
	else if(GPIOx == GPIO2)
	{
		return (P2 & PortPins);
	}
	else if(GPIOx == GPIO3)
	{
		return (P3 & PortPins);
	}
	else if(GPIOx == GPIO4)
	{
		return (P4 & PortPins);
	}
	else
	{
		return (P5 & PortPins);	
	}				  
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/