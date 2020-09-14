//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: BM5863.c
//	作者		: 
//	模块功能	: 时钟读取
//	局部函数列表:
//  最后更正日期: 2019/7/10
// 	版本		: V1.0 
//  说明        ：  I2C 总线驱动程序(用两个普通 IO 模拟 I2C 总线)用来驱动 BM8563，100k 的速率。
//默认 12Mhz 的晶振。 
//*************************************************************

 #include "BM8563.h"
 #include "operation.h"
 
/* ---------------------------------------IO引脚分配定义-------------------------------------*/

 sbit BM8563_SDA = P5^5; /*实时时钟时钟线引脚定义,设置为高阻态上拉 */ 
 sbit BM8563_SCL = P5^4; /*实时时钟数据线引脚定义，设置为推挽输出 */ 
 
/*--------------------------------------------宏定义--------------------------------------------*/

 #define BM8563_SDA(N)  BM8563_SDA = N
 #define BM8563_SCL(N)  BM8563_SCL = N
 
 #define SomeNOP(); _nop_();_nop_();_nop_();_nop_();_nop_(); 

 /*选择SDA的数据方向*/
 #define BM8563_SDA_Input()     { P5CON &= 0xDF; P5PH |= 0x20;}
 #define BM8563_SDA_Output()    { P5CON |= 0x30; P5PH |= 0x00;}
 

/* -----------------------------------------全局变量定义-----------------------------------*/
 
// static uchar twdata[9]={0x00,0x00,0x58,0x59,0x23,0x31,0x06,0x12,0x04};
// /*前 2 个数据用来设置状态寄存器，后 7 个用来设置时间寄存器 */ 

// static uchar trdata[7]; /*定义数组用来存储读取的时间数据 */ 
// static uchar asc[14]; /*定义数组用来存储转换的 asc 码时间数据，供显示用 */ 
 static bit ack; 
 unsigned char BM8563_hour = 0;
 unsigned char BM8563_min = 0;
/* -----------------------------------------应用程序---------------------------------------*/

/*********************************************
函数名：Delayus
功  能：微秒延时
形  参：
返回值：none.
备  注：应用于IIC
作  者：
时  间：2020/06/24
**********************************************/

void Delayus(u8 i)
{
    while (i--);
}

/*********************************************
函数名：IIC_Init
功  能：IIC引脚初始化
形  参：
返回值：
备  注：
时  间：2019/06/11
**********************************************/

void IIC_Init(void)
{
    BM8563_SDA_Output();
    BM8563_SDA(1);
    BM8563_SCL(1);
}
 
/******************************************************************** 
函 数 名：BM8563_IIC_Start(void) 
功 能：启动 I2C 总线的传输 
说 明： 
调 用： 
入口参数：无 
返 回 值：无 
***********************************************************************/ 

void BM8563_IIC_Start(void)
{
    BM8563_SDA_Output();  // 设置为输出模式
    BM8563_SCL(1);
    BM8563_SDA(1);
    Delayus(1);
    BM8563_SDA(0);
    BM8563_SCL(0);
    Delayus(2);
}

/******************************************************************** 
函 数 名：BM8563_IIC_Stop(void) 
功 能：停止 I2C 总线的传输 
说 明： 
调 用： 
入口参数：无 
返 回 值：无 
***********************************************************************/ 

void BM8563_IIC_Stop(void)
{
    BM8563_SDA_Output();  // 设置为输出模式
    BM8563_SCL(0);
    BM8563_SDA(0);
    Delayus(2);
    BM8563_SCL(1);
    BM8563_SDA(1);
    Delayus(2);
}

/******************************************************************** 
函 数 名：BM8563_IIC_Wait_ACK(void) 
功 能：IIC从设备应答
说 明：
调 用：
入口参数： 
返 回 值：无 
***********************************************************************/ 

void BM8563_IIC_Wait_ACK(void)
{
    uint8_t i = 0;
    BM8563_SDA_Input();            //   SDA 设置为输入
    BM8563_SCL(1);
    Delayus(1);
    while (BM8563_SDA == 1 && i < 250)
        i++;
    BM8563_SCL(0);
    BM8563_SDA_Output();           //   设置成输出
    Delayus(2);
}

/******************************************************************** 
函 数 名：SendByte(void) 
功 能：向 BM8563 写一个字节的数据 
说 明： 被 GetBM8563(void) 调用 
调 用：被 GetBM8563(void)、setBM8563(void)调用 
入口参数：byte（要写入的单字节数据） 
返 回 值：无 
***********************************************************************/ 

void BM8563_IIC_WriteByte(uint8_t byte)
{
    uint8_t len = 0;
    BM8563_SCL(0);
    Delayus(2);
    for (len = 0; len < 8; len++)
    {
        if (byte & 0x80)
        {
            BM8563_SDA(1);
        }
        else
        {
            BM8563_SDA(0);
        }
        Delayus(1);
        BM8563_SCL(1);
        byte <<= 1;
        Delayus(1);
        BM8563_SCL(0);
        Delayus(2);
    }
    BM8563_SDA(1);
    BM8563_SCL(0);
    Delayus(2);
}

/******************************************************************** 
函 数 名：BM8563_send_add_byte(void) 
功 能：向 BM8563 的地址发送数据 
说 明：  
调 用：
入口参数：add bat 
返 回 值：无 
***********************************************************************/ 

void BM8563_send_add_byte(uint8_t add,uint8_t bat) //向某个地址发送某数据
{
	
	BM8563_IIC_Start();
	BM8563_IIC_WriteByte(0xa2);
	BM8563_IIC_Wait_ACK();
	BM8563_IIC_WriteByte(add);
	BM8563_IIC_Wait_ACK();
	BM8563_IIC_WriteByte(bat);
	BM8563_IIC_Wait_ACK();
	BM8563_IIC_Stop();
}


/******************************************************************** 
函 数 名：BM8563_IIC_ReadByte(void) 
功 能：从 BM8563 读取一个字节的数据 
说 明：该程序要配合 SendByte()程序一起完成对 BM8563 的读操作，被 GetBM8563(void) 
 调用 
调 用：被 GetBM8563(void)调用 
入口参数：无 
返 回 值：Byte 
***********************************************************************/ 

uint8_t BM8563_IIC_ReadByte(void)
{
    uint8_t len = 0, Byte = 0;
    BM8563_SDA(1);
    BM8563_SDA_Input();            // SDA 设置为输入
    for (len = 0; len < 8; len++)
    {
        BM8563_SCL(0);
        Delayus(1);
        BM8563_SCL(1);
        Delayus(1);
        Byte <<= 1;
        Byte |= BM8563_SDA;
        Delayus(1);
        BM8563_SCL(0);
        Delayus(1);
    }
    return Byte;
}

/*********************************************
函数名：BM8563_IIC_ReceiveData
功  能：向从设备接收一个字节，并带应答
形  参：
返回值：
备  注：
时  间：2020/07/15
**********************************************/
uint8_t BM8563_IIC_ReceiveData(uint8_t Ack)
{
    uint8_t i = 0, ReadValue = 0;
    BM8563_SDA_Output();   //   设置成输出模式
    BM8563_SDA(1);
    BM8563_SDA_Input();    //   设置为输入模式
    BM8563_SCL(0);

    for (i = 0; i < 8; i++)
    {
        BM8563_SCL(1);
        Delayus(1);
        ReadValue <<= 1;
        if (BM8563_SDA != 0)
        {
            ReadValue |= 0x01;
        }
        Delayus(1);
        BM8563_SCL(0);
        Delayus(2);
    }
    if (Ack)
    {
        BM8563_SCL(0);
        BM8563_SDA_Output();   //   设置成输出模式
        BM8563_SDA(0);
        Delayus(2);
        BM8563_SCL(1);
        Delayus(1);
        BM8563_SCL(0);
    }
    else
    {
        BM8563_SCL(0);
        BM8563_SDA_Output();   //   设置成输出模式
        BM8563_SDA(1);
        Delayus(2);
        BM8563_SCL(1);
        Delayus(1);
        BM8563_SCL(0);
    }
    return ReadValue;
}

/******************************************************************** 
函 数 名：BM8563_read_add_byte
功 能：从 BM8563 的地址读取数据 
说 明：  
调 用：
入口参数：add 
返 回 值：temp
***********************************************************************/ 
uint8_t BM8563_read_add_byte(uint8_t add) //从某个地址读出数据
{
   uint8_t temp;	
   BM8563_IIC_Start();
   BM8563_IIC_WriteByte(0xa2);
   BM8563_IIC_Wait_ACK();
   BM8563_IIC_WriteByte(add);
   BM8563_IIC_Wait_ACK();
   BM8563_IIC_Start();
   BM8563_IIC_WriteByte(0xa3);
   BM8563_IIC_Wait_ACK();
   temp=BM8563_IIC_ReadByte();
   BM8563_IIC_Stop();
   return temp;
}

/******************************************************************** 
函 数 名： GetBM8563(void) 
功 能：从 BM8563 的内部寄存器（时间、状态、报警等寄存器）读取数据 
说 明：该程序函数用来读取 BM8563 的内部寄存器，譬如时间，报警，状态等寄存器 
 采用页写的方式，设置数据的个数为 no，no 参数设置为 1 就是单字节方式 
调 用：Start_I2C()，SendByte()，RcvByte()，Ack_I2C()，Stop_I2C() 
入口参数：sla（BM8563 从地址）， suba（BM8563 内部寄存器地址） 
 *s（设置读取数据存储的指针）， no（传输数据的个数） 
返 回 值：有，返回布尔量（bit）用来鉴定传输成功否 
***********************************************************************/ 
// bit GetBM8563(uint8_t sla,uint8_t suba,uint8_t *s,uchar no) 
// { 
// uchar i; 
// BM8563_IIC_Start(); 
// BM8563_IIC_WriteByte(sla); 
// if(ack==0)return(0); 
// BM8563_IIC_WriteByte(suba); 
// if(ack==0)return(0); 
// BM8563_IIC_Start(); 
// BM8563_IIC_WriteByte(sla+1); 
// if(ack==0)return(0); 
// 
// for (i=0;i<no-1;i++) 
// { 
// *s=BM8563_IIC_ReceiveData(); 
//// Ack_I2C(0); 
// s++; 
// } 
// *s=BM8563_IIC_ReceiveData(); 
//// Ack_I2C(1); 
// BM8563_IIC_Stop();//除最后一个字节外，其他都要从 MASTER 发应答。 
// return(1); 
// } 
 

/******************************************************************** 
函 数 名：SetBM8563(void) 
功 能：设置 BM8563 的内部寄存器（时间，报警等寄存器） 
说 明：该程序函数用来设置 BM8563 的内部寄存器，譬如时间，报警，状态等寄存器 
 采用页写的方式，设置数据的个数为 no，no 参数设置为 1 就是单字节方式 
调 用：Start_I2C()，SendByte()，Stop_I2C() 
入口参数：sla（BM8563 从地址）， suba（BM8563 内部寄存器地址） 
 *s（设置初始化数据的指针）， no（传输数据的个数） 
返 回 值：有，返回布尔量（bit）用来鉴定传输成功否 
***********************************************************************/ 
 bit SetBM8563(uint8_t sla,uint8_t suba,uint8_t *s,uint8_t no) 
 { 
 uint8_t i; 
 BM8563_IIC_Start(); 
 BM8563_IIC_WriteByte(sla); 
 if(ack==0)return(0); 
 BM8563_IIC_WriteByte(suba); 
 if(ack==0)return(0); 
 for(i=0;i<no;i++) 
{ 
 BM8563_IIC_WriteByte(*s); 
 if(ack==0)return(0); 
 s++; 
} 
BM8563_IIC_Stop(); 
return(1); 
} 

/******************************************************************** 
函 数 名：void Bcd2asc(void) 
功 能：bcd 码转换成 asc 码，供液晶显示用 
说 明： 
调 用： 
入口参数： 
返 回 值：无 
***********************************************************************/ 
//void Bcd2asc(void) 
//{ 
// uchar i,j; 
// 
// for (j=0,i=0; i<7; i++) 
// { 
// time_timeout.min =(time_timeset.min&0xf0)>>4|0x30 ;/*格式为: 秒 分 时 日 月 星期 年 */ 

// time_timeout.min =time_timeset.min&0x0f|0x30; 
// } 
//} 

/******************************************************************** 
函 数 名：void Bcd_dec(void) 
功 能：BCD转10进制表示
说 明： 
调 用： 
入口参数： 
返 回 值：无 
***********************************************************************/ 
uint8_t Bcd_dec(uint8_t bat)
{
uint8_t temp1,temp2,tol;
temp1=bat&0x0f;
temp2=(bat&0xf0)>>4;
tol=temp2*10+temp1;
return tol; 
}

/******************************************************************** 
函 数 名：datajust(void) 
功 能：将读出的时间数据的无关位屏蔽掉 
说 明：BM8563 时钟寄存器中有些是无关位，可以将无效位屏蔽掉 
调 用： 
入口参数： 
返 回 值：无 
***********************************************************************/ 
//void datajust(void) 
//{ 
// 
// trdata[0] = trdata[0]&0x7f; 
// trdata[1] = trdata[1]&0x7f; 
// trdata[2] = trdata[2]&0x3f; 
// trdata[3] = trdata[3]&0x3f; 
// trdata[4] = trdata[4]&0x07; 
// trdata[5] = trdata[5]&0x1f; 
// trdata[6] = trdata[6]&0xff; 

//} 

/******************************************************************** 
函 数 名：delayx1ms(void) 
功 能：延时 
说 明： 
调 用： 
入口参数： 
返 回 值：无 
***********************************************************************/ 
void BM8563_get_time(void) 
{ 
	TIME time_ASC;
	TIME time_BCD;


         time_ASC.sec=0x7f&BM8563_read_add_byte(0x02);   	//读取秒
         time_ASC.min=0x7f&BM8563_read_add_byte(0x03);   	//读取分钟
         time_ASC.hour=0x3f&BM8563_read_add_byte(0x04);  	//读取小时
//         time_ASC.day=0x3f&BM8563_read_add_byte(0x05);   	//读取天数
//         time_ASC.moom=0x1f&BM8563_read_add_byte(0x07);  	//读取月
//         time_ASC.year=0xff&BM8563_read_add_byte(0x08);     //读取年
				
         time_BCD.sec=Bcd_dec(time_ASC.sec);                //将读取的BCD码秒转换成十进制秒以便运算
         time_BCD.min=Bcd_dec(time_ASC.min);
         time_BCD.hour=Bcd_dec(time_ASC.hour);
//         time_BCD.day=Bcd_dec(time_ASC.day);
//         time_BCD.moom=Bcd_dec(time_ASC.moom);
//         time_BCD.year=Bcd_dec(time_ASC.year);
//	BM8563_hour = time_BCD.hour;
//	BM8563_min = time_BCD.min;
		now.hour = time_BCD.hour;
		now.min = time_BCD.min;
} 

/******************************************************************** 
函 数 名：BM8563_init(void) 
功 能：初始化 BM8563，然后循环读取 BM8563 的时钟并存储。 
说 明：该程序只是简单的将固定的时间设置到 BM8563，然后循环都 BM8563 的时间 
 并存储，对 BM8563 其它的功能没有操作，用户可以根据需要添加其它的功能 
 程序。 
调 用： 
返 回 值：无 
***********************************************************************/ 
 void BM8563_init(void) 
{ 
	IIC_Init();
	BM8563_send_add_byte(0x00,0x00);  //启动时钟
	Time_init();
}
/******************************************************************** 
函 数 名：Time_init(void) 
功 能：时钟设置初始化
说 明：  
调 用： 
返 回 值：无 
***********************************************************************/ 
void  Time_init(void)		
{
  BM8563_send_add_byte(0x02,0x00);         //0秒
  BM8563_send_add_byte(0x03,0x00);         //0分钟    
  BM8563_send_add_byte(0x04,0x00);         //0小时             
  BM8563_send_add_byte(0x05,0x01);         //26号
  BM8563_send_add_byte(0x07,0x01);         //5月  20世纪的
  BM8563_send_add_byte(0x08,0x20);         //2014年
}