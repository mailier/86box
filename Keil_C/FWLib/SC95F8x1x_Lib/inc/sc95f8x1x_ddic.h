//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_ddic.c
//	����		: 
//	ģ�鹦��	: DDIC�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************
#ifndef _sc95f8x1x_DDIC_H_
#define	_sc95f8x1x_DDIC_H_

#include "sc95f8x1x.h"

typedef enum {
	DDIC_PIN_X0    = ((uint8_t)0x01),	//Px0�ڴ���ʾ��������
	DDIC_PIN_X1    = ((uint8_t)0x02),	//Px1�ڴ���ʾ��������
	DDIC_PIN_X2    = ((uint8_t)0x04),	//Px2�ڴ���ʾ��������
	DDIC_PIN_X3    = ((uint8_t)0x08),	//Px3�ڴ���ʾ��������
	DDIC_PIN_X4    = ((uint8_t)0x10), 	//Px4�ڴ���ʾ��������
	DDIC_PIN_X5    = ((uint8_t)0x20), 	//Px5�ڴ���ʾ��������
	DDIC_PIN_X6    = ((uint8_t)0x40), 	//Px6�ڴ���ʾ��������
	DDIC_PIN_X7    = ((uint8_t)0x80), 	//Px7�ڴ���ʾ��������
}DDIC_Pin_TypeDef;

typedef enum 
{
	DDIC_DUTYCYCLE_D8 = (uint8_t)0x00, //1/8 ռ�ձ�
	DDIC_DUTYCYCLE_D6 = (uint8_t)0x10, //1/6 ռ�ձ�
	DDIC_DUTYCYCLE_D5 =	(uint8_t)0x20, //1/5 ռ�ձ�
	DDIC_DUTYCYCLE_D4 =	(uint8_t)0x30  //1/4 ռ�ձ�
} DDIC_DutyCycle_TypeDef;

typedef enum {
	 DDIC_ResSel_100K	= (uint8_t)0X00,   //�趨�ڲ���ѹ����Ϊ100k
	 DDIC_ResSel_200K	= (uint8_t)0X04,   //�趨�ڲ���ѹ����Ϊ200k
	 DDIC_ResSel_400K	= (uint8_t)0X08,   //�趨�ڲ���ѹ����Ϊ400k
	 DDIC_ResSel_800K	= (uint8_t)0X0C	   //�趨�ڲ���ѹ����Ϊ800k
} DDIC_ResSel_Typedef;

typedef enum {
	 DDIC_BIAS_D3 = 0X01,	 //LCDƫ�õ�ѹΪ1/3
	 DDIC_BIAS_D4 = 0X00	 //LCDƫ�õ�ѹΪ1/4
} DDIC_BiasVoltage_Typedef;

typedef enum {
  SEG0_27COM4_7 = (uint8_t)0x00,   // 1/4ռ�ձ�ʱ��S0-S27Ϊsegment��C4-C7Ϊcommon
  SEG4_27COM0_3 = (uint8_t)0x01	   // 1/4ռ�ձ�ʱ��S4-S27Ϊsegment��C0-C3Ϊcommon
}DDIC_OutputPin_TypeDef;

typedef enum {
  DMOD_LCD = (uint8_t)0x00,	    // LCDģʽ
  DMOD_LED = (uint8_t)0x01   	// LEDģʽ
}DDIC_DMOD_TypeDef;

typedef enum {
  DDIC_SEG0 = (uint8_t)0,  //SEG0
  DDIC_SEG1 = (uint8_t)1,  //SEG1
  DDIC_SEG2 = (uint8_t)2,  //SEG2
  DDIC_SEG3 = (uint8_t)3,  //SEG3
  DDIC_SEG4 = (uint8_t)4,  //SEG4
  DDIC_SEG5 = (uint8_t)5,  //SEG5
  DDIC_SEG6 = (uint8_t)6,  //SEG6
  DDIC_SEG7 = (uint8_t)7,  //SEG7
  DDIC_SEG8 = (uint8_t)8,  //SEG8
  DDIC_SEG9 = (uint8_t)9,  //SEG9
  DDIC_SEG10= (uint8_t)10, //SEG10
  DDIC_SEG11= (uint8_t)11, //SEG11
  DDIC_SEG12= (uint8_t)12, //SEG12
  DDIC_SEG13= (uint8_t)13, //SEG13
  DDIC_SEG14= (uint8_t)14, //SEG14
  DDIC_SEG15= (uint8_t)15, //SEG15
  DDIC_SEG16= (uint8_t)16, //SEG16
  DDIC_SEG17= (uint8_t)17, //SEG17
  DDIC_SEG18= (uint8_t)18, //SEG18
  DDIC_SEG19= (uint8_t)19, //SEG19
  DDIC_SEG20= (uint8_t)20, //SEG20
  DDIC_SEG21= (uint8_t)21, //SEG21
  DDIC_SEG22= (uint8_t)22, //SEG22
  DDIC_SEG23= (uint8_t)23, //SEG23
  DDIC_SEG24= (uint8_t)24, //SEG24
  DDIC_SEG25= (uint8_t)25, //SEG25
  DDIC_SEG26= (uint8_t)26, //SEG26
  DDIC_SEG27= (uint8_t)27, //SEG27
}DDIC_Control_SEG_TypeDef;

typedef enum {
  DDIC_COM0 = (uint8_t)0x01,	//COM0
  DDIC_COM1 = (uint8_t)0x02,   	//COM1
  DDIC_COM2 = (uint8_t)0x04,   	//COM2
  DDIC_COM3 = (uint8_t)0x08,   	//COM3
  DDIC_COM4 = (uint8_t)0x10,   	//COM4
  DDIC_COM5 = (uint8_t)0x20,   	//COM5
  DDIC_COM6 = (uint8_t)0x40,   	//COM6
  DDIC_COM7 = (uint8_t)0x80   	//COM7
}DDIC_Control_COM_TypeDef;

typedef enum{
  DDIC_Control_ON  = (uint8_t)0x01, //����
  DDIC_Control_OFF = (uint8_t)0x00	//Ϩ��
}DDIC_Control_Status;

void DDIC_DeInit(void);
void DDIC_Init(DDIC_DutyCycle_TypeDef DDIC_DutyCylce, uint8_t P0OutputPin, uint8_t P1OutputPin, uint8_t P2OutputPin, uint8_t P3OutputPin);
void DDIC_LEDConfig(void);
void DDIC_LCDConfig(uint8_t LCDVoltage, DDIC_ResSel_Typedef DDIC_ResSel, DDIC_BiasVoltage_Typedef DDIC_BiasVoltage);
void DDIC_Cmd(FunctionalState NewState);
void DDIC_OutputPinOfDutycycleD4(DDIC_OutputPin_TypeDef DDIC_OutputPin);
void DDIC_DMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD);
void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg,DDIC_Control_COM_TypeDef DDIC_Com,DDIC_Control_Status DDIC_Contr);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/