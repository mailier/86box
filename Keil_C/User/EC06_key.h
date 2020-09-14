//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: EC06_key.h
//	作者		: 
//	模块功能	: 旋转编码器头文件
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  
//*************************************************************
#ifndef _EC06_KEY_H_
#define	_EC06_KEY_H_

#include "sc95f8x1x.h"

//----------------IO口定义----------------//
#define EC11_A_Now                  P21                             //EC11的A引脚，视为时钟线
#define EC11_B_Now                  P20                             //EC11的B引脚，视为信号线
#define EC11_Key                    P41                             //EC11的按键
#define keyleft						P42
#define keyright 					P40

extern bit spin_int1_flag;

extern bit Key_left_short;
extern bit Key_right_short;

extern bit Key_left_long;
extern bit Key_right_long;

extern bit spin_left,
			spin_right,
			
			spin_short,
			spin_long,

			spin_long_left,
			spin_long_right;


//----------------编码器动作代码相关定义----------------//
extern  int G_PWM_NUM1;
extern  int G_PWM_NUM2;
extern  int G_PWM_NUM3;
static unsigned char EC11_NUM_SW = 0;

//----------------编码器参数微调宏定义----------------//
#define EC11_SCAN_PERIOD_MS            1                            //EC11编码器扫描周期
#define KEY_COUNT_DESHAKING         ( 20/EC11_SCAN_PERIOD_MS)       //按键消抖时间
#define KEY_COUNT_LONGTIME          (600/EC11_SCAN_PERIOD_MS)       //长按按键判断时间
#define KEY_COUNT_DUALCLICKTIME     (150/EC11_SCAN_PERIOD_MS)       //双击按键判断时间
#define KEY_LONG_REPEAT_TIME        (200/EC11_SCAN_PERIOD_MS)       //长按按键的回报率的倒数，即一直长按按键时响应的时间间隔

//----------------局部文件内变量列表----------------//
static  char    EC11_A_Last = 0;                        //EC11的A引脚上一次的状态
static  char    EC11_B_Last = 0;                        //EC11的B引脚上一次的状态
static  char    EC11_Type = 1;                          //定义变量暂存EC11的类型---->>>>----  0：一定位对应一脉冲；  1：两定位对应一脉冲
                                                        //所谓一定位对应一脉冲，是指EC11旋转编码器每转动一格，A和B都会输出一个完整的方波。
                                                        //而  两定位对应一脉冲，是指EC11旋转编码器每转动两格，A和B才会输出一个完整的方波，只转动一格只输出A和B的上升沿或下降沿
                                                 
static   int    EC11_KEY_COUNT = 0;                     //EC11按键动作计数器
static   int    EC11_KEY_DoubleClick_Count = 0;         //EC11按键双击动作计数器
static  char    FLAG_EC11_KEY_ShotClick = 0;            //EC11按键短按动作标志
static  char    FLAG_EC11_KEY_LongClick = 0;            //EC11按键长按动作标志
static  char    FLAG_EC11_KEY_DoubleClick = 0;          //EC11按键双击动作标志


extern uint32_t Temper;  

/*******************************************************************
void Encoder_EC11_Init(unsigned char Set_EC11_TYPE);        //初始化EC11旋转编码器IO口和类型以及变量初始化
char Encoder_EC11_Scan();                                   //扫描旋转编码器的动作
void Encoder_EC11_Analyze(char EC11_Value);                 //分析EC11旋转编码器的动作以及动作处理代码
******************************************************************/
//-------->>>>>>>>--------注意事项：EC11旋转编码器的扫描时间间隔控制在1~4ms之间，否则5ms及以上的扫描时间在快速旋转时可能会误判旋转方向--------<<<<<<<<--------//
//-------->>>>>>>>--------注意事项：EC11旋转编码器的扫描时间间隔控制在1~4ms之间，否则5ms及以上的扫描时间在快速旋转时可能会误判旋转方向--------<<<<<<<<--------//
//-------->>>>>>>>--------注意事项：EC11旋转编码器的扫描时间间隔控制在1~4ms之间，否则5ms及以上的扫描时间在快速旋转时可能会误判旋转方向--------<<<<<<<<--------//

//----------------函数声明列表----------------//
//

void spin_scan(void);	

void  key_scan(void);
//*******************************************************************/
//功能：初始化EC11旋转编码器相关参数
//形参：EC11旋转编码器的类型-->>  unsigned char Set_EC11_TYPE  <<--  ：0----一定位对应一脉冲；1（或非0）----两定位对应一脉冲。
//返回：无
//详解：对EC11旋转编码器的连接IO口做IO口模式设置。以及将相关的变量进行初始化
//*******************************************************************/
void Encoder_EC11_Init(unsigned char Set_EC11_TYPE);

//*******************************************************************/
//功能：扫描EC11旋转编码器的动作并将参数返回给动作分析函数使用
//形参：EC11旋转编码器的类型-->>  unsigned char Set_EC11_TYPE  <<--  ：0----一定位对应一脉冲；1（或非0）----两定位对应一脉冲
//返回：EC11旋转编码器的扫描结果-->>  char ScanResult  -->>  0：无动作；1：正转； -1：反转；2：只按下按键；3：按着按键正转；-3：按着按键反转
//详解：只扫描EC11旋转编码器有没有动作，不关心是第几次按下按键或长按或双击。返回值直接作为形参传给 [ void Encoder_EC11_Analyze(char EC11_Value); ] 函数使用
//*******************************************************************/
char Encoder_EC11_Scan();
    
//*******************************************************************/
//功能：对EC11旋转编码器的动作进行分析，并作出相应的动作处理代码
//形参：无
//返回：char AnalyzeResult = 0;目前无用。若在该函数里做了动作处理，则函数的返回值无需理会
//详解：对EC11旋转编码器的动作进行模式分析，是单击还是双击还是长按松手还是一直按下。形参从 [ char Encoder_EC11_Scan(unsigned char Set_EC11_TYPE) ] 函数传入。在本函数内修改需要的动作处理代码
//*******************************************************************/
char Encoder_EC11_Analyze(char EC11_Value);

#endif
