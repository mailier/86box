//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: interface.c
//	����		: 
//	ģ�鹦��	: ���潻��
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************
#include "operation.h"
#include "NST1001.h"
#include "EC06_key.h"
#include "interface.h"
#include "BM8563.h"
#include "SC_it.h"


/* -----------------------------------------ȫ�ֱ�������-----------------------------------*/
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

//	u8 week;				//����
//	u8 mode;			    //ģʽ
//	u16 temper;				//�¶�
//	u8 state;				//״̬
//	u8 wind;				//����
//	u8 hour;				//ʱ��
//	u8 min;				
//	u8 group;				//���

NOW  now = {0,1,0,0,0,0,0,0};

unsigned  char menu_grade = 0;
unsigned  int set_temper = 260;

/*********************************************
��������MainFuction
��  �ܣ�������
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/06/24
**********************************************/
void MainFuction(void)
{	
	
	/*right���������ʼ��ʱ������*/
	if(Key_right_long == 1&&menu_grade == home_page&&menu_clock_flag == 0)		//right���������ó�ʼʱ��
	{	
		Key_right_long = 0;						//�Ҽ�������־����
		set_start_flag = 1;
		menu_clock_flag = 1;				//�رյ�ǰʱ����ʾ��־λ��һ	
			
	}

	/*right�̰�����4�������Զ�������*/
	if(Key_right_short == 1&&menu_grade == home_page&&menu_clock_flag == 0)		//right�̰������÷���ģʽ
	{
					
		Key_right_short = 0;
		set_start_flag = 1;
		menu_wind_flag = 1;					//�رյ�ǰ������ʾ��־λ��һ
		
	}
	
	/*left�����������ģʽ����*/
	if(Key_left_long == 1&&menu_grade == home_page&&menu_clock_flag == 0)			//right���������ý���ģʽ
	{	
		
		Key_left_long = 0;	
		set_start_flag = 1;		
		menu_holiday_flag = 1;				//�رյ�ǰ������ʾ��־λ��һ	

	}

	/*left�̰��������Ƚ����л�����*/
	if(Key_left_short == 1&&menu_grade == home_page&&menu_clock_flag == 0)		//right�̰�����������ģʽ
	{
					
		Key_left_short = 0;
		set_start_flag = 1;	
		menu_hotcool_flag = 1;				//�رյ�ǰ������ʾ��־λ��һ

	}
	
	/*left��ת�����¶�*/
	if(spin_left == 1&&menu_grade == home_page&&menu_clock_flag == 0)			//����ת��ת�������¶�
	{
		spin_left = 0;
		blink_start_count = 0;			
		menu_temp_flag = 1;
		set_temper--;					//�ݼ�
		
	}
	
	/*right��ת�����¶�*/
	if(spin_right == 1&&menu_grade == home_page&&menu_clock_flag == 0)			//����ת��ת�������¶�
	{
		spin_right = 0;
		blink_start_count = 0;		
		menu_temp_flag = 1;
		set_temper++;					//�ۼ�
		
	}
	
	/*spin��������˵�*/
	if(spin_long == 1&&menu_grade == home_page&&menu_clock_flag == 0)			//����ת��ת�������¶�
	{
		spin_long = 0;
		menu_grade = menu_page;
		set_start_flag = 1;	
	}
	
//	/*������ת���жϵ��ڲ��ԣ�δ����ת����*/
//	if(Encoder_EC11_Scan() == 4&&menu_grade == home_page)			//��������˵�
//	{
//			menu_grade = menu_page;					//		
//	}
	
	/*��ʾ������*/
	if(menu_grade == home_page)						//������
	{

		main_part();								//��ʾ�����棨ʱ��״̬��
	}
	/*����ʱ�ӽ���*/
	if(menu_clock_flag == 1&&menu_grade == home_page)
	{

		clock_part();
	}	
	/*���÷�������*/
	if(menu_wind_flag == 1&&menu_clock_flag == 0&&menu_grade == home_page)
	{
		
		wind_part();
	}	
	/*���ý��ܽ���*/
	if(menu_holiday_flag == 1&&menu_clock_flag == 0&&menu_grade == home_page)
	{
		
		holiday_part();
	}	
	/*�������Ƚ���*/
	if(menu_hotcool_flag == 1&&menu_clock_flag == 0&&menu_grade == home_page)
	{
		
		hotcool_part();								
	}

	/*��ʾ�˵���*/
	if(menu_grade == menu_page)	
	{
	
		menu_bar();					//����˵�ģ��ѡ��			
	}
	if(menu_grade == time6_page)	
	{
	
		time6_part();				//���붨ʱ6��ʱ��ģ��ѡ��			
	}
	if(menu_grade == copy_page)	
	{
	
		copy_part();				//���븴��ճ��ģ��ѡ��			
	}
	if(menu_grade == FCtemper_page)	
	{
	
		FCtemper_part();			//�������϶�ģ��ѡ��			
	}

}

/*********************************************
��������main_part
��  �ܣ���ʾ��ǰ����״̬������
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/20
**********************************************/
void main_part(void)		//��ʾ�����棨ʱ��״̬��
{
	static bit time_sign_blink,
				wind_sign_blink;

	
	/*ʱ��оƬ�����ݲɼ�*/
		if(TIME_5msFlag == 1)			   //��������ʱ��оƬ
		{
			TIME_5msFlag = 0;
			BM8563_get_time();				
		}
		/*�¶�̽ͷ�����ݲɼ�*/
		if(temp_start_flag == 1)		    //һ���ж�һ���¶�
		{				
			GetNST1001Temp();              //���ú�����ȡNST1001�¶�		  
		}	
		
	/*����������ʾ*/		
		if(TIME_100msFlag == 1)				//LCD500ms��ʾ����
		{
			TIME_100msFlag = 0;
			
			LCD_clean(TIMER);
			LCD_clean(TEMPER);
			LCD_clean(GROUP);
			
			/*ʱ���ʾ����ʾ*/
			if(menu_clock_flag == 0)
			{	
				
				LCD_time(now.hour,now.min,now.week,1,1,1);		//��ʾʱ��оƬʱ��
				DDIC_Control(DDIC_SEG6,DDIC_COM4,time_sign_blink);			//S23":"
			}
			/*������ʾ����ʾ*/
			if(menu_wind_flag == 0)
				LCD_wind(now.wind);						//��ʾ��ǰ����
			
			/*���Ƚ��ܵ�ʾ����ʾ*/
			if(menu_hotcool_flag == 0&&menu_holiday_flag == 0)
				LCD_mode(now.mode);							//��ʾ���Ƚ���ģʽ
			
			/*�¶�̽ͷ��ʾ����ʾ*/
			if(menu_temp_flag == 0)
			{	
				if(temp_judge_flag == 0)		//�ж��¶�̽ͷ�Ƿ���Ч
				{
					now.temper = N_Temper;
					LCD_sTemperature(now.temper);			//��ʾ��ǰ�¶�
				}
				else
				{
					LCD_sTemperature(888);			//��ʾ888������������ʾΪERR
					LCD_Temper_error();
				}
					LCD_state(2);							//��ʾ��ǰ״̬Ϊ��real��
			}
			
			
			if(now.wind == 0)
				DDIC_Control(DDIC_SEG20,DDIC_COM4,wind_sign_blink);		//�絲
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

		
	/*�����¶ȵ�ʾ����ʾ*/
		if(menu_temp_flag == 1)
		{	
			now.temper = set_temper;
			LCD_sTemperature(now.temper);			//��ʾ�����¶�
			LCD_state(1);			//��ʾ��ǰ״̬Ϊ��set��
			
		}
		if(blink_start_count >= 4)
			menu_temp_flag = 0;
}	

/*********************************************
��������hotcool_part
��  �ܣ���ʾ�������Ƚ���ģʽ
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/20
**********************************************/
void hotcool_part(void)
{
	
	now.mode++;
	if(now.mode >= 3)
		now.mode = 1;
	menu_hotcool_flag = 0;
}

/*********************************************
��������wind_part
��  �ܣ���ʾ���÷���ģʽ
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/20
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
��������holiday_part
��  �ܣ���ʾ���ü���ģʽ
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/20
**********************************************/
void holiday_part(void)
{
	now.mode = 3;
	menu_holiday_flag = 0;
	
}

/*********************************************
��������clock_part
��  �ܣ���ʾ����ʱ��ģʽ
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/20
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
	
	switch(clock_sect)						//�м�����µ���λ��
	{
		case 1:	
				hour_flag = 1;
				min_flag = 0;
				week_flag = 0;
				
			if(spin_right == 1&&menu_grade == home_page)		//up��������	
			{
				set_hour++;
				spin_right = 0;
				blink_start_count = 0;
				if(set_hour >= 24)				//24ʱ����ֵѭ��
					set_hour = 0;
			}
			if(spin_left == 1&&menu_grade == home_page)
			{	
				set_hour--;
				spin_left = 0;
				blink_start_count = 0;
				if(set_hour == 255)				//uchar0-255������ѭ��
					set_hour = 23;
			}
										
			break;
		case 2:
				hour_flag = 0;
				min_flag = 1;
				week_flag = 0;
				
			if(spin_right == 1&&menu_grade == home_page)		//up��������	
			{
				set_min++;
				spin_right = 0;
				blink_start_count = 0;
				if(set_min >= 60)				//60������ֵѭ��
					set_min = 0;	
			}
			if(spin_left == 1&&menu_grade == home_page)
			{	
				set_min--;
				spin_left = 0;		
				blink_start_count = 0;
				if(set_min == 255)				//uchar0-255,����ѭ��
					set_min = 59;	
			}
												
			break;	
		case 3:
				hour_flag = 0;
				min_flag = 0;
				week_flag = 1;
				
			if(spin_right == 1&&menu_grade == home_page)		//up��������	
			{
				set_week++;
				spin_right = 0;
				blink_start_count = 0;
				if(set_week >= 7)				//60������ֵѭ��
					set_week = 0;				
			}
			if(spin_left == 1&&menu_grade == home_page)
			{	
				set_week--;
				spin_left = 0;
				blink_start_count = 0;
				if(set_week == 255)				//uchar0-255,����ѭ��
					set_week = 6;
			}
		
			break;
		case 4:
				set_over_flag = 1;			//�������ý�����־

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
	
	
	if(set_over_flag == 1)			//����ʱ����ɣ��ı��������־λ������������
	{
		now.week = set_week;
		
		set_min =(set_min/10*16)+set_min%10;			//����ʮ��������ӦΪBCD 
		set_hour =(set_hour/10*16)+set_hour%10;			//ʱ��ʮ��������ӦΪBCD 

		BM8563_send_add_byte(0x03,set_min);            
		BM8563_send_add_byte(0x04,set_hour);  

		set_over_flag = 0;			//��־λ��ԭ
		menu_clock_flag = 0;		
		clock_sect = 1;		
	}
	
}

/*********************************************
��������menu_bar
��  �ܣ���ʾ�˵�ģʽ
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/20
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

	switch(menu_sect)						//�м�����µ���λ��
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

			LCD_time(now.hour,now.min,now.week,1,1,1);		//��ʾʱ��оƬʱ��
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
��������time6_part
��  �ܣ�����6��ʱ��ģʽ
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/26
**********************************************/
void time6_part(void)
{
 static  uint8_t time6_week_sect = 0;
	if(set_start_flag == 1)			//�״ν����־λ������
	{
		LCD_cleanALL();
		set_start_flag = 0;			//�ر��״ν����־
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
��������copy_part
��  �ܣ�����ճ��ģʽ
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/26
**********************************************/
void copy_part(void)
{
	
	
}	

/*********************************************
��������FCtemper_part
��  �ܣ����϶�ģʽѡ��
��  �Σ�
����ֵ��
��  ע��
ʱ  �䣺2020/08/26
**********************************************/
void FCtemper_part(void)
{
	
	
}