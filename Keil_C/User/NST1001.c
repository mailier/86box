//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: NST1001.c
//	作者: 
//	模块功能	: 温度采集
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************
#include "NST1001.h"
#include "SC_it.h"
#include "interface.h"

bit int1_first_flag = 0;		//第一次采集温度标志位

bit temp_judge_flag = 0;		//判断温度有效标志位

bit temp_start_flag = 0;		//采集温度开始标志位
bit temp_over_flag = 0;			//采集温度结束标志位

unsigned char temp_collect_timer2 = 0;		//采集温度开始时间	
unsigned char temp_over_timer2 = 0;		//采集温度结束时间
unsigned int temp_num = 0;					//采集温度脉冲量
unsigned int N_Temper = 0;					//温度结果摄氏度

//unsigned int moment_num = 0;

/* NST1001温度读取函数 */
void GetNST1001Temp()
{	

	static unsigned int moment_num = 0;

	
	if(int1_first_flag == 1)		//第一次采集温度标志位
	{
		temp_over_flag = 0;			//脉冲结束标志位
		temp_collect_timer2	= 0;	//清除温度采集时间
		temp_over_timer2 = 0;		//清除脉冲结束时间
//		temp_num = 0;				//清空脉冲数
		
		NST1001_IO = 1;	 			//上拉打开NST1001
		NST1001_DQ = 1;			    //上拉计数IO口准备计数

		int1_first_flag = 0;
	}

		if(temp_collect_timer2<15)		
		{	
			INT0_ITConfig(ENABLE,1);	//打开中断使能
			temp_num = 0;				//清空脉冲量
		}
		if(temp_collect_timer2>20)		//开始温度脉冲读取
		{
			
			if(temp_num != moment_num)
			{
				
				moment_num = temp_num;
				temp_over_timer2=0;
			}
			else						//
			{
				temp_over_flag = 1;		//脉冲结束标志位
				
			}	

	   }
	
	if(temp_over_timer2>15)				//温度脉冲读取结束
		
	{	
		
		if(temp_num > 0)				//判断脉冲量有效
		{	
			N_Temper = ((long int)temp_num*625 - 500625)/1000;
			
			
			temp_judge_flag = 0;
		}
		else
			temp_judge_flag = 1;		//脉冲量为零则为无效，判断位置一
			
		if(temp_num < 1281)  				//小于30℃
	{
		 
			N_Temper = N_Temper + (N_Temper - 30)*0.005;
	}
		if((temp_num > 1281) && (temp_num < 2401))  //30℃<温度<100℃
	{
			N_Temper = N_Temper;
	}
		if(temp_num > 2401)				//大于100℃
	{
			N_Temper = N_Temper + (100 - N_Temper)*0.012;
	}
		

		INT0_ITConfig(DISABLE,LOW);	//关闭中断	
	
		NST1001_IO = 0;	 			//下拉关闭NST1001
		NST1001_DQ = 0;			    //下拉计数IO口
		
		temp_over_flag = 0;			//脉冲结束标志位
		temp_start_flag = 0;		//脉冲开始标志位
	
		temp_collect_timer2 = 0;	//清除脉冲采集时间
		temp_over_timer2 = 0;		//清除脉冲间隔定时器时间

		temp_num = 0;				//清空脉冲数
	}
	
}
