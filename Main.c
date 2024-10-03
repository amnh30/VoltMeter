/*
 * Main.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Ahmed Nageeb
 */
/* LIB Layer*/
#include "STD_Types.h"
/* MCAL Layer*/
#include "MDIO/MDIO_Interface.h"
#include "HLCD/HLCD_interface.h"
#include "MADC_Interface.h"
#include <avr/delay.h>

int main(int argc, char const *argv[])
{
    u16 Local_u16Value;
    float Local_u16AnalogValue;

    /* Intial MDIO*/
    MDIO_IntialPins();
    /* Intial LCD*/
    HLCD_VoidLcdIint();
    /* Intial MADC*/
    MADC_voidInit();
    HLCD_u8WriteStr("Hello");

    while (1)
    {
        MADC_u8GetADCValue(0,&Local_u16Value);
        Local_u16AnalogValue = (Local_u16Value*5UL)/(float)1023;


        
        HLCD_VoidLcdClear();
        HLCD_u8WriteStr("Volt is: ");
        HLCD_VoidLcdWriteFloat(Local_u16AnalogValue);
        // HLCD_VoidLcdWriteInt(Local_u16Value/70);
        _delay_ms(100);









        // if (Local_u16AnalogValue <= 1500)
        // {
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_2,MDIO_HIGH);
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_1,MDIO_LOW);
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_0,MDIO_LOW);
        // }
        // else if (Local_u16AnalogValue <= 3500 )
        // {
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_1,MDIO_HIGH);
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_2,MDIO_LOW);
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_0,MDIO_LOW);
        // }
        // else 
        // {
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_0,MDIO_HIGH);
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_2,MDIO_LOW);
        //     MDIO_u8SetPinValue(MDIO_PORTB,MDIO_PIN_1,MDIO_LOW);
        // }
        
        
    }

    return 0;
}
