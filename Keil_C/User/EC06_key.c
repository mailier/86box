//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: EC06_key.c
//	����		: 
//	ģ�鹦��	: ��ת������
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************
#include "EC06_key.h"
//#include "interface.h"
//#include "SC_it.h"

bit spin_int1_flag = 0;

bit Key_left_short;
bit Key_right_short;

bit Key_left_long;
bit Key_right_long;

bit spin_left 		= 0,
	spin_right		= 0,
	
	spin_short		= 0,
	spin_long		= 0,

	spin_long_left	= 0,
	spin_long_right = 0;


uint32_t Temper; 


//ע�����EC11��ת��������ɨ��ʱ����������1~4ms֮��
//����5ms�����ϵ�ɨ��ʱ���ڿ�����תʱ���ܻ�������ת����




//*******************************************************************/
//���ܣ���ʼ��EC11��ת��������ز���
//�βΣ�EC11��ת������������-->>  unsigned char Set_EC11_TYPE  <<--  ��0----һ��λ��Ӧһ���壻1�����0��----����λ��Ӧһ���塣
//���أ���
//��⣺��EC11��ת������������IO����IO��ģʽ���á��Լ�����صı������г�ʼ��
//*******************************************************************/
//void Encoder_EC11_Init(unsigned char Set_EC11_TYPE)
//{
//    //IO��ģʽ��ʼ������ʼ��EC11��IO��Ϊ׼˫��ģʽ
////    P35_QB();
////    P36_QB();
////    P37_QB();
//    
//    EC11_A_Now = 0;
//    EC11_B_Now = 0;
////    EC11_Key = 0;

////    //EC11����ѡ��0-һ��λһ���壻1-����λһ����
////    if(Set_EC11_TYPE == 0)
////    {
////        EC11_Type = 0;
////    }
////    else
////    {
////        EC11_Type = 1;
////    }

////    //�����ϵ�ʱEC11��ťλ�ò�ȷ������һ�ζ�������
////    EC11_A_Last = EC11_A_Now;   
////    EC11_B_Last = EC11_B_Now;

////    //--------��������������ͱ�־λ--------//
////    EC11_KEY_COUNT = 0;                     //EC11��������������
////    EC11_KEY_DoubleClick_Count = 0;         //EC11����˫������������
////    FLAG_EC11_KEY_ShotClick = 0;            //EC11�����̰�������־
////    FLAG_EC11_KEY_LongClick = 0;            //EC11��������������־
////    FLAG_EC11_KEY_DoubleClick = 0;          //EC11����˫��������־
//	
//}

/**************************************************
*�������ƣ�void key_scan(void)
*�������ܣ����Ұ���ɨ��
*��ڲ�����
*���ڲ�����void
**************************************************/
void key_scan(void)	
{	
	static unsigned char Key_left_count;
	static unsigned char Key_right_count;
	static unsigned char EC11_Key_count;
	
	 /*left��ɨ��*/
	if(keyleft == 0)								//left����������
      {
		  if(Key_left_count<250)					//left�����¼���
				Key_left_count++; 				
		  if(Key_left_count>=200)					//�жϳ���
			{		
				Key_left_long=1;   //bit			//������־λ��һ
			}
	  }
	if(keyleft == 1)								//left���ɿ��ж�
	 {
		  if(Key_left_count<50&&Key_left_count>0)	//�ж϶̰�		
			{		
				Key_left_short=1;  //bit			//�̰���һ
			}
			Key_left_count = 0;						//left����������
			Key_left_long = 0;	
	 }
	 
	  /*right��ɨ��*/
     if(keyright == 0)							//right����������
      {
		  if(Key_right_count<250)			    //right�����¼���
				Key_right_count++; 
		  if(Key_right_count>=200)				//�жϳ���
			{		
				Key_right_long=1; 				//������־λ��һ			
			}
	  }
	if(keyright == 1)									//right���ɿ��ж�
	 {
		  if(Key_right_count<50&&Key_right_count>0)		//�ж϶̰�
			{			
				Key_right_short=1;  //bit				//�̰���һ	
			}
			Key_right_count = 0;							//right����������	
			Key_right_long = 0;
      }
	 
	  /*middle��ɨ��*/
	 if(EC11_Key == 0)							//middle����������
      {
		  if(EC11_Key_count<250)			    //middle�����¼���
				EC11_Key_count++; 
		  if(EC11_Key_count>=200)				//�жϳ���
			{		
				spin_long=1; 				//������־λ��һ			
			}
	  }
	if(EC11_Key == 1)									//middle���ɿ��ж�
	 {
		  if(EC11_Key_count<50&&EC11_Key_count>0)		//�ж϶̰�
			{			
				spin_short=1;  //bit				//�̰���һ	
			}
			EC11_Key_count = 0;							//middle����������	
			spin_long = 0;
      }
	 
}

/**************************************************
*�������ƣ�void spin_scan(void)
*�������ܣ���ת������ɨ��
*��ڲ�������ת��־��INT2�жϲɼ�������ɨ����TIME2�����������û�ɼ�һ�ζ�����TIME2��װһ��
		  Ϊ��ÿ�ɼ�һ�ζ�����1ms����붨ʱ��		
*���ڲ�����void
**************************************************/
void spin_scan(void)	
{	
	if(spin_int1_flag == 1)        //��A��������ʱ�ɼ�B��ǰ��״̬������B����һ�ε�״̬���жԱȡ�
	{                                   //��A 0->1 ʱ��B 1->0 ��ת����A 1->0 ʱ��B 0->1 ��ת��
									  //��A 0->1 ʱ��B 0->1 ��ת����A 1->0 ʱ��B 1->0 ��ת
		if(EC11_A_Now == 1)     //EC11_A����һ��״̬��ȣ�Ϊ������
		{
		  
			if(EC11_B_Now == 0)   //EC11_B����һ��״̬��ȣ�Ϊ�½���
				spin_right = 1;                         //��ת

			if(EC11_B_Now == 1)   //EC11_B����һ��״̬��ȣ�Ϊ������               
				spin_left = 1;                        //��ת
		}
		else					 //EC11_A����һ��״̬��ȣ�Ϊ�½���
		{  
			
			if(EC11_B_Now == 1)  //A������ʱ���ɼ���B������Ϊ0
				spin_right = 1;                                 //��ת

			if(EC11_B_Now == 0)  //A������ʱ���ɼ���B������Ϊ1
				spin_left = 1;                                //��ת
		}
   
		spin_int1_flag = 0;
	}
}

//*******************************************************************/
//���ܣ�ɨ��EC11��ת�������Ķ��������������ظ�������������ʹ��
//�βΣ�EC11��ת������������-->>  unsigned char Set_EC11_TYPE  <<--  ��0----һ��λ��Ӧһ���壻1�����0��----����λ��Ӧһ����
//���أ�EC11��ת��������ɨ����-->>  char ScanResult  -->>  0���޶�����1����ת�� -1����ת��2��ֻ���°�����3�����Ű�����ת��-3�����Ű�����ת
//��⣺ֻɨ��EC11��ת��������û�ж������������ǵڼ��ΰ��°����򳤰���˫��������ֱֵ����Ϊ�βδ��� [ void Encoder_EC11_Analyze(char EC11_Value); ] ����ʹ��
//*******************************************************************/
char Encoder_EC11_Scan()
{
//���´���A��B��һ��ֵ�ı�������Ϊ��̬ȫ�ֱ����������EC11��Ӧ��IO������ʼ��
//  static char EC11_A_Last = 0;
//  static char EC11_B_Last = 0;
    char ScanResult = 0;    //���ر�����ɨ���������ڷ����������Ķ���
                            //����ֵ��ȡֵ��   0���޶�����      1����ת��           -1����ת��  
                            //                2��ֻ���°�����    3�����Ű�����ת��   -3�����Ű�����ת
                            //======================================================//
//    if(EC11_Type == 0)      //================һ��λ��Ӧһ�����EC11================//
//    {                       //======================================================//
//        if(EC11_A_Now != EC11_A_Last)   //��AΪʱ�ӣ�BΪ���ݡ���תʱAB���࣬��תʱABͬ��
//        {
//            if(EC11_A_Now == 0)
//            {
//                if(EC11_B_Now == 1)      //ֻ��Ҫ�ɼ�A�������ػ��½��ص�����һ��״̬����A�½���ʱBΪ1����ת                    
//                    ScanResult = 1;     //��ת

//                else                    //��ת
//                    ScanResult = -1;
//            }
//            EC11_A_Last = EC11_A_Now;   //���±�������һ��״̬�ݴ����
//            EC11_B_Last = EC11_B_Now;   //���±�������һ��״̬�ݴ����
//        }
//    }   
//                            //======================================================//
//    else                    //================����λ��Ӧһ�����EC11================//
//    {                       //======================================================//
        if(spin_int1_flag == 1)        //��A��������ʱ�ɼ�B��ǰ��״̬������B����һ�ε�״̬���жԱȡ�
        {                                   //��A 0->1 ʱ��B 1->0 ��ת����A 1->0 ʱ��B 0->1 ��ת��
                                          //��A 0->1 ʱ��B 0->1 ��ת����A 1->0 ʱ��B 1->0 ��ת
            if(EC11_A_Now == 1)     //EC11_A����һ��״̬��ȣ�Ϊ������
            {
              
				if(EC11_B_Now == 0)   //EC11_B����һ��״̬��ȣ�Ϊ�½���
                    ScanResult = 1;                         //��ת

                if(EC11_B_Now == 1)   //EC11_B����һ��״̬��ȣ�Ϊ������               
                    ScanResult = -1;                        //��ת
			}
			else					 //EC11_A����һ��״̬��ȣ�Ϊ�½���
			{  
                if(EC11_B_Now == 1)  //A������ʱ���ɼ���B������Ϊ0
                    ScanResult = 1;                                 //��ת

                if(EC11_B_Now == 0)  //A������ʱ���ɼ���B������Ϊ1
                    ScanResult = -1;                                //��ת
            }
       
//            EC11_A_Last = EC11_A_Now;   //���±�������һ��״̬�ݴ����

        }
//    }                                                                       

//if(EC11_Key == 0)   //���EC11�İ������£�����û��EC11û��ת����
//{
//	if(ScanResult == 0)         //���°���ʱδת��
//		ScanResult = 2;         //����ֵΪ2
//	else
//	{
//		if(ScanResult == 1)     //���°���ʱ����ת
//			ScanResult = 3;     //����ֵΪ3
//		if(ScanResult == -1)    //���°���ʱ��ת
//			ScanResult = -3;    //����ֵΪ-3
//	}
//}

 
	return ScanResult;      //����ֵ��ȡֵ��   0���޶�����      1����ת��           -1����ת��
	
}                           //              2��ֻ���°�����    3�����Ű�����ת��   -3�����Ű�����ת


//*******************************************************************/
//���ܣ���EC11��ת�������Ķ������з�������������Ӧ�Ķ����������
//�βΣ���
//���أ�char AnalyzeResult = 0;Ŀǰ���á����ڸú��������˶������������ķ���ֵ�������
//��⣺��EC11��ת�������Ķ�������ģʽ�������ǵ�������˫�����ǳ������ֻ���һֱ���¡��βδ� [ char Encoder_EC11_Scan(unsigned char Set_EC11_TYPE) ] �������롣�ڱ��������޸���Ҫ�Ķ����������
//*******************************************************************/
char Encoder_EC11_Analyze(char EC11_Value)
{
    char AnalyzeResult = 0;
    static unsigned int TMP_Value = 0;  //�м����ֵ�������������������Ķ�����ʱ���

    //>>>>>>>>>>>>>>>>��������ת�������<<<<<<<<<<<<<<<<//
	
//		P51 = EC11_Value;
	
    if(EC11_Value == 1)     //��ת
    {
		spin_right = 1;
		 spin_int1_flag = 0; 
        //--------��������ת��������--------//
   
    }

    //>>>>>>>>>>>>>>>>��������ת�������<<<<<<<<<<<<<<<<//
    if(EC11_Value == -1)    //��ת
    {
		spin_left = 1;
		 spin_int1_flag = 0; 
        //--------��������ת��������--------//

    }

	//>>>>>>>>>>>>>>>>�������������´������<<<<<<<<<<<<<<<<//
//    if(EC11_Value == 2)     		
//    {
//		//====��⵽��������====//
//		
//		spin_short = 1;
//		
//        if(EC11_KEY_COUNT<10000)    //�򿪰�������ʱ�䶨ʱ��
//            EC11_KEY_COUNT++;
//        if(EC11_KEY_COUNT == KEY_COUNT_DESHAKING)   //���°���ʱ�䵽������ʱ��ʱ
//        {                                           //��λ�̰�������־
//            FLAG_EC11_KEY_ShotClick = 1;
//        }

//        if((EC11_KEY_DoubleClick_Count > 0)&&(EC11_KEY_DoubleClick_Count <= KEY_COUNT_DUALCLICKTIME))   //�ɿ����������ڶ�ʱ����˫��ʱ���ڰ��°���
//        {                                                                                               //��λ˫��������־
//            FLAG_EC11_KEY_DoubleClick = 1;
//        }

//        if(EC11_KEY_COUNT == KEY_COUNT_LONGTIME)    //���°���ʱ�䵽�ﳤ��ʱ��
//        {                                           //��λ����������־����λ�̰�������־
//            FLAG_EC11_KEY_LongClick = 1;
//            FLAG_EC11_KEY_ShotClick = 0;
//        }

//    }
//    else    //====��⵽�����ɿ�====//     
//    {
//        if(EC11_KEY_COUNT < KEY_COUNT_DESHAKING)    //û������ʱ�����ɿ���������λ���ж�ʱ���Ͱ�����־
//        {
//            EC11_KEY_COUNT = 0;
//            FLAG_EC11_KEY_ShotClick = 0;
//            FLAG_EC11_KEY_LongClick = 0;
//            FLAG_EC11_KEY_DoubleClick = 0;
//            EC11_KEY_DoubleClick_Count = 0;
//        }
//        else
//        {
//            
//            if(FLAG_EC11_KEY_ShotClick == 1)        //�̰�������ʱ��Ч�ڼ�
//            {
//                if((FLAG_EC11_KEY_DoubleClick == 0)&&(EC11_KEY_DoubleClick_Count >= 0)) 
//                    EC11_KEY_DoubleClick_Count++;
//                if((FLAG_EC11_KEY_DoubleClick == 1)&&(EC11_KEY_DoubleClick_Count <= KEY_COUNT_DUALCLICKTIME))   //����ڹ涨˫��ʱ�����ٴΰ��°���
//                {                                                                                               //��Ϊ������˫������
//                    FLAG_EC11_KEY_DoubleClick = 2;
//                }   

//                if((FLAG_EC11_KEY_DoubleClick == 0)&&(EC11_KEY_DoubleClick_Count > KEY_COUNT_DUALCLICKTIME))    //���û���ڹ涨˫��ʱ�����ٴΰ��°���
//                    FLAG_EC11_KEY_ShotClick = 0;                                                                //��Ϊ�����ǵ�������
//            }

//            if(FLAG_EC11_KEY_LongClick == 1)        //��⵽���������ɿ�
//                FLAG_EC11_KEY_LongClick = 0;
//        }

//    }
	
    //>>>>>>>>>>>>>>>�������������²���ת�������<<<<<<<<<<<<<<<//
    if(EC11_Value == 3)
    {
        //--------�������������²���ת��������--------//
          
    }

    //>>>>>>>>>>>>>>>>�������������²���ת�������<<<<<<<<<<<<<<<<//
    if(EC11_Value == -3)
    {
        //--------�������������²���ת��������--------//
  
    }

   


    //>>>>>>>>>>>>>>>>���������������������<<<<<<<<<<<<<<<<//
    if(EC11_KEY_COUNT > KEY_COUNT_DESHAKING)    //�̰�������ʱ����ʱ��
    {

        //�̰�����������������
        if((FLAG_EC11_KEY_ShotClick == 0)&&(EC11_KEY_DoubleClick_Count > KEY_COUNT_DUALCLICKTIME)&&(EC11_KEY_COUNT < KEY_COUNT_LONGTIME))   //�̰�����������������
        {
            //--------�̰�����������������--------//
//            EC11_NUM_SW++;
//            if(EC11_NUM_SW >= 4)
//                EC11_NUM_SW = 1;
            AnalyzeResult = 1;
            //--------�����־λ--------//
            EC11_KEY_COUNT = 0;
            EC11_KEY_DoubleClick_Count = 0;
            FLAG_EC11_KEY_DoubleClick = 0;
        }

        //˫������������������
        if((FLAG_EC11_KEY_DoubleClick == 2)&&(EC11_KEY_DoubleClick_Count > 0)&&(EC11_KEY_DoubleClick_Count <= KEY_COUNT_DUALCLICKTIME)) //˫������������������
        {
            //--------˫������������������--------//
//            if(EC11_NUM_SW == 5)
//                EC11_NUM_SW = 0;
//            if(EC11_NUM_SW == 4)
//                EC11_NUM_SW = 5;

//            if(EC11_NUM_SW <4)
//            {
//                EC11_NUM_SW = 4;
//            }
            AnalyzeResult = 2;
            //--------�����־λ--------//
            EC11_KEY_COUNT = 0;
            EC11_KEY_DoubleClick_Count = 0;
            FLAG_EC11_KEY_ShotClick = 0;
            FLAG_EC11_KEY_DoubleClick = 0;
            
        }

        //���������������´���
        if((FLAG_EC11_KEY_LongClick == 1)&&(EC11_KEY_COUNT >= KEY_COUNT_LONGTIME))  //���������������´���
        {
            TMP_Value ++;
            if(TMP_Value % KEY_LONG_REPEAT_TIME == 0)
            {
                TMP_Value = 0;
                //-------���������������´���--------//
                AnalyzeResult = 4;
            }
        }

        //��������������������
        if((FLAG_EC11_KEY_LongClick == 0)&&(EC11_KEY_COUNT >= KEY_COUNT_LONGTIME))  //��������������������
        {                                                                           
            //--------�����������¶�����������--------//
//            EC11_NUM_SW = 0;
//            G_PWM_NUM1 = 0x20;
//            G_PWM_NUM2 = 0x20;
//            G_PWM_NUM3 = 0x20;
            AnalyzeResult = 3;
            //--------�����־λ--------//
            EC11_KEY_COUNT = 0;
        }


    }
    return AnalyzeResult;
}

