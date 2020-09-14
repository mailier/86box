//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: SC_Init.c
//	模块功能	: MCU初始化函数C文件
//  说明        :  
//*************************************************************

#include "SC_Init.h"	//MCU初始化头文件，包含固件库所有头文件
#include "NST1001.h"


/*****************************************************
*函数名称: SC_Init
*函数功能: MCU初始化函数
*入口参数：void
*出口参数：void
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
*函数名称: SC_OPTION_Init
*函数功能: OPTION配置初始化函数
*入口参数：void
*出口参数：void
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
*函数名称: SC_GPIO_Init
*函数功能: GPIO初始化函数
*入口参数：void00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
*出口参数：void
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
*函数名称: SC_UART0_Init
*函数功能: UART0初始化函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_UART0_Init(void)
{
	/*UART0_Init write here*/		
}

/*****************************************************
*函数名称: SC_TIM0_Init
*函数功能: TIMER0初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_TIM0_Init(void)
{
	/*TIM0_Init write here*/		
}

/*****************************************************
*函数名称: SC_TIM1_Init
*函数功能: TIMER1初始化函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_TIM1_Init(void)
{
	/*TIM1_Init write here*/	
}

/*****************************************************
*函数名称: SC_TIM2_Init
*函数功能: TIMER2初始化函数
*入口参数：void
*出口参数：void
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
*函数名称: SC_TIM3_Init
*函数功能: TIMER3初始化函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_TIM3_Init(void)
{
	/*TIM3_Init write here*/	
}
/*****************************************************
*函数名称: SC_TIM4_Init
*函数功能: TIMER4初始化函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_TIM4_Init(void)
{
	/*TIM4_Init write here*/	
}
/*****************************************************
*函数名称: SC_PWM_Init
*函数功能: PWM初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_PWM_Init(void)
{
	/*PWM_Init write here*/	
}

/*****************************************************
*函数名称: SC_INT_Init
*函数功能: INT初始化函数
*入口参数：void
*出口参数：void
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
	NST1001_IO = 0;	 			//关闭上拉NST1001
	NST1001_DQ = 0;			    //关闭上拉计数IO口计数
	
	/*INT_Init write here*/	
}

/*****************************************************
*函数名称: SC_ADC_Init
*函数功能: ADC初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_ADC_Init(void)
{
	/*ADC_Init write here*/
}

/*****************************************************
*函数名称: SC_IAP_Init
*函数功能: IAP初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_IAP_Init(void)
{
	/*IAP_Init write here*/		
}

/*****************************************************
*函数名称: SC_USCI0_Init
*函数功能: USCI0初始化函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_USCI0_Init(void)
{
	/*USCI0_Init write here*/		
}
/*****************************************************
*函数名称: SC_USCI1_Init
*函数功能: USCI1初始化函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_USCI1_Init(void)
{
	/*USCI1_Init write here*/		
}
/*****************************************************
*函数名称: SC_USCI2_Init
*函数功能: USCI2初始化函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_USCI2_Init(void)
{
	/*USCI2_Init write here*/		
}
/*****************************************************
*函数名称: SC_BTM_Init
*函数功能: 低频时钟定时器初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_BTM_Init(void)
{
	/*BTM_Init write here*/		
}

/*****************************************************
*函数名称: SC_CRC_Init
*函数功能: check sum 初始化函数
*入口参数：void
*出口参数：void
*****************************************************/
void SC_CRC_Init(void)
{
	/*CRC_Init write here*/	
}

/*****************************************************
*函数名称: SC_WDT_Init
*函数功能: 看门狗初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_WDT_Init(void)
{
	/*WDT_Init write here*/		
}

/*****************************************************
*函数名称: SC_PWR_Init
*函数功能: 电源/功耗控制初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_PWR_Init(void)
{
	/*PWR_Init write here*/		
}
/*****************************************************
*函数名称: SC_DDIC_Init
*函数功能: 显示控制初始化函数
*入口参数：void
*出口参数：void 
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
*函数名称: SC_ACMP_Init
*函数功能: 运放初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_ACMP_Init(void)
{
	/*ACMP_Init write here*/	
}
/*****************************************************
*函数名称: SC_MDU_Init
*函数功能: 乘除法器初始化函数
*入口参数：void
*出口参数：void 
*****************************************************/
void SC_MDU_Init(void)
{
	/*MDU_Init write here*/	
}