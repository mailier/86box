//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: NST1001.c
//	����: 
//	ģ�鹦��	: �¶Ȳɼ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************
#include "NST1001.h"
#include "SC_it.h"
#include "interface.h"

bit int1_first_flag = 0;		//��һ�βɼ��¶ȱ�־λ

bit temp_judge_flag = 0;		//�ж��¶���Ч��־λ

bit temp_start_flag = 0;		//�ɼ��¶ȿ�ʼ��־λ
bit temp_over_flag = 0;			//�ɼ��¶Ƚ�����־λ

unsigned char temp_collect_timer2 = 0;		//�ɼ��¶ȿ�ʼʱ��	
unsigned char temp_over_timer2 = 0;		//�ɼ��¶Ƚ���ʱ��
unsigned int temp_num = 0;					//�ɼ��¶�������
unsigned int N_Temper = 0;					//�¶Ƚ�����϶�

//unsigned int moment_num = 0;

/* NST1001�¶ȶ�ȡ���� */
void GetNST1001Temp()
{	

	static unsigned int moment_num = 0;

	
	if(int1_first_flag == 1)		//��һ�βɼ��¶ȱ�־λ
	{
		temp_over_flag = 0;			//���������־λ
		temp_collect_timer2	= 0;	//����¶Ȳɼ�ʱ��
		temp_over_timer2 = 0;		//����������ʱ��
//		temp_num = 0;				//���������
		
		NST1001_IO = 1;	 			//������NST1001
		NST1001_DQ = 1;			    //��������IO��׼������

		int1_first_flag = 0;
	}

		if(temp_collect_timer2<15)		
		{	
			INT0_ITConfig(ENABLE,1);	//���ж�ʹ��
			temp_num = 0;				//���������
		}
		if(temp_collect_timer2>20)		//��ʼ�¶������ȡ
		{
			
			if(temp_num != moment_num)
			{
				
				moment_num = temp_num;
				temp_over_timer2=0;
			}
			else						//
			{
				temp_over_flag = 1;		//���������־λ
				
			}	

	   }
	
	if(temp_over_timer2>15)				//�¶������ȡ����
		
	{	
		
		if(temp_num > 0)				//�ж���������Ч
		{	
			N_Temper = ((long int)temp_num*625 - 500625)/1000;
			
			
			temp_judge_flag = 0;
		}
		else
			temp_judge_flag = 1;		//������Ϊ����Ϊ��Ч���ж�λ��һ
			
		if(temp_num < 1281)  				//С��30��
	{
		 
			N_Temper = N_Temper + (N_Temper - 30)*0.005;
	}
		if((temp_num > 1281) && (temp_num < 2401))  //30��<�¶�<100��
	{
			N_Temper = N_Temper;
	}
		if(temp_num > 2401)				//����100��
	{
			N_Temper = N_Temper + (100 - N_Temper)*0.012;
	}
		

		INT0_ITConfig(DISABLE,LOW);	//�ر��ж�	
	
		NST1001_IO = 0;	 			//�����ر�NST1001
		NST1001_DQ = 0;			    //��������IO��
		
		temp_over_flag = 0;			//���������־λ
		temp_start_flag = 0;		//���忪ʼ��־λ
	
		temp_collect_timer2 = 0;	//�������ɼ�ʱ��
		temp_over_timer2 = 0;		//�����������ʱ��ʱ��

		temp_num = 0;				//���������
	}
	
}
