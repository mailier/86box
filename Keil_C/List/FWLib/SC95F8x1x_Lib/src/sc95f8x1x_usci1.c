//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_usci1.c
//	����		: 
//	ģ�鹦��	: USCI1�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_usci1.h"

/**************************************************
*�������ƣ�void USCI1_DeInit(void)
*�������ܣ�USCI1��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI1_DeInit(void)
{
	OTCON &= 0X3F;
	US1CON0 = 0X00;
	US1CON1 = 0X00;
	US1CON2 = 0X00;
	US1CON3 = 0X00;
	IE2 &= (~0X01);
	IP2 &= (~0X01);			
}

/**************************************************
*�������ƣ�void USCI1_SPI_Init(USCI1_SPI_FirstBit_TypeDef FirstBit, USCI1_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,USCI1_SPI_Mode_TypeDef Mode,
							 USCI1_SPI_ClockPolarity_TypeDef ClockPolarity, USCI1_SPI_ClockPhase_TypeDef ClockPhase,USCI1_SPI_TXE_INT_TypeDef SPI_TXE_INT,USCI1_TransmissionMode_TypeDef TransmissionMode)
*�������ܣ�SPI��ʼ�����ú���
*��ڲ�����FirstBit				���ȴ���λѡ��MSB/LSB��
		   BaudRatePrescaler	SPIʱ��Ƶ��ѡ��
		   Mode					SPI����ģʽѡ��
		   ClockPolarity		SPIʱ�Ӽ���ѡ��
		   ClockPhase			SPIʱ����λѡ��
		   SPI_TXE_INT			���ͻ������ж�����ѡ��
		   TransmissionMode     SPI����ģʽѡ�� 8λ/16λ
*���ڲ�����void																								
**************************************************/
void USCI1_SPI_Init(USCI1_SPI_FirstBit_TypeDef FirstBit, USCI1_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, USCI1_SPI_Mode_TypeDef Mode,
				  USCI1_SPI_ClockPolarity_TypeDef ClockPolarity, USCI1_SPI_ClockPhase_TypeDef ClockPhase, USCI1_SPI_TXE_INT_TypeDef SPI_TXE_INT, USCI1_TransmissionMode_TypeDef TransmissionMode)
{
	OTCON = (OTCON & 0X3F) | 0X40;
	US1CON1 = US1CON1 & (~0X05) | FirstBit | SPI_TXE_INT | TransmissionMode;
	US1CON0 = US1CON0 & 0X80 | BaudRatePrescaler | Mode | ClockPolarity | ClockPhase;
}

/*****************************************************
*�������ƣ�void USCI1_SPI_Cmd(FunctionalState NewState)
*�������ܣ�SPI���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void USCI1_SPI_Cmd(FunctionalState NewState)
{
	OTCON = (OTCON & 0X3F) | 0X40;
	if(NewState != DISABLE)
	{
		US1CON0 |= 0X80;
	}	
	else
	{
		US1CON0 &= (~0X80);
	}	
}


/*****************************************************
*�������ƣ�void USCI1_SPI_SendData_8(uint8_t Data)
*�������ܣ�USCI1 SPI��������
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI1_SPI_SendData_8(uint8_t Data)
{
	US1CON2 = Data;
}

/*****************************************************
*�������ƣ�uint8_t USCI1_SPI_ReceiveData_8(void)
*�������ܣ����US1CON2�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t		
*****************************************************/
uint8_t USCI1_SPI_ReceiveData_8(void)
{
	return US1CON2;		
}

/*****************************************************
*�������ƣ�void USCI1_SPI_SendData_16(uint16_t Data)
*�������ܣ�US1CON2 SPI��������
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI1_SPI_SendData_16(uint16_t Data)
{
	US1CON3 = (uint8_t) (Data >> 8);
	US1CON2 = (uint8_t) Data;
}

/*****************************************************
*�������ƣ�uint16_t USCI1_SPI_ReceiveData_16(void)
*�������ܣ����US1CON2�е�ֵ
*��ڲ�����void
*���ڲ�����uint16_t		
*****************************************************/
uint16_t USCI1_SPI_ReceiveData_16(void)
{
	uint16_t SPI_data;
	SPI_data = (uint16_t)((US1CON3 << 8) |  US1CON2);
	return SPI_data;		
}

/**************************************************
*�������ƣ�void USCI1_TWI_Slave_Init(uint8_t TWI_Address)
*�������ܣ�USCI1 TWI �ӻ���ʼ�����ú���
*��ڲ�����TWI_Address	7λ�ӻ���ַ����			
*���ڲ�����void
**************************************************/
void USCI1_TWI_Slave_Init(uint8_t TWI_Address)
{
	OTCON = OTCON & 0X3F | 0X80;
	US1CON2 = TWI_Address<<1;		
}

/**************************************************
*�������ƣ�void USCI1_TWI_MasterCommunicationRate(USCI1_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate)
*�������ܣ�USCI1 TWI����ģʽ��ͨѶ�����趨
*��ڲ�����TWI_MasterCommunicationRate TWI����ģʽ��ͨѶ����
*���ڲ�����void
**************************************************/
void USCI1_TWI_MasterCommunicationRate(USCI1_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate)
{
	OTCON = OTCON & 0X3F | 0X80;		//ѡ��usci1ΪTWI
	US1CON1 |= TWI_MasterCommunicationRate;		
}

/**************************************************
*�������ƣ�void USCI1_TWI_Start(void)
*�������ܣ�USCI1 TWI ��ʼλ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI1_TWI_Start(void)
{
	US1CON1 |= 0x20;		
}

/**************************************************
*�������ƣ�void USCI1_TWI_MasterModeStop(void)
*�������ܣ�USCI1 TWI����ģʽֹͣλ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI1_TWI_MasterModeStop(void)
{
	US1CON1 |= 0x10;		
}

/**************************************************
*�������ƣ�void USCI1_TWI_SlaveClockExtension(FunctionalState NewState)
*�������ܣ�USCI1 TWI�ӻ�ģʽʱ���ӳ�����λ
*��ڲ�����FunctionalState NewState		����Ӧ��ʹ��/ʧ��ѡ��
*���ڲ�����void
**************************************************/
void USCI1_TWI_SlaveClockExtension(FunctionalState NewState)
{
	OTCON = OTCON & 0X3F | 0X80;
	if (NewState != DISABLE)
	{
		US1CON1 |= 0x40;	
	}
	else
	{
	  	US1CON1 &= 0XBF;
	}	
}

/**************************************************
*�������ƣ�void USCI1_TWI_AcknowledgeConfig(FunctionalState NewState)
*�������ܣ�TWI����Ӧ��ʹ�ܺ���
*��ڲ�����FunctionalState NewState		����Ӧ��ʹ��/ʧ��ѡ��			
*���ڲ�����void
**************************************************/
void USCI1_TWI_AcknowledgeConfig(FunctionalState NewState)
{
	OTCON = OTCON & 0X3F | 0X80;
	if (NewState != DISABLE)
	{
		US1CON0 |= 0X08;	
	}
	else
	{
	  	US1CON0 &= 0XF7;
	}
}

/**************************************************
*�������ƣ�void USCI1_TWI_GeneralCallCmd(FunctionalState NewState)
*�������ܣ�TWIͨ�õ�ַ��Ӧʹ�ܺ���
*��ڲ�����FunctionalState NewState		ͨ�õ�ַ��Ӧʹ��/ʧ��ѡ��			
*���ڲ�����void
**************************************************/
void USCI1_TWI_GeneralCallCmd(FunctionalState NewState)
{
	OTCON = OTCON & 0X3F | 0X80;
	if (NewState != DISABLE)
	{
		US1CON2 |= 0X01;	
	}
	else
	{
	  	US1CON2 &= 0XFE;
	}	
}

/*****************************************************
*�������ƣ�void USCI1_TWI_Cmd(FunctionalState NewState)
*�������ܣ�TWI���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void USCI1_TWI_Cmd(FunctionalState NewState)
{
	OTCON = OTCON & 0X3F | 0X80;
	if(NewState != DISABLE)
	{
		US1CON0 |= 0X80;	
	}
	else
	{
		US1CON0 &= (~0X80);
	}
}

/*****************************************************
*�������ƣ�void USCI1_TWI_SendData(uint8_t Data)
*�������ܣ�TWI��������
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI1_TWI_SendData(uint8_t Data)
{
	US1CON3 = Data;	
}

/*****************************************************
*�������ƣ�uint8_t USCI1_TWI_SendData(void)
*�������ܣ����US1CON3�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t	
*****************************************************/
uint8_t USCI1_TWI_ReceiveData(void)
{
	return US1CON3;
}

/**************************************************
*�������ƣ�void USCI1_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI1_UART_Mode_TypeDef Mode, USCI1_UART_RX_TypeDef RxMode)
*�������ܣ�UART��ʼ�����ú���
*��ڲ�����UARTFsys	ϵͳʱ��Ƶ��
		   BaudRate		������
		   Mode			UART1����ģʽ
		   RxMode		��������ѡ��
*���ڲ�����void
**************************************************/
void USCI1_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI1_UART_Mode_TypeDef Mode, USCI1_UART_RX_TypeDef RxMode) 
{
	OTCON |= 0xC0;
	US1CON0 = US1CON0 & 0X0F | Mode | RxMode;
	if(Mode == USCI1_UART_Mode_8B)
	{
		if(BaudRate == USCI1_UART_BaudRate_FsysDIV12)
		{
			US1CON0 &= 0XDF;		
		}
		else if(BaudRate == USCI1_UART_BaudRate_FsysDIV4)
		{
			US1CON0 |= 0X20;		
		}
	}
	else
	{
		US1CON2 = UARTFsys / BaudRate / 256;
		US1CON1 = UARTFsys / BaudRate % 256;	
	}
}

/*****************************************************
*�������ƣ�void USCI1_UART_SendData8(uint8_t Data)
*�������ܣ�USCI1 UART����8λ����
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI1_UART_SendData8(uint8_t Data)
{
   US1CON3 = Data;
}

/*****************************************************
*�������ƣ�uint8_t USCI1_UART_ReceiveData8(void)
*�������ܣ����US1CON3�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t		
*****************************************************/
uint8_t USCI1_UART_ReceiveData8(void)
{
	return US1CON3;
}

/*****************************************************
*�������ƣ�void USCI1_UART_SendData9(uint16_t Data)
*�������ܣ�UART����9λ����
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI1_UART_SendData9(uint16_t Data)
{
	uint8_t Data_9Bit;
	Data_9Bit = (Data>>8);
	if(Data_9Bit)
	{
		US1CON0	|= 0x08;
	}
	else
	{
		US1CON0	&= 0xf7;
	}
	
	US1CON3 = (uint8_t)Data;
}

/*****************************************************
*�������ƣ�uint16_t USCI1_UART_ReceiveData9(void)
*�������ܣ����US1CON3�е�ֵ���ھ�λ��ֵ
*��ڲ�����void
*���ڲ�����uint16_t		
*****************************************************/
uint16_t USCI1_UART_ReceiveData9(void)
{
	uint16_t Data9;
	Data9 =  US1CON3 + ((uint16_t)(US1CON0&0X04)<<6);
	US1CON0 &= 0XFB;
	return Data9;
}

/*****************************************************
*�������ƣ�void USCI1_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�USCI1�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void USCI1_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
    if(NewState != DISABLE)
    {
       IE2 |= 0x01;
    }
    else
    {
       IE2 &= 0xFE;
    }
/************************************************************/
	if(Priority != LOW)
	{
		IP2 |= 0x01;
	}
	else
	{
		IP2 &= 0xFE;
	}
}

/*****************************************************
*�������ƣ�FlagStatus USCI1_GetFlagStatus(USCI1_Flag_TypeDef USCI1_FLAG)
*�������ܣ����USCI1��־״̬
*��ڲ�����USCI1_FLAG		�����ȡ�ı�־λ
*���ڲ�����FlagStatus    	USCI1��־״̬	
*****************************************************/
FlagStatus USCI1_GetFlagStatus(USCI1_Flag_TypeDef USCI1_FLAG)
{
	FlagStatus bitstatus = RESET;

	if((USCI1_FLAG==USCI1_SPI_FLAG_SPIF) || (USCI1_FLAG==USCI1_SPI_FLAG_WCOL) || (USCI1_FLAG==USCI1_SPI_FLAG_TXE))
	{
		if((USCI1_FLAG & US1CON1) != (uint8_t)RESET)
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
		if((USCI1_FLAG & US1CON0) != (uint8_t)RESET)
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
*�������ƣ�void USCI1_ClearFlag(USCI1_Flag_TypeDef USCI1_FLAG)
*�������ܣ����USCI1��־״̬
*��ڲ�����USCI1_FLAG		��������ı�־λ
*���ڲ�����void	
*****************************************************/
void USCI1_ClearFlag(USCI1_Flag_TypeDef USCI1_FLAG)
{
	if((USCI1_FLAG==USCI1_SPI_FLAG_SPIF) || (USCI1_FLAG==USCI1_SPI_FLAG_WCOL) || (USCI1_FLAG==USCI1_SPI_FLAG_TXE))
	{
		US1CON1 &= (~USCI1_FLAG);
	}
	else
	{
		US1CON0 &= (~USCI1_FLAG);
	}
}

/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/