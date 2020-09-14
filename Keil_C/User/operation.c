//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: interface.c
//	作者		: 
//	模块功能	: 界面交互
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************
#include "operation.h"
#include "NST1001.h"
#include "EC06_key.h"
#include "interface.h"
#include "BM8563.h"
#include "SC_it.h"


/* -----------------------------------------全局变量定义-----------------------------------*/
#define	 home_page   	0
#define	 time6_page   	1
#define	 copy_page 	 	2
#define	 FCtemper_page  3
#define  hotcool_page 	4 
#define	 wind_page    	5
#define	 holiday_page   6
#define	 clock_page     7
#define  menu_page      8


bit menu_clock_flag   = 0,
	menu_wind_flag    = 0,
	menu_holiday_flag = 0,
	menu_hotcool_flag = 0,
	menu_temp_flag    = 0,
	
	set_start_flag = 0,	
	set_over_flag = 0,
	
	blink_stop_flag = 0;

//	u8 week;				//星期
//	u8 mode;			    //模式
//	u16 temper;				//温度
//	u8 state;				//状态
//	u8 wind;				//风量
//	u8 hour;				//时间
//	u8 min;				
//	u8 group;				//组别

NOW  now = {0,1,0,0,0,0,0,0};

unsigned  char menu_grade = 0;
unsigned  int set_temper = 260;

/*********************************************
函数名：MainFuction
功  能：主函数
形  参：
返回值：
备  注：
时  间：2020/06/24
**********************************************/
void MainFuction(void)
{	
	
	/*right长按进入初始化时间设置*/
	if(Key_right_long == 1&&menu_grade == home_page&&menu_clock_flag == 0)		//right长按，设置初始时间
	{	
		Key_right_long = 0;						//右键长按标志清零
		set_start_flag = 1;
		menu_clock_flag = 1;				//关闭当前时钟显示标志位置一	
			
	}

	/*right短按进入4档风量自动挡设置*/
	if(Key_right_short == 1&&menu_grade == home_page&&menu_clock_flag == 0)		//right短按，设置风量模式
	{
					
		Key_right_short = 0;
		set_start_flag = 1;
		menu_wind_flag = 1;					//关闭当前风量显示标志位置一
		
	}
	
	/*left长按进入节能模式设置*/
	if(Key_left_long == 1&&menu_grade == home_page&&menu_clock_flag == 0)			//right长按，设置节能模式
	{	
		
		Key_left_long = 0;	
		set_start_flag = 1;		
		menu_holiday_flag = 1;				//关闭当前节能显示标志位置一	

	}

	/*left短按进入冷热节能切换设置*/
	if(Key_left_short == 1&&menu_grade == home_page&&menu_clock_flag == 0)		//right短按，设置冷热模式
	{
					
		Key_left_short = 0;
		set_start_flag = 1;	
		menu_hotcool_flag = 1;				//关闭当前冷热显示标志位置一

	}
	
	/*left旋转降低温度*/
	if(spin_left == 1&&menu_grade == home_page&&menu_clock_flag == 0)			//左旋转反转，调节温度
	{
		spin_left = 0;
		blink_start_count = 0;			
		menu_temp_flag = 1;
		set_temper--;					//递减
		
	}
	
	/*right旋转增加温度*/
	if(spin_right == 1&&menu_grade == home_page&&menu_clock_flag == 0)			//右旋转正转，调节温度
	{
		spin_right = 0;
		blink_start_count = 0;		
		menu_temp_flag = 1;
		set_temper++;					//累加
		
	}
	
	/*spin长按进入菜单*/
	if(spin_long == 1&&menu_grade == home_page&&menu_clock_flag == 0)			//右旋转正转，调节温度
	{
		spin_long = 0;
		menu_grade = menu_page;
		set_start_flag = 1;	
	}
	
//	/*长按旋转，判断调节不对，未加旋转分析*/
//	if(Encoder_EC11_Scan() == 4&&menu_grade == home_page)			//长按进入菜单
//	{
//			menu_grade = menu_page;					//		
//	}
	
	/*显示主界面*/
	if(menu_grade == home_page)						//主界面
	{

		main_part();								//显示主界面（时间状态）
	}
	/*设置时钟界面*/
	if(menu_clock_flag == 1&&menu_grade == home_page)
	{

		clock_part();
	}	
	/*设置风量界面*/
	if(menu_wind_flag == 1&&menu_clock_flag == 0&&menu_grade == home_page)
	{
		
		wind_part();
	}	
	/*设置节能界面*/
	if(menu_holiday_flag == 1&&menu_clock_flag == 0&&menu_grade == home_page)
	{
		
		holiday_part();
	}	
	/*设置冷热界面*/
	if(menu_hotcool_flag == 1&&menu_clock_flag == 0&&menu_grade == home_page)
	{
		
		hotcool_part();								
	}

	/*显示菜单栏*/
	if(menu_grade == menu_page)	
	{
	
		menu_bar();					//进入菜单模块选择			
	}
	if(menu_grade == time6_page)	
	{
	
		time6_part();				//进入定时6组时间模块选择			
	}
	if(menu_grade == copy_page)	
	{
	
		copy_part();				//进入复制粘贴模块选择			
	}
	if(menu_grade == FCtemper_page)	
	{
	
		FCtemper_part();			//进入摄氏度模块选择			
	}

}

/*********************************************
函数名：main_part
功  能：显示当前所有状态主界面
形  参：
返回值：
备  注：
时  间：2020/08/20
**********************************************/
void main_part(void)		//显示主界面（时间状态）
{
	static bit time_sign_blink,
				wind_sign_blink;

	
	/*时钟芯片的数据采集*/
		if(TIME_5msFlag == 1)			   //五毫秒调用时钟芯片
		{
			TIME_5msFlag = 0;
			BM8563_get_time();				
		}
		/*温度探头的数据采集*/
		if(temp_start_flag == 1)		    //一秒判断一次温度
		{				
			GetNST1001Temp();              //调用函数读取NST1001温度		  
		}	
		
	/*界面数据显示*/		
		if(TIME_100msFlag == 1)				//LCD500ms显示部分
		{
			TIME_100msFlag = 0;
			
			LCD_clean(TIMER);
			LCD_clean(TEMPER);
			LCD_clean(GROUP);
			
			/*时间的示数显示*/
			if(menu_clock_flag == 0)
			{	
				
				LCD_time(now.hour,now.min,now.week,1,1,1);		//显示时钟芯片时间
				DDIC_Control(DDIC_SEG6,DDIC_COM4,time_sign_blink);			//S23":"
			}
			/*风量的示数显示*/
			if(menu_wind_flag == 0)
				LCD_wind(now.wind);						//显示当前风量
			
			/*冷热节能的示数显示*/
			if(menu_hotcool_flag == 0&&menu_holiday_flag == 0)
				LCD_mode(now.mode);							//显示冷热节能模式
			
			/*温度探头的示数显示*/
			if(menu_temp_flag == 0)
			{	
				if(temp_judge_flag == 0)		//判断温度探头是否有效
				{
					now.temper = N_Temper;
					LCD_sTemperature(now.temper);			//显示当前温度
				}
				else
				{
					LCD_sTemperature(888);			//显示888再清除个别段显示为ERR
					LCD_Temper_error();
				}
					LCD_state(2);							//显示当前状态为“real”
			}
			
			
			if(now.wind == 0)
				DDIC_Control(DDIC_SEG20,DDIC_COM4,wind_sign_blink);		//风挡
			else
				DDIC_Control(DDIC_SEG20,DDIC_COM4,1);								
		}
		
	if(TIME_500msFlag == 1)
	{	
		TIME_500msFlag = 0;
		if(menu_clock_flag == 0)
			time_sign_blink = ~time_sign_blink;	
		if(now.wind == 0)
			wind_sign_blink = ~wind_sign_blink;
	}

		
	/*调节温度的示数显示*/
		if(menu_temp_flag == 1)
		{	
			now.temper = set_temper;
			LCD_sTemperature(now.temper);			//显示设置温度
			LCD_state(1);			//显示当前状态为“set”
			
		}
		if(blink_start_count >= 4)
			menu_temp_flag = 0;
}	

/*********************************************
函数名：hotcool_part
功  能：显示设置冷热节能模式
形  参：
返回值：
备  注：
时  间：2020/08/20
**********************************************/
void hotcool_part(void)
{
	
	now.mode++;
	if(now.mode >= 3)
		now.mode = 1;
	menu_hotcool_flag = 0;
}

/*********************************************
函数名：wind_part
功  能：显示设置风量模式
形  参：
返回值：
备  注：
时  间：2020/08/20
**********************************************/
void wind_part(void)
{

	
	now.wind++;
//		set_wind++;
	if(now.wind == 5)
		now.wind = 0;
	menu_wind_flag = 0;
}

/*********************************************
函数名：holiday_part
功  能：显示设置假期模式
形  参：
返回值：
备  注：
时  间：2020/08/20
**********************************************/
void holiday_part(void)
{
	now.mode = 3;
	menu_holiday_flag = 0;
	
}

/*********************************************
函数名：clock_part
功  能：显示设置时间模式
形  参：
返回值：
备  注：
时  间：2020/08/20
**********************************************/
void clock_part(void)
{
	static uint8_t clock_sect = 1;
	static uint8_t set_hour = 0;
	static uint8_t set_min = 0;
	static uint8_t set_week = 0;
			
	static bit hour_flag = 0,
				min_flag = 0,
				week_flag = 0;
	
static bit hour_blink_flag = 1,
			min_blink_flag = 1,
			week_blink_flag = 1;

	if((spin_short == 1||Key_right_short == 1)&&set_start_flag == 0)
	{
		clock_sect++;
		spin_short = 0;
		Key_right_short	= 0;	
	}
	if(Key_left_short == 1&&set_start_flag == 0)
	{
		clock_sect--;
		Key_left_short = 0;
		if(clock_sect == 0)
			clock_sect = 3;		
	}	
	
	if(set_start_flag == 1)
	{
		set_start_flag = 0;
		set_hour = now.hour;
		set_min = now.min;
		set_week = now.week;
	}
	
	switch(clock_sect)						//中间键按下调节位置
	{
		case 1:	
				hour_flag = 1;
				min_flag = 0;
				week_flag = 0;
				
			if(spin_right == 1&&menu_grade == home_page)		//up增加数字	
			{
				set_hour++;
				spin_right = 0;
				blink_start_count = 0;
				if(set_hour >= 24)				//24时钟数值循环
					set_hour = 0;
			}
			if(spin_left == 1&&menu_grade == home_page)
			{	
				set_hour--;
				spin_left = 0;
				blink_start_count = 0;
				if(set_hour == 255)				//uchar0-255，反向循环
					set_hour = 23;
			}
										
			break;
		case 2:
				hour_flag = 0;
				min_flag = 1;
				week_flag = 0;
				
			if(spin_right == 1&&menu_grade == home_page)		//up增加数字	
			{
				set_min++;
				spin_right = 0;
				blink_start_count = 0;
				if(set_min >= 60)				//60分钟数值循环
					set_min = 0;	
			}
			if(spin_left == 1&&menu_grade == home_page)
			{	
				set_min--;
				spin_left = 0;		
				blink_start_count = 0;
				if(set_min == 255)				//uchar0-255,反向循环
					set_min = 59;	
			}
												
			break;	
		case 3:
				hour_flag = 0;
				min_flag = 0;
				week_flag = 1;
				
			if(spin_right == 1&&menu_grade == home_page)		//up增加数字	
			{
				set_week++;
				spin_right = 0;
				blink_start_count = 0;
				if(set_week >= 7)				//60分钟数值循环
					set_week = 0;				
			}
			if(spin_left == 1&&menu_grade == home_page)
			{	
				set_week--;
				spin_left = 0;
				blink_start_count = 0;
				if(set_week == 255)				//uchar0-255,反向循环
					set_week = 6;
			}
		
			break;
		case 4:
				set_over_flag = 1;			//开启设置结束标志

			break;
	}
	
	if(TIME_300msFlag == 1)
	{
		TIME_300msFlag = 0;
		if(hour_flag == 1)		
		{	
			hour_blink_flag = ~hour_blink_flag;
			min_blink_flag = 1;
			week_blink_flag = 1;
		}
		if(min_flag == 1)
		{	
			hour_blink_flag = 1;
			min_blink_flag = ~min_blink_flag;
			week_blink_flag = 1;
		}
		if(week_flag == 1)
		{
			hour_blink_flag = 1;
			min_blink_flag = 1;
			week_blink_flag = ~week_blink_flag;
		}
	}
	
		if(blink_start_count >= 2)
			LCD_time(set_hour,set_min,set_week,hour_blink_flag,min_blink_flag,week_blink_flag);
		else
			LCD_time(set_hour,set_min,set_week,1,1,1);

	DDIC_Control(DDIC_SEG6,DDIC_COM4,1);		//S23":"
	
	if(blink_start_count >= 10)	
		blink_start_count = 2;
	
	
	if(set_over_flag == 1)			//设置时间完成，改变主界面标志位，返回主界面
	{
		now.week = set_week;
		
		set_min =(set_min/10*16)+set_min%10;			//分钟十进制数对应为BCD 
		set_hour =(set_hour/10*16)+set_hour%10;			//时钟十进制数对应为BCD 

		BM8563_send_add_byte(0x03,set_min);            
		BM8563_send_add_byte(0x04,set_hour);  

		set_over_flag = 0;			//标志位复原
		menu_clock_flag = 0;		
		clock_sect = 1;		
	}
	
}

/*********************************************
函数名：menu_bar
功  能：显示菜单模式
形  参：
返回值：
备  注：
时  间：2020/08/20
**********************************************/
void menu_bar(void)
{
	static uint8_t menu_sect = 1;
			uint8_t group = 0;
	static bit menu_time6_flag = 0,
				menu_copy_flag = 0,
				menu_FCtemper_flag = 0;		
//				shift_flag = 0;
	
	if(set_start_flag == 1)
	{
		set_start_flag = 0;
		LCD_cleanALL();
		menu_sect = 1;
	}
	
	if(spin_right == 1&&menu_grade == menu_page)
	{
		menu_sect++;

		spin_right = 0;
	}	
	
	if(spin_left == 1&&menu_grade == menu_page)
	{
		menu_sect--;

		spin_left = 0;
		if(menu_sect == 0)
			menu_sect = 3;		
	}		
	
	if(Key_left_short == 1&&menu_grade == menu_page)
	{	
		menu_grade = home_page;
		Key_left_short = 0;		

	}

	switch(menu_sect)						//中间键按下调节位置
	{
		case 1:	
				menu_time6_flag = 1;
				menu_copy_flag = 0;
				menu_FCtemper_flag = 0;
		
			if(Key_right_short == 1||spin_short == 1&&menu_grade == menu_page)
			{	
				menu_grade = time6_page;
				Key_right_short = 0;
				spin_short = 0;
				set_start_flag = 1;
			}
										
			break;
		case 2:
				menu_time6_flag = 0;
				menu_copy_flag = 1;
				menu_FCtemper_flag = 0;
		
			if(Key_right_short == 1||spin_short == 1&&menu_grade == menu_page)
			{	
				menu_grade = copy_page;
				Key_right_short = 0;
				spin_short = 0;				
				set_start_flag = 1;
			}
												
			break;	
		case 3:
				menu_time6_flag = 0;
				menu_copy_flag = 0;
				menu_FCtemper_flag = 1;
		
			if(Key_right_short == 1&&spin_short == 1&&menu_grade == menu_page)
			{	
				menu_grade = FCtemper_page;
				Key_right_short = 0;
				spin_short = 0;
				set_start_flag = 1;
			}
		
			break;
		case 4:
				menu_sect = 1;					//

			break;
	}
	if(TIME_100msFlag == 1)
	{	
		LCD_clean(TIMER);
		LCD_clean(TEMPER);
		LCD_clean(GROUP);
		DDIC_Control(DDIC_SEG6,DDIC_COM4,0);			//S23":"
		
		TIME_100msFlag = 0;
		
		if(menu_time6_flag == 1)
		{
			LCD_number(1,0,1);
			LCD_number(2,1,1);
			for(group = 0;group < 7;group++)
			LCD_group(group);

			LCD_time(now.hour,now.min,now.week,1,1,1);		//显示时钟芯片时间
			DDIC_Control(DDIC_SEG6,DDIC_COM4,1);			//S23":"
		}	
		else if(menu_copy_flag == 1)
		{
			LCD_number(1,0,1);
			LCD_number(2,2,1);
			LCD_week(now.week,1);
			LCD_group(7);
			LCD_group(8);		
		}	
		else if(menu_FCtemper_flag == 1)
		{
			LCD_clean(GROUP);
			LCD_number(1,0,1);
			LCD_number(2,3,1);
			DDIC_Control(DDIC_SEG3,DDIC_COM7,DDIC_Control_ON);		//S22"F"
			DDIC_Control(DDIC_SEG1,DDIC_COM7,DDIC_Control_ON);		//S21"C"	
		}	
	}	
	
}
/*********************************************
函数名：time6_part
功  能：设置6组时间模式
形  参：
返回值：
备  注：
时  间：2020/08/26
**********************************************/
void time6_part(void)
{
 static  uint8_t time6_week_sect = 0;
	if(set_start_flag == 1)			//首次进入标志位，清屏
	{
		LCD_cleanALL();
		set_start_flag = 0;			//关闭首次进入标志
	}
		
	if(spin_right == 1||Key_right_short == 1&&menu_grade == time6_page)
	{
		time6_week_sect++;
		spin_right = 0;
	}	
	
	if(spin_left == 1||Key_left_short == 1&&menu_grade == time6_page)
	{
		time6_week_sect--;
		spin_left = 0;		
	}
	
	if(spin_short == 1&&menu_grade == time6_page)
	{
		set_over_flag = 1;
	}
	
	
}	

/*********************************************
函数名：copy_part
功  能：复制粘贴模式
形  参：
返回值：
备  注：
时  间：2020/08/26
**********************************************/
void copy_part(void)
{
	
	
}	

/*********************************************
函数名：FCtemper_part
功  能：摄氏度模式选择
形  参：
返回值：
备  注：
时  间：2020/08/26
**********************************************/
void FCtemper_part(void)
{
	
	
}