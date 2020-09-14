//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_timerx.c
//	作者		: 
//	模块功能	: TIMER3固件库函数C文件
//	局部函数列表:
//  最后更正日期: 2020/04/16
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#include "sc95f8x1x_timer3.h"

/**************************************************
*函数名称：void TIMX_DeInit(void)
*函数功能：TIMER3相关寄存器复位至缺省值
*入口参数：void
*出口参数：void
**************************************************/
void TIM3_DeInit()
{
	TXINX = 0x03;    //TIMER3 选择
	TXCON = 0X00;
	TXMOD = 0X00;
	RCAPXH = 0X00;
	RCAPXL = 0X00;
	THX = 0X00;
	TLX = 0X00;
	IE1 &= 0X3F;
	IP1 &= 0X3F;
	ET2 = 0;
	IPT2 = 0;
}

/**************************************************
*函数名称：void TIM3_PrescalerSelection(TIMX_TimerSelect_TypeDef TIMX_TimerSelect, TIMX_PresSel_TypeDef TIMX_PrescalerSelection)
*函数功能：TIMER3 预分频选择
*入口参数：TIM2_PrescalerSelection	预分频选择
*出口参数：void
**************************************************/
void TIM3_PrescalerSelection(TIM3_PresSel_TypeDef TIM3_PrescalerSelection)
{
	TXINX = 0x03;
	if(TIM3_PrescalerSelection == TIM3_PRESSEL_FSYS_D12)
	{
		TXMOD &= 0X7F;
	}
	else if(TIM3_PrescalerSelection == TIM3_PRESSEL_FSYS_D1)
	{
		TXMOD |= 0X80;
	}	
}

/**************************************************
*函数名称：void TIM3_WorkMode1Config(uint16_t TIM3_SetCounter)
*函数功能：TIMER3工作模式1配置函数
*入口参数：uint16_t TIM3_SetCounter	配置计数初值
*出口参数：void
**************************************************/
void TIM3_WorkMode1Config(uint16_t TIM3_SetCounter)
{	
	TXINX = 0x03;
	RCAPXL = TIM3_SetCounter % 256;
	RCAPXH = TIM3_SetCounter / 256;

	TLX = RCAPXL;
	THX = RCAPXH;
}

/*****************************************************
*函数名称：void TIM3_Cmd(FunctionalState NewState)
*函数功能：TIMER3功能开关函数
*入口参数：FunctionalState NewState	功能启动/关闭选择
*出口参数：void
*****************************************************/
void TIM3_Cmd(FunctionalState NewState)
{
	TXINX = 0x03;
	if (NewState == DISABLE)
    {
       TRX = 0;
    }
    else
    {
       TRX = 1;
    }
}

/*****************************************************
*函数名称：void TIM3_ITConfig(TIM3_TimerSelect_TypeDef TIM3_TimerSelect, FunctionalState NewState, PriorityStatus Priority)
*函数功能：TIMER3中断初始化
*入口参数：NewState	中断使能/关闭选择
 		   Priority	中断优先级选择
*出口参数：void
*****************************************************/
void TIM3_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	TXINX = 0x03;
	if(NewState == DISABLE)
	{
   		IE1 &= 0XBF;
	}
	else
	{
   		IE1 |= 0X40;
	}
	if(Priority == LOW)
	{
		IP1 &= 0XBF;
	}
	else
	{
		IP1 |= 0X40;
	}
}

/*****************************************************
*函数名称：FlagStatus TIM3_GetFlagStatus(void)
*函数功能：获得TIMER3中断标志状态
*入口参数：TIM3_Flag   	TIMER3标志选择
*出口参数：FlagStatus	TIMER3中断标志状态	
*****************************************************/
FlagStatus TIM3_GetFlagStatus()
{	
	FlagStatus status = RESET;
	TXINX = 0x03;
	if(TFX)
	{
		status = SET; 			
	}
	else
	{
		status = RESET;	
	}
	return status;	
}

/*****************************************************
*函数名称：void TIM3_ClearFlag(void)
*函数功能：清除TIMER3中断标志状态
*入口参数：TIM3_Flag   TIMER3标志选择
*出口参数：void	
*****************************************************/
void TIM3_ClearFlag()
{
	TXINX = 0x03;
	TXCON &= 0x7F;
}

/******************* (C) COPYRIGHT 2020 SinOne Microelectronics *****END OF FILE****/