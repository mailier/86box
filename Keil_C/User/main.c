//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: main.c
//	ģ�鹦��	: ������
//  ˵��        : ����MCU��ʼ����������ͷ�ļ�
//************************************************************
/********************Includes************************************************************************/


/********************Includes************************************************************************/
#include "SC_Init.h"	//MCU��ʼ��ͷ�ļ��������̼�������ͷ�ļ�
#include "SC_it.h"
#include "..\Drivers\SCDriver_List.h"
#include "HeadFiles\CustomType.h"
#include "HeadFiles\UserExport.h"
#include "HeadFiles\FunctionType.h"
/*<UserCodeStart>*/
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
#include "EC06_key.h"
#include "BM8563.h"
#include "operation.h"
/*<UserCodeEnd>*/


/*****************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
******************************************************************************************************/
void main(void)
{	
/*** MCU��ʼ������ ***/
    SC_Init();
/*<UserCodeStart>*/
	BM8563_init();	
//	Encoder_EC11_Init(1);		//����ɨ���Ƿ���Ҫѭ����ʼ��
	while(1)
	{
			
		P50 = 1;//	
		MainFuction();

	}
/*<UserCodeEnd>*/


    
    
}
