//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_usci2.c
//	作者		: 
//	模块功能	: USCI2固件库函数C文件
//	局部函数列表:
//  最后更正日期: 2019/04/16
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#include "sc95f8x1x_usci2.h"

/**************************************************
*函数名称：void USCI2_DeInit(void)
*函数功能：USCI2相关寄存器复位至缺省值
*入口参数：void
*出口参数：void
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
*函数名称：void USCI2_SPI_Init(USCI2_SPI_FirstBit_TypeDef FirstBit, USCI2_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,USCI2_SPI_Mode_TypeDef Mode,
							 USCI2_SPI_ClockPolarity_TypeDef ClockPolarity, USCI2_SPI_ClockPhase_TypeDef ClockPhase,USCI2_SPI_TXE_INT_TypeDef SPI_TXE_INT,USCI2_TransmissionMode_TypeDef TransmissionMode)
*函数功能：SPI初始化配置函数
*入口参数：FirstBit				优先传送位选择（MSB/LSB）
		   BaudRatePrescaler	SPI时钟频率选择
		   Mode					SPI工作模式选择
		   ClockPolarity		SPI时钟极性选择
		   ClockPhase			SPI时钟相位选择
		   SPI_TXE_INT			发送缓存器中断允许选择
		   TransmissionMode		SPI传输模式选择 8/16e位
*出口参数：void																								
**************************************************/
void USCI2_SPI_Init(USCI2_SPI_FirstBit_TypeDef FirstBit, USCI2_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, USCI2_SPI_Mode_TypeDef Mode,
				  USCI2_SPI_ClockPolarity_TypeDef ClockPolarity, USCI2_SPI_ClockPhase_TypeDef ClockPhase, USCI2_SPI_TXE_INT_TypeDef SPI_TXE_INT,USCI2_TransmissionMode_TypeDef TransmissionMode)
{
	TMCON = (TMCON & 0X3F) | 0X40;
	US2CON1 = US2CON1 & (~0X05) | FirstBit | SPI_TXE_INT | TransmissionMode;
	US2CON0 = US2CON0 & 0X80 | BaudRatePrescaler | Mode | ClockPolarity | ClockPhase;
}

/*****************************************************
*函数名称：void USCI2_SPI_Cmd(FunctionalState NewState)
*函数功能：SPI功能开关函数
*入口参数：FunctionalState NewState	功能启动/关闭选择
*出口参数：void
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
*函数名称：void USCI2_SPI_SendData_8(uint8_t Data)
*函数功能：USCI2 SPI发送数据
*入口参数：Data		发送的数据
*出口参数：void
*****************************************************/
void USCI2_SPI_SendData_8(uint8_t Data)
{
	US2CON2 = Data;
}

/*****************************************************
*函数名称：uint8_t USCI2_SPI_ReceiveData_8(void)
*函数功能：获得US2CON2中的值
*入口参数：void
*出口参数：uint8_t		
*****************************************************/
uint8_t USCI2_SPI_ReceiveData_8(void)
{
	return US2CON2;		
}

/*****************************************************
*函数名称：void USCI2_SPI_SendData_16(uint16_t Data)
*函数功能：US2CON2 SPI发送数据
*入口参数：Data		发送的数据
*出口参数：void
*****************************************************/
void USCI2_SPI_SendData_16(uint16_t Data)
{
	US2CON3 = (uint8_t) (Data >> 8);
	US2CON2 = (uint8_t) Data;
}

/*****************************************************
*函数名称：uint16_t USCI2_SPI_ReceiveData_16(void)
*函数功能：获得US2CON2中的值
*入口参数：void
*出口参数：uint16_t		
*****************************************************/
uint16_t USCI2_SPI_ReceiveData_16(void)
{
	uint16_t SPI_data;
	SPI_data = (uint16_t)((US2CON3 << 8) |  US2CON2);
	return SPI_data;		
}

/**************************************************
*函数名称：void USCI2_TWI_Slave_Init(uint8_t TWI_Address)
*函数功能：USCI2 TWI 从机初始化配置函数
*入口参数：TWI_Address	7位从机地址配置			
*出口参数：void
**************************************************/
void USCI2_TWI_Slave_Init(uint8_t TWI_Address)
{
	TMCON = TMCON & 0X3F | 0X80;
	US2CON2 = TWI_Address<<1;		
}

/**************************************************
*函数名称：void USCI2_TWI_MasterCommunicationRate(USCI2_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate)
*函数功能：USCI2 TWI主机模式下通讯速率设定
*入口参数：TWI_MasterCommunicationRate TWI主机模式下通讯速率
*出口参数：void
**************************************************/
void USCI2_TWI_MasterCommunicationRate(USCI2_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate)
{
	TMCON = TMCON & 0X3F | 0X80;		//选择usci2为TWI

	US2CON1 = TWI_MasterCommunicationRate;		
}

/**************************************************
*函数名称：void USCI2_TWI_Start(void)
*函数功能：USCI2 TWI 起始位
*入口参数：void
*出口参数：void
**************************************************/
void USCI2_TWI_Start(void)
{
	US2CON1 |= 0x20;		
}

/**************************************************
*函数名称：void USCI2_TWI_MasterModeStop(void)
*函数功能：USCI2 TWI主机模式停止位
*入口参数：void
*出口参数：void
**************************************************/
void USCI2_TWI_MasterModeStop(void)
{
	US2CON1 |= 0x10;		
}

/**************************************************
*函数名称：void USCI2_TWI_SlaveClockExtension(void)
*函数功能：USCI2 TWI从机模式时钟延长功能位
*入口参数：void
*出口参数：void
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
*函数名称：void USCI2_TWI_AcknowledgeConfig(FunctionalState NewState)
*函数功能：TWI接收应答使能函数
*入口参数：FunctionalState NewState		接收应答使能/失能选择			
*出口参数：void
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
*函数名称：void USCI2_TWI_GeneralCallCmd(FunctionalState NewState)
*函数功能：TWI通用地址响应使能函数
*入口参数：FunctionalState NewState		通用地址响应使能/失能选择			
*出口参数：void
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
*函数名称：void USCI2_TWI_Cmd(FunctionalState NewState)
*函数功能：TWI功能开关函数
*入口参数：FunctionalState NewState	功能启动/关闭选择
*出口参数：void
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
*函数名称：void USCI2_TWI_SendData(uint8_t Data)
*函数功能：TWI发送数据
*入口参数：Data		发送的数据/地址
*出口参数：void
*****************************************************/
void USCI2_TWI_SendData(uint8_t Data)
{
	US2CON3 = Data;	
}

/*****************************************************
*函数名称：uint8_t USCI2_TWI_SendData(void)
*函数功能：获得US2CON3中的值
*入口参数：void
*出口参数：uint8_t	
*****************************************************/
uint8_t USCI2_TWI_ReceiveData(void)
{
	return US2CON3;
}

/**************************************************
*函数名称：void USCI2_UART_Init(uint32_t UARTFsys, uint32_t BaudRate, USCI2_UART_Mode_TypeDef Mode, USCI2_UART_RX_TypeDef RxMode)
*函数功能：UART初始化配置函数
*入口参数：UARTFsys	系统时钟频率
		   BaudRate		波特率
		   Mode			UART1工作模式
		   RxMode		接收允许选择
*出口参数：void
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
*函数名称：void USCI2_UART_SendData8(uint8_t Data)
*函数功能：USCI2 UART1发送8位数据
*入口参数：Data		发送的数据
*出口参数：void
*****************************************************/
void USCI2_UART_SendData8(uint8_t Data)
{
   US2CON3 = Data;
}

/*****************************************************
*函数名称：uint8_t USCI2_UART_ReceiveData8(void)
*函数功能：获得US2CON3中的值
*入口参数：void
*出口参数：uint8_t		
*****************************************************/
uint8_t USCI2_UART_ReceiveData8(void)
{
	return US2CON3;
}

/*****************************************************
*函数名称：void USCI2_UART_SendData9(uint16_t Data)
*函数功能：UART发送9位数据
*入口参数：Data		发送的数据
*出口参数：void
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
*函数名称：uint16_t USCI2_UART_ReceiveData9(void)
*函数功能：获得US2CON3中的值及第九位的值
*入口参数：void
*出口参数：uint16_t		
*****************************************************/
uint16_t USCI2_UART_ReceiveData9(void)
{
	uint16_t Data9;
	Data9 =  US2CON3 + ((uint16_t)(US2CON0&0X04)<<6);
	return Data9;
}

/*****************************************************
*函数名称：void USCI2_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*函数功能：USCI2中断初始化
*入口参数：FunctionalState NewState	中断使能/关闭选择
 		   PriorityStatus Priority	中断优先级选择
*出口参数：void
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
*函数名称：FlagStatus USCI2_GetFlagStatus(USCI2_Flag_TypeDef USCI2_FLAG)
*函数功能：获得USCI2标志状态
*入口参数：USCI2_FLAG		所需获取的标志位
*出口参数：FlagStatus    	USCI2标志状态	
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
*函数名称：void USCI2_ClearFlag(USCI2_Flag_TypeDef USCI2_FLAG)
*函数功能：清除USCI2标志状态
*入口参数：USCI2_FLAG		所需清除的标志位
*出口参数：void	
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


			   
               




