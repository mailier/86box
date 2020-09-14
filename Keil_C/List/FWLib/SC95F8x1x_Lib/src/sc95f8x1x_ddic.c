//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_ddic.c
//	����		: 
//	ģ�鹦��	: DDIC�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2020/4/20
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_ddic.h"

uint8_t xdata LCDRAM[30] _at_ 0x1000;

/**************************************************
*�������ƣ�void DDIC_DeInit(void)
*�������ܣ�DDIC��ؼĴ�����λ��ȱʡֵ
*��ڲ�����void
*���ڲ�����void
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
*�������ƣ�void DDIC_Init(uint8_t P0OutputPin)
*�������ܣ�DDIC��ʼ�����ú���
*��ڲ�����DDIC_DutyCylce	LCD/LED��ʾռ�ձȿ���
		   P0OutputPin		����P0������ΪLCD��ѹ�����	
		   P1OutputPin		����P1������ΪLCD��ѹ�����
		   P2OutputPin		����P2������ΪLCD��ѹ�����
		   P3OutputPin		����P3������ΪLCD��ѹ�����
*���ڲ�����void
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
*�������ƣ�void DDIC_LEDConfig(void)
*�������ܣ�LED���ú���
*��ڲ�����void
*���ڲ�����void
**************************************************/
void DDIC_LEDConfig(void)
{
	DDRCON |= 0X40;
}

/**************************************************
*�������ƣ�void DDIC_LCDConfig(DDIC_ResSel_Typedef DDIC_ResSel)
*�������ܣ�LCD���ú���
*��ڲ�����LCDVoltage		LCD��ѹ����
		   DDIC_ResSel		LCD��ѹ����ڵ���ѡ��
		   DDIC_BiasVoltage	LCD��ʾ����ƫ�õ�ѹ����
*���ڲ�����void
**************************************************/
void DDIC_LCDConfig(uint8_t LCDVoltage, DDIC_ResSel_Typedef DDIC_ResSel, DDIC_BiasVoltage_Typedef DDIC_BiasVoltage)
{
	DDRCON = DDRCON & 0XB0 | LCDVoltage;
	OTCON = OTCON & 0XF2 | DDIC_ResSel | DDIC_BiasVoltage;			
}
/**************************************************
*�������ƣ�void DDIC_DMOD_Selcet(DDIC_DMOD_TypeDef DDIC_DMOD)
*�������ܣ���ʾ����ģʽѡ����
*��ڲ�����DDIC_DMOD		ѡ����ʾģʽ
*���ڲ�����void
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
*�������ƣ�void DDIC_OutputPinOfDutycycleD4(DDIC_OutputPin_TypeDef DDIC_OutputPin)
*�������ܣ�1/4ռ�ձ�ʱsegment��common���ùܽ�ѡ��
*��ڲ�����DDIC_OutputPin	����ܽ�ѡ��
*���ڲ�����void
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
*�������ƣ�void DDIC_Cmd(FunctionalState NewState)
*�������ܣ���ʾ�������ܿ��غ���
*��ڲ�����FunctionalState NewState	��������/�ر�ѡ��
*���ڲ�����void
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
*�������ƣ�void DDIC_Control(DDIC_Control_SEG_TypeDef DDIC_Seg,DDIC_Control_COM_TypeDef DDIC_Com,DDIC_Control_Status DDIC_Contr)
*�������ܣ����������SEG��COM�Ŷ�ӦLCD/LED������
*��ڲ�����DDIC_Control_SEG_TypeDef DDIC_Seg ѡ����Ƶ�SEG��
		   DDIC_Control_COM_TypeDef DDIC_Com ѡ����Ƶ�COM��
		   DDIC_Control_Status DDIC_Contr	����״̬
*���ڲ�����void
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