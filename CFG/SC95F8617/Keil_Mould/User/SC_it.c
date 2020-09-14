//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: SC_it.c
//	作者		: 
//	模块功能	: sc92F854X 中断服务程序
//	局部函数列表:
//  最后更正日期: 2019/1/21
// 	版本		: V1.0   
//*************************************************************
#include "SC_it.h"
#include "..\Drivers\SCDriver_List.h"
void INT0Interrupt()		interrupt 0				
{
    /*<UserCodeStart>*/
	/*<UserCodeEnd>*/
	TCON &= 0XFD;//clear Interrupt flag
	/*INT0_it write here*/
		
}

void Timer0Interrupt()		interrupt 1			   
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*TIM0_it write here*/		
}

void INT1Interrupt()		interrupt 2		
{
    /*<UserCodeStart>*/
	/*<UserCodeEnd>*/
	TCON &= 0XF7;//clear Interrupt flag	
	/*INT1_it write here*/	
	
}

void Timer1Interrupt()		interrupt 3		
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*TIM1_it write here*/		
}

void UART0Interrupt()		interrupt 4		
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*UART0_it write here*/		
}

void Timer2Interrupt()		interrupt 5		
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*TIM2_it write here*/		
}

void ADCInterrupt()			interrupt 6		
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*ADC_it write here*/		
}

void USCI0Interrupt()			interrupt 7		
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*USCI0_it write here*/		
}

void PWMInterrupt()			interrupt 8
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*PWM_it write here*/		
}

void BTMInterrupt()			interrupt 9
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*BTM_it write here*/		
}

void INT2Interrupt()		interrupt 10
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*INT2_it write here*/		
}

void ACMPInterrupt()		interrupt 12
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*ACMP_it write here*/		
}
void Timer3Interrupt()		interrupt 13
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*Timer3_it write here*/		
}
void Timer4Interrupt()		interrupt 14
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*Timer4_it write here*/		
}
void USCI1Interrupt()		interrupt 15		
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*USCI1_it write here*/		
}
void USCI2Interrupt()		interrupt 16		
{
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*USCI2_it write here*/		
}