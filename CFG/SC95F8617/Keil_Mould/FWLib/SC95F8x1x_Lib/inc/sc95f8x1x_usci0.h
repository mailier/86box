//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_usci0.h
//	����		: 
//	ģ�鹦��	: USCI0�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/04/16
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_USCI0_H_
#define	_sc95f8x1x_USCI0_H_

#include "sc95f8x1x.h"

#define  USCI0_UART_BaudRate_FsysDIV12    0X00	 //��ģʽ0���ã����ж˿���ϵͳʱ�ӵ�1/12������
#define  USCI0_UART_BaudRate_FsysDIV4	  0X01	 //��ģʽ0���ã����ж˿���ϵͳʱ�ӵ�1/4������

typedef enum {
  	USCI0_Mode_SPI     = (uint8_t)0x01, 		   //SPI
  	USCI0_Mode_TWI     = (uint8_t)0x02,  		   //TWI
	USCI0_Mode_UART    = (uint8_t)0x03			   //UART
} USCI0_CommunicationMode_TypeDef;

typedef enum {
  	USCI0_SPI_FIRSTBIT_MSB = (uint8_t)0x00, 		//MSB���ȷ���
  	USCI0_SPI_FIRSTBIT_LSB = (uint8_t)0x04  		//LSB���ȷ���
} USCI0_SPI_FirstBit_TypeDef;

typedef enum {
	USCI0_SPI_BAUDRATEPRESCALER_1   = (uint8_t)0x00, //SPIʱ������Ϊϵͳʱ�ӳ���1
	USCI0_SPI_BAUDRATEPRESCALER_2   = (uint8_t)0x01, //SPIʱ������Ϊϵͳʱ�ӳ���2
	USCI0_SPI_BAUDRATEPRESCALER_4   = (uint8_t)0x02, //SPIʱ������Ϊϵͳʱ�ӳ���4
	USCI0_SPI_BAUDRATEPRESCALER_8   = (uint8_t)0x03, //SPIʱ������Ϊϵͳʱ�ӳ���8
	USCI0_SPI_BAUDRATEPRESCALER_16  = (uint8_t)0x04, //SPIʱ������Ϊϵͳʱ�ӳ���16
	USCI0_SPI_BAUDRATEPRESCALER_32  = (uint8_t)0x05, //SPIʱ������Ϊϵͳʱ�ӳ���32
	USCI0_SPI_BAUDRATEPRESCALER_64  = (uint8_t)0x06, //SPIʱ������Ϊϵͳʱ�ӳ���64
	USCI0_SPI_BAUDRATEPRESCALER_128 = (uint8_t)0x07  //SPIʱ������Ϊϵͳʱ�ӳ���128
} USCI0_SPI_BaudRatePrescaler_TypeDef;

typedef enum {
	USCI0_SPI_MODE_MASTER = (uint8_t)0x20, //SPIΪ���豸
	USCI0_SPI_MODE_SLAVE  = (uint8_t)0x00  //SPIΪ���豸
} USCI0_SPI_Mode_TypeDef;

typedef enum {
	USCI0_TWI_MODE_MASTER = (uint8_t)0x20, //TWIΪ���豸
	USCI0_TWI_MODE_SLAVE  = (uint8_t)0x00  //TWIΪ���豸
} USCI0_TWI_Mode_TypeDef;

typedef enum {
	USCI0_SPI_CLOCKPOLARITY_LOW  = (uint8_t)0x00, //SCK�ڿ���״̬��Ϊ�͵�ƽ
	USCI0_SPI_CLOCKPOLARITY_HIGH = (uint8_t)0x10  //SCK�ڿ���״̬��Ϊ�ߵ�ƽ
} USCI0_SPI_ClockPolarity_TypeDef;

typedef enum {
	USCI0_SPI_CLOCKPHASE_1EDGE = (uint8_t)0x00, //SCK�ĵ�һ�زɼ�����
	USCI0_SPI_CLOCKPHASE_2EDGE = (uint8_t)0x08  //SCK�ĵڶ��زɼ�����
} USCI0_SPI_ClockPhase_TypeDef;

typedef enum {
	USCI0_SPI_TXE_DISINT = (uint8_t)0x00, //TBIEΪ0ʱ���������ж�
	USCI0_SPI_TXE_ENINT  = (uint8_t)0x01  //TBIEΪ1ʱ�������ж�
} USCI0_SPI_TXE_INT_TypeDef;

typedef enum {
  	USCI0_SPI_DATA8     = (uint8_t)0x00, 			   //SPI 8λ����ģʽ
	USCI0_SPI_DATA16    = (uint8_t)0x01				   //SPI 16λ����ģʽ
} USCI0_TransmissionMode_TypeDef;

typedef enum {
  	USCI0_TWI_1024     = (uint8_t)0x00, 			   //TWIͨ������ Fhrc/1024 
	USCI0_TWI_512      = (uint8_t)0x01,				   //TWIͨ������ Fhrc/512
	USCI0_TWI_256      = (uint8_t)0x02, 			   //TWIͨ������ Fhrc/256
	USCI0_TWI_128      = (uint8_t)0x03,				   //TWIͨ������ Fhrc/128
	USCI0_TWI_64       = (uint8_t)0x04, 			   //TWIͨ������ Fhrc/64
	USCI0_TWI_32       = (uint8_t)0x05,				   //TWIͨ������ Fhrc/32
	USCI0_TWI_16       = (uint8_t)0x06, 			   //TWIͨ������ Fhrc/16
} USCI0_TWI_MasterCommunicationRate_TypeDef;

typedef enum { 
	USCI0_UART_Mode_8B   = 0X00,//UART����Ϊ8λģʽ
	USCI0_UART_Mode_10B  = 0X40,//UART����Ϊ10λģʽ
	USCI0_UART_Mode_11B  = 0X80 //UART����Ϊ11λģʽ
} USCI0_UART_Mode_TypeDef;

typedef enum {
	USCI0_UART_RX_ENABLE  = 0X10,//UART�������
	USCI0_UART_RX_DISABLE = 0X00 //UART��ֹ����
} USCI0_UART_RX_TypeDef;

typedef enum {
  USCI0_SPI_FLAG_SPIF    = (uint8_t)0x80, //SPI���ݴ��ͱ�־λSPIF 
  USCI0_SPI_FLAG_WCOL    = (uint8_t)0x50, //SPIд���ͻ��־λWCOL
  USCI0_SPI_FLAG_TXE     = (uint8_t)0x08, //SPI���ͻ������ձ�־TXE 
  USCI0_TWI_FLAG_GCA	   = (uint8_t)0x10,	//TWIͨ�õ�ַ��Ӧ��־λGCA
  USCI0_TWI_FLAG_TWIF    = (uint8_t)0x40, //TWI�жϱ�־λTWIF
  USCI0_TWI_FLAG_MSTR 	  = (uint8_t)0x20,	//TWI���ӱ�־λMSTR
  USCI0_UART_FLAG_TI	   = (uint8_t)0x02,	//UART�����жϱ�־λTI
  USCI0_UART_FLAG_RI	   = (uint8_t)0x01	//UART�����жϱ�־λRI
} USCI0_Flag_TypeDef;					   

void USCI0_DeInit(void);
void USCI0_SPI_Init(USCI0_SPI_FirstBit_TypeDef FirstBit,USCI0_SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler,USCI0_SPI_Mode_TypeDef Mode,USCI0_SPI_ClockPolarity_TypeDef ClockPolarity,USCI0_SPI_ClockPhase_TypeDef ClockPhase,USCI0_SPI_TXE_INT_TypeDef SPI_TXE_INT,USCI0_TransmissionMode_TypeDef TransmissionMode);
void USCI0_SPI_Cmd(FunctionalState NewState);
void USCI0_SPI_SendData_8(uint8_t Data);
uint8_t USCI0_SPI_ReceiveData_8(void);
void USCI0_SPI_SendData_16(uint16_t Data);
uint16_t USCI0_SPI_ReceiveData_16(void);
void USCI0_TWI_Slave_Init(uint8_t TWI_Address);
void USCI0_TWI_MasterCommunicationRate(USCI0_TWI_MasterCommunicationRate_TypeDef TWI_MasterCommunicationRate);
void USCI0_TWI_Start(void);
void USCI0_TWI_MasterModeStop(void);
void USCI0_TWI_SlaveClockExtension(FunctionalState NewState);
void USCI0_TWI_AcknowledgeConfig(FunctionalState NewState);
void USCI0_TWI_GeneralCallCmd(FunctionalState NewState);
void USCI0_TWI_Cmd(FunctionalState NewState);
void USCI0_TWI_SendData(uint8_t Data);
uint8_t USCI0_TWI_ReceiveData(void);
void USCI0_UART_Init(uint32_t UART1Fsys, uint32_t BaudRate, USCI0_UART_Mode_TypeDef Mode, USCI0_UART_RX_TypeDef RxMode); 
void USCI0_UART_SendData8(uint8_t Data);
uint8_t USCI0_UART_ReceiveData8(void);
void USCI0_UART_SendData9(uint16_t Data);
uint16_t USCI0_UART_ReceiveData9(void);
void USCI0_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus USCI0_GetFlagStatus(USCI0_Flag_TypeDef USCI0_FLAG);
void USCI0_ClearFlag(USCI0_Flag_TypeDef USCI0_FLAG);

#endif

/******************* (C) COPYRIGHT 2019 SinOne Microelectronics *****END OF FILE****/