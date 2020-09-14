//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_uart0.c
//	����		: 
//	ģ�鹦��	: UART0�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_uart0.h"

/**************************************************
*�������ƣ�void UART0_DeInit(void)
*�������ܣ�UART0��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void UART0_DeInit(void)
{
 	SCON = 0X00;
	SBUF = 0X00;
	PCON &= 0X7F;
	IE &= 0XEF;
	IP &= 0XEF;	
}

/**************************************************
*�������ƣ�void UART0_Init(uint32_t Uart0Fsys, uint32_t BaudRate, UART0_Mode_Typedef Mode,
						   UART0_Clock_Typedef ClockMode, UART0_RX_Typedef RxMode)
*�������ܣ�UART0��ʼ�����ú���
*��ڲ�����Uart0Fsys	ϵͳʱ��Ƶ��
		   BaudRate		������
		   Mode			UART0����ģʽ
		   ClockMode	������ʱ��Դ��TIMER1/TIMER2��
		   RxMode		��������ѡ��
*���ڲ�����void
**************************************************/
void UART0_Init(uint32_t Uart0Fsys, uint32_t BaudRate, UART0_Mode_Typedef Mode,
			   UART0_Clock_Typedef ClockMode, UART0_RX_Typedef RxMode)
{
	SCON  = SCON & 0X2F | Mode | RxMode;	//����UART����ģʽ,���ý�������λ
	
	if(Mode == UART0_Mode_8B)
	{
		if(BaudRate == UART0_BaudRate_FsysDIV12)
		{
			SCON &= 0XDF;		
		}
		else if(BaudRate == UART0_BaudRate_FsysDIV4)
		{
			SCON |= 0X20;		
		}
	}
	else
	{				
		TXCON = (TXCON & 0xCF) | ClockMode;		//���ò�����ʱ��Դ	
		if(ClockMode == UART0_CLOCK_TIMER1)
		{
			TH1 = (Uart0Fsys / BaudRate) / 256;
			TL1 = (Uart0Fsys / BaudRate) % 256;
			TR1 = 0;
		}
		else if(ClockMode == UART0_CLOCK_TIMER2)
		{
			RCAPXH = (Uart0Fsys / BaudRate) / 256;
			RCAPXL = (Uart0Fsys / BaudRate) % 256;
		}
	}
}

/*****************************************************
*�������ƣ�void UART0_SendData8(uint8_t Data)
*�������ܣ�UART0����8λ����
*��ڲ�����uint8_t Data		���͵����� 
*���ڲ�����void
*****************************************************/
void UART0_SendData8(uint8_t Data)
{
   SBUF = Data;
}

/**************************************************
*�������ƣ�uint8_t UART0_ReceiveData8(void)
*�������ܣ����SBUF�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t
**************************************************/
uint8_t UART0_ReceiveData8(void)
{
	return SBUF;
}

/*****************************************************
*�������ƣ�void UART0_SendData9(uint16_t Data)
*�������ܣ�UART0����9λ����
*��ڲ�����uint16_t Data	���͵����� 
*���ڲ�����void
*****************************************************/
void UART0_SendData9(uint16_t Data)
{
	uint8_t Data_9Bit;
	Data_9Bit = (Data >> 8);
	if(Data_9Bit)
	{
		SCON |= 0X08;		
	}
	else
	{
		SCON &= 0XF7;
	}
	SBUF = (uint8_t)Data;		
}

/**************************************************
*�������ƣ�uint16_t UART0_ReceiveData9(void)
*�������ܣ����SBUF�е�ֵ���ھ�λ��ֵ
*��ڲ�����void
*���ڲ�����uint16_t
**************************************************/
uint16_t UART0_ReceiveData9(void)
{
	uint16_t Data9;
	Data9 =  SBUF + ((uint16_t)(SCON&0X04)<<6);
	SCON &= 0XFB;
	return Data9;
}

/*****************************************************
*�������ƣ�void UART0_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�UART0�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void UART0_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	if(NewState == DISABLE)
    {
       EUART = 0;
    }
    else
    {
       EUART = 1;
    }
	//�����ж����ȼ�
	if(Priority == LOW)
	{
		IPUART = 0;
	}
	else
	{
		IPUART = 1;
	}
}

/*****************************************************
*�������ƣ�FlagStatus UART0_GetFlagStatus(UART0_Flag_Typedef UART0_Flag)
*�������ܣ����UART0�жϱ�־״̬
*��ڲ�����UART0_Flag	�жϱ�־λѡ��
*���ڲ�����FlagStatus		UART0�жϱ�־״̬	
*****************************************************/
FlagStatus UART0_GetFlagStatus(UART0_Flag_Typedef UART0_Flag)
{
	return (FlagStatus)(SCON & UART0_Flag);
}

/*****************************************************
*�������ƣ�void UART0_ClearFlag(UART0_Flag_Typedef UART0_Flag)
*�������ܣ����UART0�жϱ�־״̬
*��ڲ�����UART0_Flag	�жϱ�־λѡ��
*���ڲ�����void	
*****************************************************/
void UART0_ClearFlag(UART0_Flag_Typedef UART0_Flag)
{
	SCON &=	(~UART0_Flag);
}

 