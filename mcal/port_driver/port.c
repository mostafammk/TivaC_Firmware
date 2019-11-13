
/*
 * port.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Mustafa Sayed
 */
#define MAX_NUM_OF_CH_IN_PORT       8

#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include "port_types.h"
#include "port.h"

extern Port_CfgType PortCfgArr[];

void PORT_init(void)
{
    uint8 i;
    Port_IdType PortId;
    Port_ChIdType ChId;
    volatile PORT_RegType* PORT_Addr;
    for (i = 0; i < PORT_NUM_OF_ACTIVATED_CH; ++i)
    {
        PortId = i/ MAX_NUM_OF_CH_IN_PORT;
        ChId = i % MAX_NUM_OF_CH_IN_PORT;

        switch (PortId)
        {
        case Port_Id_A:
            PORT_Addr = &PORTA_REG;
            break;
        case Port_Id_B:
            PORT_Addr = &PORTB_REG;
            break;
        case Port_Id_C:
            PORT_Addr = &PORTC_REG;
            break;
        case Port_Id_D:
            /*TODONE: Assign PORTD address to PORT_Addr variable */
            PORT_Addr = &PORTD_REG;
            break;
        case Port_Id_E:
            PORT_Addr = &PORTE_REG;
            break;
        case Port_Id_F:
            PORT_Addr = &PORTF_REG;
            break;
        }

        /*TODONE: set channel direction */
        if(PortCfgArr[i].Dir == port_Dir_Input)
        {
            CLR_BIT(PORT_Addr->GPIODIR, ChId);
        }
        else if (PortCfgArr[i].Dir == port_Dir_Output)
        {
            SET_BIT(PORT_Addr->GPIODIR, ChId);
        }

        /*TODONE: set channel mode */
        if(PortCfgArr[i].Mode == PORT_MODE_PIN_X_DIO)
        {
            CLR_BIT(PORT_Addr->GPIOAFSEL, ChId);

        }
        else
        {
            SET_BIT(PORT_Addr->GPIOAFSEL, ChId);
        }

        /*TODONE: set Interrupt configuration */
        if(PortCfgArr[i].Interrupt == Port_IntDisable)
        {
            CLR_BIT(PORT_Addr->GPIOIM, ChId);
        }
        else
        {
            SET_BIT(PORT_Addr->GPIOIM, ChId);
        }

        /*TODONE: set Internal Attachment configuration */
        switch (PortCfgArr[i].AttachedRes)
        {
        case Port_InternalAttach_NA:
            CLR_BIT(PORT_Addr->GPIOPUR,ChId);
            CLR_BIT(PORT_Addr->GPIOPDR,ChId);
            CLR_BIT(PORT_Addr->GPIOODR,ChId);
            break;

        case Port_InternalAttach_PullUpRes:
            SET_BIT(PORT_Addr->GPIOPUR,ChId);
            CLR_BIT(PORT_Addr->GPIOPDR,ChId);
            CLR_BIT(PORT_Addr->GPIOODR,ChId);
            break;

        case Port_InternalAttach_PullDownRes:
            SET_BIT(PORT_Addr->GPIOPDR,ChId);
            CLR_BIT(PORT_Addr->GPIOPUR,ChId);
            CLR_BIT(PORT_Addr->GPIOODR,ChId);
            break;

        case  Port_InternalAttach_OpenDrain:
            SET_BIT(PORT_Addr->GPIOODR,ChId);
            CLR_BIT(PORT_Addr->GPIOPUR,ChId);
            CLR_BIT(PORT_Addr->GPIOPDR,ChId);
            break;
        }


        /*TODONE: set current strength configuration */
        if(PortCfgArr[i].CurrentDrive == Port_CurrDrive_2mA)
        {
            SET_BIT(PORT_Addr->GPIODR2R,ChId);
        }
        else if(PortCfgArr[i].CurrentDrive == Port_CurrDrive_4mA)
        {
            SET_BIT(PORT_Addr->GPIODR4R,ChId);
        }
        else if(PortCfgArr[i].CurrentDrive == Port_CurrDrive_8mA)
        {
            SET_BIT(PORT_Addr->GPIODR8R,ChId);
        }


        /*Check if analog functionality is required*/
        if(PortCfgArr[i].Mode != Port_Mode_AIN )
        {
            /*TODONE: enable digital and disable ADC  */
            SET_BIT(PORT_Addr->GPIODEN,ChId);

        }
        else
        {
            /*TODONE: disable digital and enable ADC */
            SET_BIT(PORT_Addr->GPIOAMSEL,ChId);
        }
    }
}
