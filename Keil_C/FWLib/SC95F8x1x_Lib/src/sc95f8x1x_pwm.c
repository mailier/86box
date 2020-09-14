//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_pwm.c
//	����		: 
//	ģ�鹦��	: PWM�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_pwm.h"

uint16_t xdata PWMREG[8] _at_ 0x1040;	//PWMռ�ձȵ��ڼĴ���
uint16_t pwm_tmpreg[8] = {0,0,0,0,0,0,0,0};		//PWMռ�ձȵ��ڼĴ�����������

/**************************************************
*�������ƣ�void PWM_DeInit(void)
*�������ܣ�PWM��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
**************************************************/
void PWM_DeInit(void)
{
	static uint8_t i;
	PWMMOD  = 0X00;
	PWMCFG = 0;
	PWMCON = 0;		
	PWMFLT = 0X00;
	PWMDFR = 0X00;
	IE1 &= 0XFD;
	IP1 &= 0XFD;
	for(i=0;i<8;i++)
	{
		PWMREG[i]=0;
	}		
}

/**************************************************
*�������ƣ�void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel, uint16_t PWM_Period)
*�������ܣ�PWM��ʼ�����ú���
*��ڲ�����PWM_PresSel	Ԥ��Ƶѡ��
		   PWM_Period	PWM��������
*���ڲ�����void
**************************************************/
void PWM_Init(PWM_PresSel_TypeDef PWM_PresSel, uint16_t PWM_Period)
{
	PWM_Period -= 1;
	PWMCFG = (PWMCFG & 0XCF) | PWM_PresSel;					//Ԥ��Ƶ
	PWMCFG = (PWMCFG & 0XF0) | (uint8_t)(PWM_Period / 256);	//���ڸ�4λ
	PWMCON = (uint8_t)(PWM_Period & 0X00FF);				//���ڵ�8λ
}

/**************************************************
*�������ƣ�void PWM_OutputStateConfig(uint8_t PWM_OutputPin, PWM_OutputState_TypeDef PWM_OutputState)
*�������ܣ�PWMx���ʹ��/ʧ�����ú���
*��ڲ�����PWM_OutputPin	PWMxѡ��
		   PWM_OutputState	PWM���״̬����
*���ڲ�����void
**************************************************/
void PWM_OutputStateConfig(uint8_t PWM_OutputPin, PWM_OutputState_TypeDef PWM_OutputState)
{
	uint8_t i; 
	for(i=0;i<8;i++)
	{
		if(PWM_OutputPin&(0x01<<i))
		{
			if(PWM_OutputState == PWM_OUTPUTSTATE_DISABLE)
			{
				pwm_tmpreg[i] &= 0X7FFF;	
			}
			else
			{
				pwm_tmpreg[i] |= 0X8000;
			} 
			PWMREG[i] = pwm_tmpreg[i];
		}
	}
}

/**************************************************
*�������ƣ�void PWM_PolarityConfig(uint8_t PWM_OutputPin, PWM_Polarity_TypeDef PWM_Polarity)
*�������ܣ�PWMx��/����������ú���
*��ڲ�����PWM_OutputPin	PWMxѡ��
		   PWM_Polarity		PWM�����/��������
*���ڲ�����void
**************************************************/
void PWM_PolarityConfig(uint8_t PWM_OutputPin, PWM_Polarity_TypeDef PWM_Polarity)
{
	uint8_t i; 
	for(i=0;i<8;i++)
	{
		if(PWM_OutputPin&(0x01<<i))
		{
			if(PWM_Polarity == PWM_POLARITY_NON_INVERT)
			{
				pwm_tmpreg[i] &= 0XBFFF;	
			}
			else
			{
				pwm_tmpreg[i] |= 0X4000;
			}
			PWMREG[i] = pwm_tmpreg[i];
		}
	}	
}

/**************************************************
*�������ƣ�void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin, uint16_t PWM_DutyCycle)
*�������ܣ�PWMx��������ģʽ���ú���
*��ڲ�����PWM_OutputPin	PWMx����ͨ��ѡ��
		   PWM_DutyCycle	PWMռ�ձ�����
*���ڲ�����void
**************************************************/
void PWM_IndependentModeConfig(PWM_OutputPin_TypeDef PWM_OutputPin, uint16_t PWM_DutyCycle)
{
	uint8_t i; 
	for(i=0;i<8;i++)
	{
	   if(PWM_OutputPin&(0x01<<i))
	   {
	   	    pwm_tmpreg[i] = pwm_tmpreg[i] & 0XF000 | PWM_DutyCycle;
			PWMREG[i] = pwm_tmpreg[i]; 
	   }
	}
}
/**************************************************
*�������ƣ�void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin, uint16_t PWM_DutyCycle)
*�������ܣ�PWMxPWMy��������ģʽ���ú���
*��ڲ�����PWM_ComplementaryOutputPin	PWMxPWMy����ͨ��ѡ��
		   PWM_DutyCycle				PWMռ�ձ�����
*���ڲ�����void
**************************************************/
void PWM_ComplementaryModeConfig(PWM_ComplementaryOutputPin_TypeDef PWM_ComplementaryOutputPin, uint16_t PWM_DutyCycle)
{
	PWMMOD = 0X08;
	switch(PWM_ComplementaryOutputPin)	//����ռ�ձ�
	{
		case PWM40PWM41:
			PWMREG[PWM40PWM41] = ( PWMREG[PWM40PWM41] & 0XC000 ) | PWM_DutyCycle;
			break;
		case PWM42PWM43:
			PWMREG[PWM42PWM43] = ( PWMREG[PWM42PWM43] & 0XC000 ) | PWM_DutyCycle;
			break;
		case PWM50PWM51:
			PWMREG[PWM50PWM51] = ( PWMREG[PWM50PWM51] & 0XC000 ) | PWM_DutyCycle;
			break;
		case PWM52PWM53:
			PWMREG[PWM52PWM53] = ( PWMREG[PWM52PWM53] & 0XC000 ) | PWM_DutyCycle;
			break;
		default:
			break;
	}		
}

/**************************************************
*�������ƣ�void PWM_DeadTimeConfig(uint8_t PWM_RisingDeadTime, uint8_t PWM_FallingDeadTime)
*�������ܣ�PWM��������ģʽ������ʱ�����ú���
*��ڲ�����PWM_RisingDeadTime	PWM��������ʱ��	 00-FF
		   PWM_FallingDeadTime	PWM�����½�ʱ��  00-FF
*���ڲ�����void
**************************************************/
void PWM_DeadTimeConfig(uint8_t PWM_RisingDeadTime, uint8_t PWM_FallingDeadTime)
{
	PWMDFR = (PWM_RisingDeadTime | (PWM_FallingDeadTime << 4));			
}

/*****************************************************
*�������ƣ�void PWM_Cmd(FunctionalState NewState)
*�������ܣ�PWM���ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
*****************************************************/
void PWM_Cmd(FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        PWMCFG |= 0X80;
    }
    else
    {
        PWMCFG &= 0X7F;
    }
}

/*****************************************************
*�������ƣ�void PWM_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*�������ܣ�PWM�жϳ�ʼ��
*��ڲ�����FunctionalState NewState	�ж�ʹ��/�ر�ѡ��
 		   PriorityStatus Priority	�ж����ȼ�ѡ��
*���ڲ�����void
*****************************************************/
void PWM_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
    if (NewState != DISABLE)
    {
		IE1 |= 0X02;	        
    }
    else
    {
		IE1 &= 0XFD;   
    }

	if(Priority == LOW)
	{
		IP1 &= ~0X02;	
	}
	else
	{
		IP1 |= 0X02;	
	}
}

/*****************************************************
*�������ƣ�FlagStatus PWM_GetFlagStatus(void)
*�������ܣ����PWM�жϱ�־״̬
*��ڲ�����void
*���ڲ�����FlagStatus	PWM�жϱ�־״̬	
*****************************************************/
FlagStatus PWM_GetFlagStatus(void)
{
	return (FlagStatus)(PWMCFG & 0X40);
}

/*****************************************************
*�������ƣ�void PWM_ClearFlag(void)
*�������ܣ����PWM�жϱ�־״̬
*��ڲ�����void
*���ڲ�����void	
*****************************************************/
void PWM_ClearFlag(void)
{
	PWMCFG &= 0XBF;
}

/*****************************************************
*�������ƣ�FlagStatus PWM_GetFaultDetectionFlagStatus(void)
*�������ܣ����PWM���ϼ���־λ״̬
*��ڲ�����void
*���ڲ�����FlagStatus	PWM���ϼ���־λ״̬	
*****************************************************/
FlagStatus PWM_GetFaultDetectionFlagStatus(void)
{
	return (FlagStatus)(PWMFLT & 0X40);
}

/*****************************************************
*�������ƣ�void PWM_ClearFaultDetectionFlag(void)
*�������ܣ����PWM���ϼ���־λ״̬   // ��ע��,��������ģʽ�£���λ��������
*��ڲ�����void
*���ڲ�����void	
*****************************************************/
void PWM_ClearFaultDetectionFlag(void)
{
	PWMFLT &= 0XBF;
}

/*****************************************************
*�������ƣ�void PWM_FaultDetectionFunctionConfig(FunctionalState NewState)
*�������ܣ�PWM���ϼ�⹦�ܿ���/�ر�
*��ڲ�����FunctionalState NewState	���ϼ�⹦�ܿ���/�ر�
*���ڲ�����void
*****************************************************/
void PWM_FaultDetectionConfig(FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
		PWMFLT |= 0X80;	        
    }
    else
    {
		PWMFLT &= 0X7F;   
    }
}

/*****************************************************
*�������ƣ�void PWM_FaultDetectionModeConfig(PWM_FaultDetectionMode_TypeDef FaultDetectionMode, PWM_FaultDetectionVoltageSelect_TypeDef FaultDetectionVoltageSelect, PWM_FaultDetectionWaveFilteringTime_TypeDef FaultDetectionWaveFilteringTime)
*�������ܣ�PWM���ϼ��ģʽ����
*��ڲ�����FaultDetectionMode	���ϼ�⹦��ģʽ���ã� ����ģʽ/����ģʽ
		   FaultDetectionVoltageSelect	���ϼ���ƽѡ��
		   FaultDetectionWaveFilteringTime	���ϼ�������ź��˲�ʱ��ѡ��
*���ڲ�����void
*****************************************************/
void PWM_FaultDetectionModeConfig(PWM_FaultDetectionMode_TypeDef FaultDetectionMode, PWM_FaultDetectionVoltageSelect_TypeDef FaultDetectionVoltageSelect, PWM_FaultDetectionWaveFilteringTime_TypeDef FaultDetectionWaveFilteringTime)
{
	PWMFLT = (PWMFLT & 0XC0) | FaultDetectionMode | FaultDetectionVoltageSelect | FaultDetectionWaveFilteringTime;	        
  
}

/*****************************************************
*�������ƣ�void PWM_Aligned_Mode_Select(void)
*�������ܣ�ѡ��PWM�Ķ���ģʽ
*��ڲ�����PWM_Aligned_Mode ѡ�����ģʽ
*���ڲ�����void	
*****************************************************/
void PWM_Aligned_Mode_Select(PWM_Aligned_Mode_TypeDef PWM_Aligned_Mode)
{
	if(PWM_Aligned_Mode == PWM_Edge_Aligned_Mode)
	{
	   PWMMOD&=0XFB;
	}
	else if(PWM_Aligned_Mode == PWM_Center_Alignment_Mode)
	{
	   PWMMOD|=0X04;
	}
}
/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/