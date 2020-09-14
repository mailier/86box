//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_usci2.c
//	����		: 
//	ģ�鹦��	: USCI2�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_usci2.h"

/**************************************************
*�������ƣ�void USCI2_DeInit(void)
*�������ܣ�USCI2��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI2_DeInit(void)
{
	TMCON &= 0X3F;
	US2CON0 = 0X00;
	US2CON1 = 0X00;
	US2CON2 = 0X00;
	US2CON3 = 0X00;
	IE2 &= (~0X02);
	IP2 &= (~0X02);			
}

/**************************************************
*�������ƣ�void USCI2_SPI_Init(USCI2_SPI_FirstBit_TypeDef FirstBit, USCI2_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,USCI2_SPI_Mode_TypeDef Mode,
							 USCI2_SPI_ClockPolarity_TypeDef ClockPolarity, USCI2_SPI_ClockPhase_TypeDef ClockPhase,USCI2_SPI_TXE_INT_TypeDef SPI_TXE_INT,USCI2_TransmissionMode_TypeDef TransmissionMode)
*�������ܣ�SPI��ʼ�����ú���
*��ڲ�����FirstBit				���ȴ���λѡ��MSB/LSB��
		   BaudRatePrescaler	SPIʱ��Ƶ��ѡ��
		   Mode					SPI����ģʽѡ��
		   ClockPolarity		SPIʱ�Ӽ���ѡ��
		   ClockPhase			SPIʱ����λѡ��
		   SPI_TXE_INT			���ͻ������ж�����ѡ��
		   TransmissionMode		SPI����ģʽѡ�� 8/16eλ
*���ڲ�����void																								
**************************************************/
void USCI2_SPI_Init(USCI2_SPI_FirstBit_TypeDef FirstBit, USCI2_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, USCI2_SPI_Mode_TypeDef Mode,
				  USCI2_SPI_ClockPolarity_TypeDef ClockPolarity, USCI2_SPI_ClockPhase_TypeDef ClockPhase, USCI2_SPI_TXE_INT_TypeDef SPI_TXE_INT,USCI2_TransmissionMode_TypeDef TransmissionMode)
{
	TMCON = (TMCON & 0X3F) | 0X40;
	US2CON1 = US2CON1 & (~0X05) | FirstBit | SPI_TXE_INT | TransmissionMode;
	US2CON0 = US2CON0 & 0X80 | BaudRatePrescaler | Mode | ClockPolarity | ClockPhase;
}

/*****************************************************
*�������ƣ�void USCI2_SPI_Cmd(FunctionalState NewState)
*�������ܣ�SPI���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void USCI2_SPI_Cmd(FunctionalState NewState)
{
	TMCON = (TMCON & 0X3F) | 0X40;
	if(NewState != DISABLE)
	{
		US2CON0 |= 0X80;
	}	
	else
	{
		US2CON0 &= (~0X80);
	}	
}

/*****************************************************
*�������ƣ�void USCI2_SPI_SendData_8(uint8_t Data)
*�������ܣ�USCI2 SPI��������
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI2_SPI_SendData_8(uint8_t Data)
{
	US2CON2 = Data;
}

/*****************************************************
*�������ƣ�uint8_t USCI2_SPI_ReceiveData_8(void)
*�������ܣ����US2CON2�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t		
*****************************************************/
uint8_t USCI2_SPI_ReceiveData_8(void)
{
	return US2CON2;		
}

/*****************************************************
*�������ƣ�void USCI2_SPI_SendData_16(uint16_t Data)
*�������ܣ�US2CON2 SPI��������
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI2_SPI_SendData_16(uint16_t Data)
{
	US2CON3 = (uint8_t) (Data >> 8);
	US2CON2 = (uint8_t) Data;
}

/*****************************************************
*�������ƣ�uint16_t USCI2_SPI_ReceiveData_16(void)
*�������ܣ����US2CON2�е�ֵ
*��ڲ�����void
*���ڲ�����uint16_t		
*****************************************************/
uint16_t USCI2_SPI_ReceiveData_16(void)
{
	uint16_t SPI_data;
	SPI_data = (uint16_t)((US2CON3 << 8) |  US2CON2);
	return SPI_data;		
}

/**************************************************
*�������ƣ�void USCI2_TWI_Slave_Init(uint8_t TWI_Address)
*�������ܣ�USCI2 TWI �ӻ���ʼ�����ú���
*��ڲ�����TWI_Address	7λ�ӻ���ַ����			
*���ڲ�����void
**************************************************/
void USCI2_TWI_Slave_Init(uint8_t TWI_Address)
{
	TMCON = TMCON & 0X3F | 0X80;
	US2CON2 = TWI_Address<<1;		
}

/**************************************************
*�������ƣ�void USCI2_TWI_MasterCommunicationRate(USCI2_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate)
*�������ܣ�USCI2 TWI����ģʽ��ͨѶ�����趨
*��ڲ�����TWI_MasterCommunicationRate TWI����ģʽ��ͨѶ����
*���ڲ�����void
**************************************************/
void USCI2_TWI_MasterCommunicationRate(USCI2_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate)
{
	TMCON = TMCON & 0X3F | 0X80;		//ѡ��usci2ΪTWI

	US2CON1 = TWI_MasterCommunicationRate;		
}

/**************************************************
*�������ƣ�void USCI2_TWI_Start(void)
*�������ܣ�USCI2 TWI ��ʼλ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI2_TWI_Start(void)
{
	US2CON1 |= 0x20;		
}

/**************************************************
*�������ƣ�void USCI2_TWI_MasterModeStop(void)
*�������ܣ�USCI2 TWI����ģʽֹͣλ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI2_TWI_MasterModeStop(void)
{
	US2CON1 |= 0x10;		
}

/**************************************************
*�������ƣ�void USCI2_TWI_SlaveClockExtension(void)
*�������ܣ�USCI2 TWI�ӻ�ģʽʱ���ӳ�����λ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI2_TWI_SlaveClockExtension(FunctionalState NewState)
{
	TMCON = TMCON & 0X3F | 0X80;
	if (NewState != DISABLE)
	{
		US2CON1 |= 0x40;	
	}
	else
	{
	  	US2CON1 &= 0XBF;
	}	
}

/**************************************************
*�������ƣ�void USCI2_TWI_AcknowledgeConfig(FunctionalState NewState)
*�������ܣ�TWI����Ӧ��ʹ�ܺ���
*��ڲ�����FunctionalState NewState		����Ӧ��ʹ��/ʧ��ѡ��			
*���ڲ�����void
**************************************************/
void USCI2_TWI_AcknowledgeConfig(FunctionalState NewState)
{
	TMCON = TMCON & 0X3F | 0X80;
	if (NewState != DISABLE)
	{
		US2CON0 |= 0X08;	
	}
	else
	{
	  	US2CON0 &= 0XF7;
	}
}

/**************************************************
*�������ƣ�void USCI2_TWI_GeneralCallCmd(FunctionalState NewState)
*�������ܣ�TWIͨ�õ�ַ��Ӧʹ�ܺ���
*��ڲ�����FunctionalState NewState		ͨ�õ�ַ��Ӧʹ��/ʧ��ѡ��			
*���ڲ�����void
**************************************************/
void USCI2_TWI_GeneralCallCmd(FunctionalState NewState)
{
	TMCON = TMCON & 0X3F | 0X80;
	if (NewState != DISABLE)
	{
		US2CON2 |= 0X01;	
	}
	else
	{
	  	US2CON2 &= 0XFE;
	}	
}

/*****************************************************
*�������ƣ�void USCI2_TWI_Cmd(FunctionalState NewState)
*�������ܣ�TWI���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void USCI2_TWI_Cmd(FunctionalState NewState)
{
	TMCON = TMCON & 0X3F | 0X80;
	if(NewState != DISABLE)
	{
		US2CON0 |= 0X80;	
	}
	else
	{
		US2CON0 &= (~0X80);
	}
}

/*****************************************************
*�������ƣ�void USCI2_TWI_SendData(uint8_t Data)
*�������ܣ�TWI��������
*��ڲ�����Data		���͵�����/��ַ
*���ڲ�����void
*****************************************************/
void USCI2_TWI_SendData(uint8_t Data)
{
	US2CON3 = Data;	
}

/*****************************************************
*�������ƣ�uint8_t USCI2_TWI_SendData(void)
*�������ܣ����US2CON3�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t	
*****************************************************/
uint8_t USCI2_TWI_ReceiveData(void)
{
	return US2CON3;
}

/**************************************************
*�������ƣ�void USCI2_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI2_UART_Mode_TypeDef Mode, USCI2_UART_RX_TypeDef RxMode)
*�������ܣ�UART��ʼ�����ú���
*��ڲ�����UARTFsys	ϵͳʱ��Ƶ��
		   BaudRate		������
		   Mode			UART1����ģʽ
		   RxMode		��������ѡ��
*���ڲ�����void
**************************************************/
void USCI2_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI2_UART_Mode_TypeDef Mode, USCI2_UART_RX_TypeDef RxMode) 
{
	TMCON |= 0xC0;
	US2CON0 = US2CON0 & 0X0F | Mode | RxMode;
	if(Mode == USCI2_UART_Mode_8B)
	{
		if(BaudRate == USCI2_UART_BaudRate_FsysDIV12)
		{
			US2CON0 &= 0XDF;		
		}
		else if(BaudRate == USCI2_UART_BaudRate_FsysDIV4)
		{
			US2CON0 |= 0X20;		
		}
	}
	else
	{
		US2CON2 = UARTFsys / BaudRate / 256;
		US2CON1 = UARTFsys / BaudRate % 256;	
	}
}

/*****************************************************
*�������ƣ�void USCI2_UART_SendData8(uint8_t Data)
*�������ܣ�USCI2 UART1����8λ����
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI2_UART_SendData8(uint8_t Data)
{
   US2CON3 = Data;
}

/*****************************************************
*�������ƣ�uint8_t USCI2_UART_ReceiveData8(void)
*�������ܣ����US2CON3�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t		
*****************************************************/
uint8_t USCI2_UART_ReceiveData8(void)
{
	return US2CON3;
}

/*****************************************************
*�������ƣ�void USCI2_UART_SendData9(uint16_t Data)
*�������ܣ�UART����9λ����
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI2_UART_SendData9(uint16_t Data)
{
	uint8_t Data_9Bit;
	Data_9Bit = (Data>>8);
	if(Data_9Bit)
	{
		US2CON0	|= 0x08;
	}
	else
	{
		US2CON0	&= 0xf7;
	}
	
	US2CON3 = (uint8_t)Data;
}

/*****************************************************
*�������ƣ�uint16_t USCI2_UART_ReceiveData9(void)
*�������ܣ����US2CON3�е�ֵ���ھ�λ��ֵ
*��ڲ�����void
*���ڲ�����uint16_t		
*****************************************************/
uint16_t USCI2_UART_ReceiveData9(void)
{
	uint16_t Data9;
	Data9 =  US2CON3 + ((uint16_t)(US2CON0&0X04)<<6);
	return Data9;
}

/*****************************************************
*�������ƣ�void USCI2_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�USCI2�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void USCI2_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
    if(NewState != DISABLE)
    {
       IE2 |= 0x02;
    }
    else
    {
       IE2 &= 0xFD;
    }
/************************************************************/
	if(Priority != LOW)
	{
		IP2 |= 0x02;
	}
	else
	{
		IP2 &= 0xFD;
	}
}

/*****************************************************
*�������ƣ�FlagStatus USCI2_GetFlagStatus(USCI2_Flag_TypeDef USCI2_FLAG)
*�������ܣ����USCI2��־״̬
*��ڲ�����USCI2_FLAG		�����ȡ�ı�־λ
*���ڲ�����FlagStatus    	USCI2��־״̬	
*****************************************************/
FlagStatus USCI2_GetFlagStatus(USCI2_Flag_TypeDef USCI2_FLAG)
{
	FlagStatus bitstatus = RESET;

	if((USCI2_FLAG==USCI2_SPI_FLAG_SPIF) || (USCI2_FLAG==USCI2_SPI_FLAG_WCOL) || (USCI2_FLAG==USCI2_SPI_FLAG_TXE))
	{
		if((USCI2_FLAG & US2CON1) != (uint8_t)RESET)
		{
			bitstatus = SET; 			
		}
		else
		{	
			bitstatus = RESET;
		}
	}
	else
	{
		if((USCI2_FLAG & US2CON0) != (uint8_t)RESET)
		{
			bitstatus = SET; 			
		}
		else
		{	
			bitstatus = RESET;
		}
	}
	
	return bitstatus;
}

/*****************************************************
*�������ƣ�void USCI2_ClearFlag(USCI2_Flag_TypeDef USCI2_FLAG)
*�������ܣ����USCI2��־״̬
*��ڲ�����USCI2_FLAG		��������ı�־λ
*���ڲ�����void	
*****************************************************/
void USCI2_ClearFlag(USCI2_Flag_TypeDef USCI2_FLAG)
{
	if((USCI2_FLAG==USCI2_SPI_FLAG_SPIF) || (USCI2_FLAG==USCI2_SPI_FLAG_WCOL) || (USCI2_FLAG==USCI2_SPI_FLAG_TXE))
	{
		US2CON1 &= (~USCI2_FLAG);
	}
	else
	{
		US2CON0 &= (~USCI2_FLAG);
	}
}

/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/


			   
               




