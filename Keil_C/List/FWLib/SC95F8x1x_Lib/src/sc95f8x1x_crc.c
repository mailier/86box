//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: sc95f8x1x_CRC.c
//	����		: 
//	ģ�鹦��	: CRC�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2019/7/10
// 	�汾		: V1.0 
//  ˵��        ��  
//*************************************************************

#include "sc95f8x1x_CRC.h"
#include"intrins.H"

/**************************************************
*�������ƣ�unsigned long CRC_All()
*�������ܣ��󱾹���HEX��CRC32У��ֵ���ü����������OPTION��IAR Range��ͬ���仯
*��ڲ�����void
*���ڲ�����uint32_t ����CRC������
**************************************************/
uint32_t CRC_All()
{
    uint32_t CRC_Result;
    OPERCON |= 0x01;
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    CRCINX = 0x00;
    CRC_Result = CRCREG;
    CRC_Result = CRCREG*256 + CRC_Result;
    CRC_Result = CRCREG*65536 + CRC_Result;
    CRC_Result = CRCREG*16777216 + CRC_Result;
	return CRC_Result;
}

/**************************************************
*�������ƣ�uint32_t CRC_Frame(uint8_t* buff,uint8_t Length)
*�������ܣ�������֡��CRCУ��ֵ
*��ڲ�����uint8_t* buff,	  ������Ҫ����CRC���������
		   uint8_t Length	  ������Ҫ��������鳤��
*���ڲ�����uint32_t CRC������
**************************************************/
uint32_t CRC_Frame(uint8_t* buff,uint8_t Length)
{
    uint8_t i;
	uint32_t CRC_Result = 0;
	EA=0;
    OPERCON |= 0x02;
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    for(i=0; i<Length; i++)
    {
        CRC_Result = *(buff + i);
        CRCREG = CRC_Result;
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();            
    }
    CRCINX = 0x00;
    CRC_Result = CRCREG;
    CRC_Result = CRCREG*256 + CRC_Result;
    CRC_Result = CRCREG*65536 + CRC_Result;
    CRC_Result = CRCREG*16777216 + CRC_Result;
	EA=1;
	return CRC_Result;
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/