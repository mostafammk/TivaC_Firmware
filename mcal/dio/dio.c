/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
/*TODONE: include the header file that contains register definitions */
#include "../mcu_hw.h"
#include "dio_types.h"
#include "dio.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    STD_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }


    /*TODONE: Return the Input Channel Value */
    if((PORT_Addr->writeHere)&(1<<ChannelPos))
    {
        ret = STD_high;
    }
    else
    {
        ret = STD_low;
    }

    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;


    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        /*TODONE: Assign PORTD address to PORT_Addr variable */
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }

    /*TODONE: Write the input value in the corresponding ChannelId */

    (PORT_Addr->writeHere) |= (1<<ChannelPos);
    //*((uint8 *)(&(PORT_Addr->GPIODATA)) + 0x3FC) |= (1<<ChannelPos);
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;

    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }
    /*TODONE: Return the Port Value*/

    ret = (PORT_Addr->writeHere);

    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }
    /*TODONE: Write the input value in the corresponding PortId */
    (PORT_Addr->writeHere) = value;
}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    /* TODONE: toggle the corresponding ChannelId */

    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }

    (PORT_Addr->writeHere) ^= (1<<ChannelPos);

}
void Dio_FlipPort(Dio_PortType PortId)
{
    /*TODONE: toggle the port value */
    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }

    (PORT_Addr->writeHere) ^= 0xFF;
}



