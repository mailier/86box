//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: sc95f8x1x_btm.c
//	作者		: 
//	模块功能	: BTM固件库函数C文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************

#include "sc95f8x1x_btm.h"

/**************************************************
*函数名称：void BTM_DeInit(void)
*函数功能：BTM相关寄存器复位至缺省值
*入口参数：void
*出口参数：void
**************************************************/
void BTM_DeInit(void)
{
	BTMCON = 0x00;	
}

/**************************************************
*函数名称：void BTM_Init(BTM_Timebase_TypeDef BTM_Timebase)
*函数功能：BTM初始化配置函数
*入口参数：BTM_Timebase		BTM溢出时间选择
*出口参数：void
**************************************************/
void BTM_Init(BTM_Timebase_TypeDef BTM_Timebase)
{
	BTMCON = (BTMCON & 0xF0) | BTM_Timebase;
}

/*****************************************************
*函数名称：void BTM_Cmd(FunctionalState NewState)
*函数功能：BTM功能开关函数
*入口参数：FunctionalState NewState	功能启动/关闭选择
*出口参数：void
*****************************************************/
void BTM_Cmd(FunctionalState NewState)
{
	if(NewState == DISABLE)
	{
		BTMCON &= 0x7f;	
	}
	else
	{
		BTMCON |= 0x80;
	}
}

/*****************************************************
*函数名称：void BTM_ITConfig(FunctionalState NewState, PriorityStatus Priority)
*函数功能：BTM中断初始化
*入口参数：FunctionalState NewState	中断使能/关闭选择
 		   PriorityStatus Priority	中断优先级选择
*出口参数：void
*****************************************************/
void BTM_ITConfig(FunctionalState NewState, PriorityStatus Priority)
{
	//中断使能设置
	if(NewState == DISABLE)
    {
       IE1 &= 0xfb;		
    }
    else
    {
       IE1 |= 0x04;		
    }

	//中断优先级设置
	if(Priority == LOW)
	{
		IP1 &= 0xfb;	
	}
	else
	{
		IP1 |= 0x04;	
	}	
}

/*****************************************************
*函数名称：FlagStatus BTM_GetFlagStatus(void)
*函数功能：获得BTM中断标志状态
*入口参数：void
*出口参数：FlagStatus	BTM中断标志状态	
*****************************************************/
FlagStatus BTM_GetFlagStatus(void)
{
	return (FlagStatus)(BTMCON & 0x40);
}

/*****************************************************
*函数名称：void BTM_ClearFlag(void)
*函数功能：清除BTM中断标志状态
*入口参数：void
*出口参数：void	
*****************************************************/
void BTM_ClearFlag(void)
{
	BTMCON &= 0xbf;
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/