//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_ddic.c
//	作者		: 
//	模块功能	: DDIC固件库函数C文件
//	局部函数列表:
//  最后更正日期: 2020/4/20
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#include "sc95f8x1x_ddic.h"

uint8_t xdata LCDRAM[30] _at_ 0x1000;

/**************************************************
*函数名称：void DDIC_DeInit(void)
*函数功能：DDIC相关寄存器复位至缺省值
*入口参数：void
*出口参数：void
**************************************************/
void DDIC_DeInit(void)
{
	DDRCON = 0X00;
	P0VO = 0X00;
	P1VO = 0X00;
	P2VO = 0X00;
	P3VO = 0X00;
	OTCON &= 0XF0;
}

/**************************************************
*函数名称：void DDIC_Init(uint8_t P0OutputPin)
*函数功能：DDIC初始化配置函数
*入口参数：DDIC_DutyCylce	LCD/LED显示占空比控制
		   P0OutputPin		设置P0口引脚为LCD电压输出口	
		   P1OutputPin		设置P1口引脚为LCD电压输出口
		   P2OutputPin		设置P2口引脚为LCD电压输出口
		   P3OutputPin		设置P3口引脚为LCD电压输出口
*出口参数：void
**************************************************/
void DDIC_Init(DDIC_DutyCycle_TypeDef DDIC_DutyCylce, uint8_t P0OutputPin, uint8_t P1OutputPin, uint8_t P2OutputPin, uint8_t P3OutputPin)
{
	DDRCON = DDRCON & 0XCF | DDIC_DutyCylce;
	P0VO = P0OutputPin;
	P1VO = P1OutputPin;
	P2VO = P2OutputPin;
	P3VO = P3OutputPin;			
}

/**************************************************
*函数名称：void DDIC_LEDConfig(void)
*函数功能：LED配置函数
*入口参数：void
*出口参数：void
**************************************************/
void DDIC_LEDConfig(void)
{
	DDRCON |= 0X40;
}

/**************************************************
*函数名称：void DDIC_LCDConfig(DDIC_ResSel_Typedef DDIC_ResSel)
*函数功能：LCD配置函数
*入口参数：LCDVoltage		LCD电压调节
		   DDIC_ResSel		LCD电压输出口电阻选择
		   DDIC_BiasVoltage	LCD显示驱动偏置电压设置
*出口参数：void
**************************************************/
void DDIC_LCDConfig(uint8_t LCDVoltage, DDIC_ResSel_Typedef DDIC_ResSel, DDIC_BiasVoltage_Typedef DDIC_BiasVoltage)
{
	DDRCON = DDRCON & 0XB0 | LCDVoltage;
	OTCON = OTCON & 0XF2 | DDIC_ResSel | DDIC_BiasVoltage;			
}
/**************************************************
*函数名称：void DDIC_DMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD)
*函数功能：显示驱动模式选择函数
*入口参数：DDIC_DMOD		选择显示模式
*出口参数：void
**************************************************/
void DDIC_DMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD)
{
	if(DDIC_DMOD == DMOD_LED)
	{
		DDRCON |= 0X40;
	}
	else
	{
		DDRCON &= 0XBF;
	}
}
/*****************************************************
*函数名称：void DDIC_OutputPinOfDutycycleD4(DDIC_OutputPin_TypeDef DDIC_OutputPin)
*函数功能：1/4占空比时segment与common复用管脚选择
*入口参数：DDIC_OutputPin	输出管脚选择
*出口参数：void
*****************************************************/
void DDIC_OutputPinOfDutycycleD4(DDIC_OutputPin_TypeDef DDIC_OutputPin)
{
	if(DDIC_OutputPin == SEG4_27COM0_3)
	{
		OTCON |= 0X02;
	}
	else
	{
		OTCON &= 0Xfd;
	}
}

/*****************************************************
*函数名称：void DDIC_Cmd(FunctionalState NewState)
*函数功能：显示驱动功能开关函数
*入口参数：FunctionalState NewState	功能启动/关闭选择
*出口参数：void
*****************************************************/
void DDIC_Cmd(FunctionalState NewState)
{
	if(NewState == DISABLE)
	{
		DDRCON &= 0X7F;
	}
	else
	{
		DDRCON |= 0x80;
	}	
}
/*****************************************************
*函数名称：void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg,DDIC_Control_COM_TypeDef DDIC_Com,DDIC_Control_Status DDIC_Contr)
*函数功能：控制输入的SEG和COM脚对应LCD/LED的亮灭
*入口参数：DDIC_Control_SEG_TypeDef DDIC_Seg 选择控制的SEG口
		   DDIC_Control_COM_TypeDef DDIC_Com 选择控制的COM口
		   DDIC_Control_Status DDIC_Contr	控制状态
*出口参数：void
*****************************************************/
void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg,DDIC_Control_COM_TypeDef DDIC_Com,DDIC_Control_Status DDIC_Contr)
{
	if(DDIC_Contr)
	{
		 LCDRAM[DDIC_Seg] |= DDIC_Com;
	}
	else
	{
		 LCDRAM[DDIC_Seg] &= (~DDIC_Com);
	}
}
/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/