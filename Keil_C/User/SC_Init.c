//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: SC_Init.c
//	ģ�鹦��	: MCU��ʼ������C�ļ�
//  ˵��        :  
//*************************************************************

#include "SC_Init.h"	//MCU��ʼ��ͷ�ļ��������̼�������ͷ�ļ�
#include "NST1001.h"


/*****************************************************
*��������: SC_Init
*��������: MCU��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_Init(void)
{
	
	SC_GPIO_Init();
	SC_OPTION_Init();
	SC_TIM2_Init();
	SC_INT_Init();
	SC_INT_Init();
	SC_INT_Init();
	SC_DDIC_Init();
	/*write initial function here*/		

	EA = 1;
}

/*****************************************************
*��������: SC_OPTION_Init
*��������: OPTION���ó�ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_OPTION_Init(void)
{
	
	OPTION_SYSCLK_Init(SYSCLK_PRESSEL_FOSC_D1);
	OPTION_XTIPLL_Cmd(DISABLE);
	OPTION_ADC_VrefConfig(ADC_VREF_VDD);
	OPTION_RST_PIN_Cmd(DISABLE);
	OPTION_LVR_Init(LVR_1_9V);
	OPTION_IAP_SetOperateRange(IAP_OPERATERANGE__LAST_1K_CODEREGION);
	OPTION_JTG_Cmd(DISABLE);
	/*OPTION_Init write here*/		
}

/*****************************************************
*��������: SC_GPIO_Init
*��������: GPIO��ʼ������
*��ڲ�����void00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
*���ڲ�����void
*****************************************************/
void SC_GPIO_Init(void)
{
	
	GPIO_Init(GPIO2, GPIO_PIN_0,GPIO_MODE_IN_PU);
	
	GPIO_Init(GPIO5, GPIO_PIN_0,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO5, GPIO_PIN_1,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO5, GPIO_PIN_3,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO5, GPIO_PIN_4,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO5, GPIO_PIN_5,GPIO_MODE_IN_PU);
	/*GPIO_Init write here*/		
}

/*****************************************************
*��������: SC_UART0_Init
*��������: UART0��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_UART0_Init(void)
{
	/*UART0_Init write here*/		
}

/*****************************************************
*��������: SC_TIM0_Init
*��������: TIMER0��ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_TIM0_Init(void)
{
	/*TIM0_Init write here*/		
}

/*****************************************************
*��������: SC_TIM1_Init
*��������: TIMER1��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_TIM1_Init(void)
{
	/*TIM1_Init write here*/	
}

/*****************************************************
*��������: SC_TIM2_Init
*��������: TIMER2��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_TIM2_Init(void)
{
	
	TIM2_TimeBaseInit(TIM2_MODE_TIMER,TIM2_COUNTDIRECTION_UP);
	TIM2_PrescalerSelection(TIM2_PRESSEL_FSYS_D1);
	
	TIM2_WorkMode1Config(33536);
	TIM2_ITConfig(ENABLE,LOW);
	TIM2_Cmd(ENABLE);
	/*TIM2_Init write here*/	
}
/*****************************************************
*��������: SC_TIM3_Init
*��������: TIMER3��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_TIM3_Init(void)
{
	/*TIM3_Init write here*/	
}
/*****************************************************
*��������: SC_TIM4_Init
*��������: TIMER4��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_TIM4_Init(void)
{
	/*TIM4_Init write here*/	
}
/*****************************************************
*��������: SC_PWM_Init
*��������: PWM��ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_PWM_Init(void)
{
	/*PWM_Init write here*/	
}

/*****************************************************
*��������: SC_INT_Init
*��������: INT��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_INT_Init(void)
{

	GPIO_Init(GPIO2, GPIO_PIN_1,GPIO_MODE_IN_PU);
	INT2_SetTriggerMode(0x00|INT21,INT_TRIGGER_RISE_FALL);
	INT2_ITConfig(ENABLE,LOW);
	
	GPIO_Init(GPIO4, GPIO_PIN_2,GPIO_MODE_IN_PU);
	GPIO_Init(GPIO4, GPIO_PIN_1,GPIO_MODE_IN_PU);
	GPIO_Init(GPIO4, GPIO_PIN_0,GPIO_MODE_IN_PU);
	INT1_SetTriggerMode(0x00|INT10|INT11|INT12,INT_TRIGGER_FALL_ONLY);
	INT1_ITConfig(ENABLE,LOW);
	
	GPIO_Init(GPIO0, GPIO_PIN_6,GPIO_MODE_IN_PU);
	GPIO_Init(GPIO0, GPIO_PIN_7,GPIO_MODE_IN_PU);
	INT0_SetTriggerMode(0x00|INT06|INT07,INT_TRIGGER_FALL_ONLY);
	INT0_ITConfig(DISABLE,LOW);
	NST1001_IO = 0;	 			//�ر�����NST1001
	NST1001_DQ = 0;			    //�ر���������IO�ڼ���
	
	/*INT_Init write here*/	
}

/*****************************************************
*��������: SC_ADC_Init
*��������: ADC��ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_ADC_Init(void)
{
	/*ADC_Init write here*/
}

/*****************************************************
*��������: SC_IAP_Init
*��������: IAP��ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_IAP_Init(void)
{
	/*IAP_Init write here*/		
}

/*****************************************************
*��������: SC_USCI0_Init
*��������: USCI0��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_USCI0_Init(void)
{
	/*USCI0_Init write here*/		
}
/*****************************************************
*��������: SC_USCI1_Init
*��������: USCI1��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_USCI1_Init(void)
{
	/*USCI1_Init write here*/		
}
/*****************************************************
*��������: SC_USCI2_Init
*��������: USCI2��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_USCI2_Init(void)
{
	/*USCI2_Init write here*/		
}
/*****************************************************
*��������: SC_BTM_Init
*��������: ��Ƶʱ�Ӷ�ʱ����ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_BTM_Init(void)
{
	/*BTM_Init write here*/		
}

/*****************************************************
*��������: SC_CRC_Init
*��������: check sum ��ʼ������
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SC_CRC_Init(void)
{
	/*CRC_Init write here*/	
}

/*****************************************************
*��������: SC_WDT_Init
*��������: ���Ź���ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_WDT_Init(void)
{
	/*WDT_Init write here*/		
}

/*****************************************************
*��������: SC_PWR_Init
*��������: ��Դ/���Ŀ��Ƴ�ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_PWR_Init(void)
{
	/*PWR_Init write here*/		
}
/*****************************************************
*��������: SC_DDIC_Init
*��������: ��ʾ���Ƴ�ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_DDIC_Init(void)
{
	
	DDIC_DMOD_Selcet(DMOD_LCD);
	DDIC_Init(DDIC_DUTYCYCLE_D4,0x00|DDIC_PIN_X0|DDIC_PIN_X1|DDIC_PIN_X2|DDIC_PIN_X3|DDIC_PIN_X4|DDIC_PIN_X5,0x00|DDIC_PIN_X0|DDIC_PIN_X1|DDIC_PIN_X2|DDIC_PIN_X3|DDIC_PIN_X4|DDIC_PIN_X5|DDIC_PIN_X6|DDIC_PIN_X7,0x00|DDIC_PIN_X2|DDIC_PIN_X3|DDIC_PIN_X4|DDIC_PIN_X5|DDIC_PIN_X6|DDIC_PIN_X7,0xf0|DDIC_PIN_X3|DDIC_PIN_X2|DDIC_PIN_X1|DDIC_PIN_X0);
	DDIC_LCDConfig(10,DDIC_ResSel_100K,DDIC_BIAS_D3);
	DDIC_OutputPinOfDutycycleD4(SEG0_27COM4_7 );
	DDIC_Cmd( ENABLE);
	/*DDIC_Init write here*/	
}
/*****************************************************
*��������: SC_ACMP_Init
*��������: �˷ų�ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_ACMP_Init(void)
{
	/*ACMP_Init write here*/	
}
/*****************************************************
*��������: SC_MDU_Init
*��������: �˳�������ʼ������
*��ڲ�����void
*���ڲ�����void 
*****************************************************/
void SC_MDU_Init(void)
{
	/*MDU_Init write here*/	
}