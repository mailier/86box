//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_acmp.c
//	作者		: 
//	模块功能	: ACMP固件库函数C文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#include "sc95f8x1x_acmp.h"

/**************************************************
*函数名称：void ACMP_DeInit(void)
*函数功能：MDU相关寄存器复位至缺省值
*入口参数：void
*出口参数：void
**************************************************/
void ACMP_DeInit(void)
{
	CMPCON = 0X00;
    CMPCFG = 0X00;
}

/**************************************************
*函数名称：void ACMP_Init(ACMP_Vref_Typedef ACMP_Vref, ACMP_Channel_TypeDef ACMP_Channel)
*函数功能：模拟比较器初始化配置函数
*入口参数：ACMP_Vref	  ACMP参考电压选择
		   ACMP_Channel	  ACMP输入通道选择	
*出口参数：void
**************************************************/
void ACMP_Init(ACMP_Vref_Typedef ACMP_Vref, ACMP_Channel_TypeDef ACMP_Channel)
{
	CMPCON = CMPCON & 0XF0 | ACMP_Vref;
	CMPCFG = CMPCFG & 0XFC | ACMP_Channel;
}

/**************************************************
*函数名称：void ACMP_SetTriggerMode(ACMP_TriggerMode_Typedef ACMP_TriggerMode)
*函数功能：ACMP中断触发方式配置函数
*入口参数：ACMP_TriggerMode	中断触发方式选择
*出口参数：void
**************************************************/
void ACMP_SetTriggerMode(ACMP_TriggerMode_Typedef ACMP_TriggerMode)
{
	CMPCFG = CMPCFG & 0X03 | ACMP_TriggerMode; 
}

/*****************************************************
*函数名称：void ACMP_Cmd(FunctionalState NewState)
*函数功能：ACMP功能开关函数
*入口参数：FunctionalState NewState	功能启动/关闭选择
*出口参数：void
*****************************************************/
void ACMP_Cmd(FunctionalState NewState)
{
	if(NewState == DISABLE)
	{
		CMPCON &= 0X7F;
	}
	else
	{
		CMPCON |= 0x80;
	}	
}

/*****************************************************
*函数名称：void ACMP_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*函数功能：ACMP中断初始化
*入口参数：FunctionalState NewState	中断使能/关闭选择
 		   PriorityStatus Priority	中断优先级选择
*出口参数：void
*****************************************************/
void ACMP_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
    if(NewState == DISABLE)
    {
       IE1 &= 0XBF;
    }
    else
    {
       IE1 |= 0X20;
    }
/************************************************************/
	if(Priority == LOW)
	{
		IP1 &= 0XBF;
	}
	else
	{
		IP1 |= 0X20;
	}
}

/*****************************************************
*函数名称：FlagStatus ACMP_GetFlagStatus(ACMP_Flag_TypeDef ACMP_Flag)
*函数功能：获得ACMP标志状态
*入口参数：ACMP_Flag	标志位选择
*出口参数：FlagStatus   ACMP标志状态	
*****************************************************/
FlagStatus ACMP_GetFlagStatus(ACMP_Flag_TypeDef ACMP_Flag)
{
	return (FlagStatus)(CMPCON & ACMP_Flag);
}

/*****************************************************
*函数名称：void ACMP_ClearFlag(void)
*函数功能：清除标志状态
*入口参数：ACMP_Flag	中断标志位选择
*出口参数：void	
*****************************************************/
void ACMP_ClearFlag(void)
{
   CMPCON &= (~ACMP_FLAG_CMPIF);
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/