/*
 * lab_03_spi.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcal/global_interrupt.h"
#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/dio/dio.h"

void lab_00_dio(void)
{
    uint8 temp=0;
    uint8 temp1=0;
    uint8 temp2=1;
    SysCtr_init();
    PORT_init();

    Dio_WriteChannel(Dio_Channel_F0, STD_high);
    Dio_WriteChannel(Dio_Channel_F1, STD_high);
    Dio_WriteChannel(Dio_Channel_F2, STD_high);

    Dio_WritePort(Dio_Port_A,0xF5);

/*  Dio_FlipChannel(Dio_Channel_A0);
    Dio_FlipChannel(Dio_Channel_A0);
    Dio_FlipChannel(Dio_Channel_A0);
    Dio_FlipChannel(Dio_Channel_A0);
    Dio_FlipChannel(Dio_Channel_A0);*/

/*  Dio_FlipPort(Dio_Port_A);
    Dio_FlipPort(Dio_Port_A);
    Dio_FlipPort(Dio_Port_A);
    Dio_FlipPort(Dio_Port_A);
    Dio_FlipPort(Dio_Port_A);*/

    temp = Dio_ReadPort(Dio_Port_A);
    temp1 = Dio_ReadChannel(Dio_Channel_A0);
    temp2 = Dio_ReadChannel(Dio_Channel_A1);
    Dio_WritePort(Dio_Port_F,temp);
    while(1)
    {

    }
}


