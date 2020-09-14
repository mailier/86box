//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: SC_it.c
//	����		: 
//	ģ�鹦��	: sc92F744XB �жϷ������
//	�ֲ������б�:
//  ����������: 2019/1/21
// 	�汾		: V1.0   
//*************************************************************
/********************Includes************************************************************************/


/********************Includes************************************************************************/
#include "SC_it.h"
#include "..\Drivers\SCDriver_list.h"
#include "HeadFiles\CustomType.h"
#include "HeadFiles\UserExport.h"
#include "HeadFiles\FunctionType.h"
/*<UserCodeStart>*/
#include "NST1001.h"
#include "EC06_key.h"

/*<UserCodeEnd>*/

/*********<GlobalVariables>**************************************************************************/			
/*********<GlobalVariablesAnnounceBegin>**************************************/
/*********<GlobalVariablesAnnounceEnd>****************************************/
/*<UserCodeStart>*/
/*<UserCodeEnd>*/

/*********<GlobalFunctions>**************************************************************************/			
/*********<GlobalFunctionsAnnounceBegin>**************************************/
/*********<GlobalFunctionsAnnounceEnd>****************************************/
/*<UserCodeStart>*/
/*<UserCodeEnd>*/

/****************Pragma directive********************************************************************/
/*<UserCodeStart>*/
/*<UserCodeEnd>*/

/*********<GlobalVariables>**************************************************************************/			
/*********<GlobalVariablesDefineBegin>**************************************/
/*********<GlobalVariablesDefineEnd>****************************************/
/*<UserCodeStart>*/



/*<UserCodeEnd>*/


/*********<GlobalFunctions>**************************************************************************/			
/*********<GlobalFunctionsDefineBegin>**************************************/
/*********<GlobalFunctionsDefineEnd>****************************************/
/*********<GlobalFunctionsRealizeBegin>**************************************/
/*********<GlobalFunctionsRealizeEnd>****************************************/
/*<UserCodeStart>*/
bit  TIME_2msFlag=0;
bit  TIME_3msFlag=0;
bit  TIME_5msFlag=0;
bit  TIME_10msFlag=0;

bit  TIME_50msFlag=0;
bit  TIME_100msFlag=0;
bit  TIME_150msFlag=0;
bit  TIME_200msFlag=0;
bit  TIME_300msFlag=0;
bit  TIME_400msFlag=0;
bit  TIME_500msFlag=0;
bit  TIME_1000msFlag=0;

unsigned int blink_start_count = 0;

/*<UserCodeEnd>*/




void INT0Interrupt()		interrupt 0				
{
/*<UserCodeStart>*/
	temp_num++;
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


	//��ת�������½����ۼ�
	
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
	static u16 timer2=0;

	spin_scan();			//��ת����������ɨ��
	
	TFX = 0;
	
	timer2++;				
	
	
	if(temp_start_flag == 1)		//1s��ʼ�¶Ȳɼ�
	{	
		temp_collect_timer2++;
		
		if(temp_over_flag == 1)	
			temp_over_timer2++;
	}
	
	if(timer2%5 == 0)
	{
		TIME_5msFlag=1;				//ʱ��оƬ5msɨ��
		
	}
	
	if(timer2%10 == 0)
	{
		TIME_10msFlag=1;
		key_scan();					//��������ɨ��
	}
	
	if(timer2%100 == 0)
	{
		TIME_100msFlag=1;			//��ҳ��100ms��ʾ
		
	}
	
	if(timer2%200 == 0)
	{
		TIME_200msFlag=1;
		
	}
	if(timer2%300 == 0)
	{
		TIME_300msFlag=1;			//��ʼ��ʱ��300ms��ʾ
		
	}
	if(timer2%500 == 0)
	{
		TIME_500msFlag=1;			//����ͼ����˸
		blink_start_count++;	
	
	}
	
	if(timer2%1000 == 0)
	{		
		TIME_1000msFlag = 1;
		
		temp_start_flag = 1;	
		int1_first_flag = 1;		//�򿪵�һ�ο����жϱ�־
	}

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
	/**/
	
	spin_int1_flag = 1;
	
	TFX = 0;

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
