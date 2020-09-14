//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: main.c
//	模块功能	: 主函数
//  说明        : 包含MCU初始化函数及其头文件
//************************************************************

#include "SC_Init.h"	//MCU初始化头文件，包含固件库所有头文件
#include "SC_it.h"
#include "..\Drivers\SCDriver_List.h"
void main(void)
{	
    /*<UserCodeStart>*/
    /*<UserCodeEnd>*/
	/*** MCU初始化函数 ***/
	SC_Init();

}


