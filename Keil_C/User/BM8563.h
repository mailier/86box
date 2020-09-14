#ifndef __BM8563_H_
#define __BM8563_H_

#include "sc95f8x1x.H"
/* -----------------------------------------全局变量声明-----------------------------------*/
  
 extern unsigned char BM8563_hour;
 extern unsigned char BM8563_min; 
 

typedef struct _TIME_{
	
	u8 sec;
	u8 min;
	u8 hour;

	u8 percent;
//	u8 moom;
//	u8 year;

} TIME;						//时钟模块

/* -----------------------------------------应用程序---------------------------------------*/

 void Delayus(u8 i); 

 void IIC_Init(void);

 void BM8563_IIC_Start(void);
 
 void BM8563_IIC_Stop(void);
 
 void BM8563_IIC_Wait_ACK(void);
 
 void BM8563_IIC_WriteByte(uint8_t byte);
 
 void BM8563_send_add_byte(uint8_t add,uint8_t bat); //向某个地址发送某数据
 
 uint8_t BM8563_IIC_ReadByte(void);
 
 uint8_t BM8563_IIC_ReceiveData(uint8_t Ack);
 
 uint8_t BM8563_read_add_byte(uint8_t add); //从某个地址读出数据
 
// bit GetBM8563(uchar sla,uchar suba,uchar *s,uchar no);
 
 bit SetBM8563(uint8_t sla,uint8_t suba,uint8_t *s,uint8_t no);
 
 void Bcd2asc(void); 
 
 uint8_t Bcd_dec(uint8_t bat);
 
void BM8563_get_time(void);
 
 void BM8563_init(void);
 
 void  Time_init(void);	
 
 #endif