//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: main.c
//	模块功能	: 主函数
//  说明        : 包含MCU初始化函数及其头文件
//************************************************************
/********************Includes************************************************************************/


/********************Includes************************************************************************/
#include "SC_Init.h"	//MCU初始化头文件，包含固件库所有头文件
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
/*** MCU初始化函数 ***/
    SC_Init();
/*<UserCodeStart>*/
	BM8563_init();	
//	Encoder_EC11_Init(1);		//按键扫描是否需要循环初始化
	while(1)
	{
			
		P50 = 1;//	
		MainFuction();

	}
/*<UserCodeEnd>*/


    
    
}
