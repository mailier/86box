//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_usci0.c
//	����		: 
//	ģ�鹦��	: USCI0�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_usci0.h"

/**************************************************
*�������ƣ�void USCI0_DeInit(void)
*�������ܣ�USCI0��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI0_DeInit(void)
{
	OTCON &= 0XCF;
	US0CON0 = 0X00;
	US0CON1 = 0X00;
	US0CON2 = 0X00;
	US0CON3 = 0X00;
	IE1 &= (~0X01);
	IP1 &= (~0X01);			
}

/**************************************************
*�������ƣ�void USCI0_SPI_Init(USCI0_SPI_FirstBit_TypeDef FirstBit, USCI0_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,USCI0_SPI_Mode_TypeDef Mode,
							 USCI0_SPI_ClockPolarity_TypeDef ClockPolarity, USCI0_SPI_ClockPhase_TypeDef ClockPhase,USCI0_SPI_TXE_INT_TypeDef SPI_TXE_INT,USCI0_TransmissionMode_TypeDef TransmissionMode)
*�������ܣ�SPI��ʼ�����ú���
*��ڲ�����FirstBit				���ȴ���λѡ��MSB/LSB��
		   BaudRatePrescaler	SPIʱ��Ƶ��ѡ��
		   Mode					SPI����ģʽѡ��
		   ClockPolarity		SPIʱ�Ӽ���ѡ��
		   ClockPhase			SPIʱ����λѡ��
		   SPI_TXE_INT			���ͻ������ж�����ѡ��
		   TransmissionMode     SPI����ģʽѡ�� 8/16λ
*���ڲ�����void																								
**************************************************/
void USCI0_SPI_Init(USCI0_SPI_FirstBit_TypeDef FirstBit, USCI0_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, USCI0_SPI_Mode_TypeDef Mode,
				  USCI0_SPI_ClockPolarity_TypeDef ClockPolarity, USCI0_SPI_ClockPhase_TypeDef ClockPhase, USCI0_SPI_TXE_INT_TypeDef SPI_TXE_INT,USCI0_TransmissionMode_TypeDef TransmissionMode)
{
	OTCON = (OTCON & 0XCF) | 0X10;
	US0CON1 = US0CON1 & (~0X05) | FirstBit | SPI_TXE_INT | TransmissionMode;
	US0CON0 = US0CON0 & 0X80 | BaudRatePrescaler | Mode | ClockPolarity | ClockPhase;
}

/*****************************************************
*�������ƣ�void USCI0_SPI_Cmd(FunctionalState NewState)
*�������ܣ�SPI���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void USCI0_SPI_Cmd(FunctionalState NewState)
{
	OTCON = (OTCON & 0XCF) | 0X10;
	if(NewState != DISABLE)
	{
		US0CON0 |= 0X80;
	}	
	else
	{
		US0CON0 &= (~0X80);
	}	
}
/*****************************************************
*�������ƣ�void USCI0_SPI_SendData_8(uint8_t Data)
*�������ܣ�USCI0 SPI��������
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI0_SPI_SendData_8(uint8_t Data)
{
	US0CON2 = Data;
}

/*****************************************************
*�������ƣ�uint8_t USCI0_SPI_ReceiveData_8(void)
*�������ܣ����US0CON2�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t		
*****************************************************/
uint8_t USCI0_SPI_ReceiveData_8(void)
{
	return US0CON2;		
}

/*****************************************************
*�������ƣ�void USCI0_SPI_SendData_16(uint16_t Data)
*�������ܣ�US0CON2 SPI��������
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI0_SPI_SendData_16(uint16_t Data)
{
	US0CON3 = (uint8_t) (Data >> 8);
	US0CON2 = (uint8_t) Data;
}

/*****************************************************
*�������ƣ�uint16_t USCI0_SPI_ReceiveData_16(void)
*�������ܣ����US0CON2�е�ֵ
*��ڲ�����void
*���ڲ�����uint16_t		
*****************************************************/
uint16_t USCI0_SPI_ReceiveData_16(void)
{
	uint16_t SPI_data;
	SPI_data = (uint16_t)((US0CON3 << 8) |  US0CON2);
	return SPI_data;		
}

/**************************************************
*�������ƣ�void USCI0_TWI_Slave_Init(uint8_t TWI_Address)
*�������ܣ�USCI0 TWI�ӻ���ʼ�����ú���
*��ڲ�����TWI_Address	7λ�ӻ���ַ����			
*���ڲ�����void
**************************************************/
void USCI0_TWI_Slave_Init(uint8_t TWI_Address)
{
	OTCON = OTCON & 0XCF | 0X20;
	US0CON2 = TWI_Address<<1;		
}

/**************************************************
*�������ƣ�void USCI0_TWI_MasterCommunicationRate(USCI0_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate)
*�������ܣ�USCI0 TWI����ģʽ��ͨѶ�����趨
*��ڲ�����TWI_MasterCommunicationRate TWI����ģʽ��ͨѶ����
*���ڲ�����void
**************************************************/
void USCI0_TWI_MasterCommunicationRate(USCI0_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate)
{
	OTCON = OTCON & 0XCF | 0X20;
	US0CON1 |= TWI_MasterCommunicationRate;		
}

/**************************************************
*�������ƣ�void USCI0_TWI_Start(void)
*�������ܣ�USCI0 TWI ��ʼλ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI0_TWI_Start(void)
{
	US0CON1 |= 0x20;		
}

/**************************************************
*�������ƣ�void USCI0_TWI_MasterModeStop(void)
*�������ܣ�USCI0 TWI����ģʽֹͣλ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI0_TWI_MasterModeStop(void)
{
	US0CON1 |= 0x10;		
}

/**************************************************
*�������ƣ�void USCI0_TWI_SlaveClockExtension(void)
*�������ܣ�USCI0 TWI�ӻ�ģʽʱ���ӳ�����λ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void USCI0_TWI_SlaveClockExtension(FunctionalState NewState)
{
	OTCON = OTCON & 0XCF | 0X20;
	if (NewState != DISABLE)
	{
		US0CON1 |= 0x40;	
	}
	else
	{
	  	US0CON1 &= 0XBF;
	}		
}

/**************************************************
*�������ƣ�void USCI0_TWI_AcknowledgeConfig(FunctionalState NewState)
*�������ܣ�TWI����Ӧ��ʹ�ܺ���
*��ڲ�����FunctionalState NewState		����Ӧ��ʹ��/ʧ��ѡ��			
*���ڲ�����void
**************************************************/
void USCI0_TWI_AcknowledgeConfig(FunctionalState NewState)
{
	OTCON = OTCON & 0XCF | 0X20;
	if (NewState != DISABLE)
	{
		US0CON0 |= 0X08;	
	}
	else
	{
	  	US0CON0 &= 0XF7;
	}
}

/**************************************************
*�������ƣ�void USCI0_TWI_GeneralCallCmd(FunctionalState NewState)
*�������ܣ�TWIͨ�õ�ַ��Ӧʹ�ܺ���
*��ڲ�����FunctionalState NewState		ͨ�õ�ַ��Ӧʹ��/ʧ��ѡ��			
*���ڲ�����void
**************************************************/
void USCI0_TWI_GeneralCallCmd(FunctionalState NewState)
{
	OTCON = OTCON & 0XCF | 0X20;
	if (NewState != DISABLE)
	{
		US0CON2 |= 0X01;	
	}
	else
	{
	  	US0CON2 &= 0XFE;
	}	
}

/*****************************************************
*�������ƣ�void USCI0_TWI_Cmd(FunctionalState NewState)
*�������ܣ�TWI���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void USCI0_TWI_Cmd(FunctionalState NewState)
{
	OTCON = OTCON & 0XCF | 0X20;
	if(NewState != DISABLE)
	{
		US0CON0 |= 0X80;	
	}
	else
	{
		US0CON0 &= (~0X80);
	}
}

/*****************************************************
*�������ƣ�void USCI0_TWI_SendData(uint8_t Data)
*�������ܣ�TWI��������
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI0_TWI_SendData(uint8_t Data)
{
	US0CON3 = Data;	
}

/*****************************************************
*�������ƣ�uint8_t USCI0_TWI_SendData(void)
*�������ܣ����US0CON3�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t	
*****************************************************/
uint8_t USCI0_TWI_ReceiveData(void)
{
	return US0CON3;
}

/**************************************************
*�������ƣ�void USCI0_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI0_UART_Mode_TypeDef Mode, USCI0_UART_RX_TypeDef RxMode)
*�������ܣ�UART��ʼ�����ú���
*��ڲ�����UARTFsys	ϵͳʱ��Ƶ��
		   BaudRate		������
		   Mode			UART1����ģʽ
		   RxMode		��������ѡ��
*���ڲ�����void
**************************************************/
void USCI0_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI0_UART_Mode_TypeDef Mode, USCI0_UART_RX_TypeDef RxMode) 
{
	OTCON |= 0x30;
	US0CON0 = US0CON0 & 0X0F | Mode | RxMode;
	if(Mode == USCI0_UART_Mode_8B)
	{
		if(BaudRate == USCI0_UART_BaudRate_FsysDIV12)
		{
			US0CON0 &= 0XDF;		
		}
		else if(BaudRate == USCI0_UART_BaudRate_FsysDIV4)
		{
			US0CON0 |= 0X20;		
		}
	}
	else
	{
		US0CON2 = UARTFsys / BaudRate / 256;
		US0CON1 = UARTFsys / BaudRate % 256;
	}	
}

/*****************************************************
*�������ƣ�void USCI0_UART_SendData8(uint8_t Data)
*�������ܣ�USCI0 UART1����8λ����
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI0_UART_SendData8(uint8_t Data)
{
   US0CON3 = Data;
}

/*****************************************************
*�������ƣ�uint8_t USCI0_UART_ReceiveData8(void)
*�������ܣ����US0CON3�е�ֵ
*��ڲ�����void
*���ڲ�����uint8_t		
*****************************************************/
uint8_t USCI0_UART_ReceiveData8(void)
{
	return US0CON3;
}

/*****************************************************
*�������ƣ�void USCI0_UART_SendData9(uint16_t Data)
*�������ܣ�UART1����9λ����
*��ڲ�����Data		���͵�����
*���ڲ�����void
*****************************************************/
void USCI0_UART_SendData9(uint16_t Data)
{
	uint8_t Data_9Bit;
	Data_9Bit = (Data>>8);
	if(Data_9Bit)
	{
		US0CON0	|= 0x08;
	}
	else
	{
		US0CON0	&= 0xf7;
	}
	
	US0CON3 = (uint8_t)Data;
}

/*****************************************************
*�������ƣ�uint16_t USCI0_UART_ReceiveData9(void)
*�������ܣ����US0CON3�е�ֵ���ھ�λ��ֵ
*��ڲ�����void
*���ڲ�����uint16_t		
*****************************************************/
uint16_t USCI0_UART_ReceiveData9(void)
{
	uint16_t Data9;
	Data9 =  US0CON3 + ((uint16_t)(US0CON0&0X04)<<6);
	return Data9;
}

/*****************************************************
*�������ƣ�void USCI0_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�USCI0�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void USCI0_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
    if(NewState != DISABLE)
    {
       IE1 |= 0x01;
    }
    else
    {
       IE1 &= 0xFE;
    }
/************************************************************/
	if(Priority != LOW)
	{
		IP1 |= 0x01;
	}
	else
	{
		IP1 &= 0xFE;
	}
}

/*****************************************************
*�������ƣ�FlagStatus USCI0_GetFlagStatus(USCI0_Flag_TypeDef USCI0_FLAG)
*�������ܣ����USCI0��־״̬
*��ڲ�����USCI0_FLAG		�����ȡ�ı�־λ
*���ڲ�����FlagStatus    	USCI0��־״̬	
*****************************************************/
FlagStatus USCI0_GetFlagStatus(USCI0_Flag_TypeDef USCI0_FLAG)
{
	FlagStatus bitstatus = RESET;

	if((USCI0_FLAG==USCI0_SPI_FLAG_SPIF) || (USCI0_FLAG==USCI0_SPI_FLAG_WCOL) || (USCI0_FLAG==USCI0_SPI_FLAG_TXE))
	{
		if((USCI0_FLAG & US0CON1) != (uint8_t)RESET)
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
		if((USCI0_FLAG & US0CON0) != (uint8_t)RESET)
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
*�������ƣ�void USCI0_ClearFlag(USCI0_Flag_TypeDef USCI0_FLAG)
*�������ܣ����USCI0��־״̬
*��ڲ�����USCI0_FLAG		��������ı�־λ
*���ڲ�����void	
*****************************************************/
void USCI0_ClearFlag(USCI0_Flag_TypeDef USCI0_FLAG)
{
	if((USCI0_FLAG==USCI0_SPI_FLAG_SPIF) || (USCI0_FLAG==USCI0_SPI_FLAG_WCOL) || (USCI0_FLAG==USCI0_SPI_FLAG_TXE))
	{
		US0CON1 &= (~USCI0_FLAG);
	}
	else
	{
		US0CON0 &= (~USCI0_FLAG);
	}
}

/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/


			   
               




