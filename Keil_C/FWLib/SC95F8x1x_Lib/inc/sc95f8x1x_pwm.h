//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_pwm.h
//	����		: 
//	ģ�鹦��	: PWM�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#ifndef _sc95f8x1x_PWM_H_
#define	_sc95f8x1x_PWM_H_

#include "sc95f8x1x.h"

typedef enum {
  PWM40 = (uint8_t)0x01,   //PWM���ͨ��ѡ��PWM40
  PWM41 = (uint8_t)0x02,   //PWM���ͨ��ѡ��PWM41
  PWM42 = (uint8_t)0x04,   //PWM���ͨ��ѡ��PWM42
  PWM43 = (uint8_t)0x08,   //PWM���ͨ��ѡ��PWM43
  PWM50 = (uint8_t)0x10,   //PWM���ͨ��ѡ��PWM50
  PWM51 = (uint8_t)0x20,   //PWM���ͨ��ѡ��PWM51
  PWM52 = (uint8_t)0x40,   //PWM���ͨ��ѡ��PWM52
  PWM53 = (uint8_t)0x80	   //PWM���ͨ��ѡ��PWM53
}PWM_OutputPin_TypeDef;

typedef enum {
  PWM_PRESSEL_FHRC_D1  = (uint8_t)0x00,	   //PWMԤ��ƵΪFhrc/1
  PWM_PRESSEL_FHRC_D2  = (uint8_t)0x10,	   //PWMԤ��ƵΪFhrc/2
  PWM_PRESSEL_FHRC_D4  = (uint8_t)0x20,	   //PWMԤ��ƵΪFhrc/4
  PWM_PRESSEL_FHRC_D8  = (uint8_t)0x30	   //PWMԤ��ƵΪFhrc/8
}PWM_PresSel_TypeDef;

typedef enum {
	PWM40PWM41 = (uint8_t)0x00,					           //PWM����ģʽͨ��ѡ��PWM40��PWM41 
	PWM42PWM43 = (uint8_t)0x02,					           //PWM����ģʽͨ��ѡ��PWM42��PWM43
	PWM50PWM51 = (uint8_t)0x04,					           //PWM����ģʽͨ��ѡ��PWM50��PWM51
	PWM52PWM53 = (uint8_t)0x06					           //PWM����ģʽͨ��ѡ��PWM52��PWM53
} PWM_ComplementaryOutputPin_TypeDef;

typedef enum{
  PWM_OUTPUTSTATE_DISABLE            = ((uint8_t)0x00),	   //��PIN����ΪGPIO
  PWM_OUTPUTSTATE_ENABLE	         = ((uint8_t)0x01)	   //��PIN����ΪPWM
}PWM_OutputState_TypeDef;

typedef enum{
  PWM_POLARITY_NON_INVERT            = ((uint8_t)0x00),		//PWM���������
  PWM_POLARITY_INVERT                = ((uint8_t)0x01)		//PWM�������
}PWM_Polarity_TypeDef;

typedef enum{
  PWM_Latch_Mode                     = ((uint8_t)0x00),		//PWM���ϼ��ģʽ������ģʽ
  PWM_Immediate_Mode                 = ((uint8_t)0x20)		//PWM���ϼ��ģʽ������ģʽ
}PWM_FaultDetectionMode_TypeDef;

typedef enum{
  PWM_FaultDetectionVoltage_Low            = ((uint8_t)0x00),		//PWM���ϼ��͵�ƽѡ��
  PWM_FaultDetectionVoltage_high           = ((uint8_t)0x10)		//PWM���ϼ��ߵ�ƽѡ��
}PWM_FaultDetectionVoltageSelect_TypeDef;

typedef enum{
  PWM_WaveFilteringTime_0us                = ((uint8_t)0x00),		//PWM���ϼ�������ź��˲�ʱ��0us
  PWM_WaveFilteringTime_1us                = ((uint8_t)0x01),		//PWM���ϼ�������ź��˲�ʱ��1us
  PWM_WaveFilteringTime_4us                = ((uint8_t)0x02),		//PWM���ϼ�������ź��˲�ʱ��4us
  PWM_WaveFilteringTime_16us               = ((uint8_t)0x03)		//PWM���ϼ�������ź��˲�ʱ��16us
}PWM_FaultDetectionWaveFilteringTime_TypeDef;

typedef enum {
	PWM_Edge_Aligned_Mode  	   = (uint8_t)0x00,	//PWM���ض���ģʽ
	PWM_Center_Alignment_Mode  = (uint8_t)0x01	//PWM�м����ģʽ
} PWM_Aligned_Mode_TypeDef;

void PWM_DeInit(void);
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel, uint16_t PWM_Period);
void PWM_OutputStateConfig(uint8_t PWM_OutputPin, PWM_OutputState_TypeDef PWM_OutputState);
void PWM_PolarityConfig(PWM_OutputPin_TypeDef PWM_OutputPin, PWM_Polarity_TypeDef PWM_Polarity);
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin, uint16_t PWM_DutyCycle);
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin, uint16_t PWM_DutyCycle);
void PWM_DeadTimeConfig(uint8_t PWM_RisingDeadTime, uint8_t PWM_fallingDeadTime);
void PWM_Cmd(FunctionalState NewState);
void PWM_ITConfig(FunctionalState NewState, PriorityStatus Priority);
FlagStatus PWM_GetFlagStatus(void);
FlagStatus PWM_GetFaultDetectionFlagStatus(void);
void PWM_ClearFlag(void);
void PWM_ClearFaultDetectionFlag(void);
void PWM_FaultDetectionConfig(FunctionalState NewState);
void PWM_FaultDetectionModeConfig(PWM_FaultDetectionMode_TypeDef FaultDetectionMode, PWM_FaultDetectionVoltageSelect_TypeDef FaultDetectionVoltageSelect, PWM_FaultDetectionWaveFilteringTime_TypeDef FaultDetectionWaveFilteringTime);
void PWM_Aligned_Mode_Select(PWM_Aligned_Mode_TypeDef PWM_Aligned_Mode);

#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/