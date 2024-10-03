/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer Include */
#include "MADC_Private.h"
#include "MADC_Config.h"
#include "MADC_Interface.h"

/* Set Initial ADC Function */
void MADC_voidInit(void)
{

    
    //     /* 1- Set Vref == 5v (AVCC) */
    // SET_BIT(PRIVATE_ADCMUX, 6);
    // CLEAR_BIT(PRIVATE_ADCMUX, 7);

    // /* 2- Adjustment value ==> Right */
    // CLEAR_BIT(PRIVATE_ADCMUX, 5);

    // /* 3- Select Single Conversion Mode */
    // CLEAR_BIT(PRIVATE_ADCSRA, 5);

    // /* 4- Set PreScaler Value ==> 64 ==> 125KHZ */
    // SET_BIT(PRIVATE_ADCSRA, 2);
    // SET_BIT(PRIVATE_ADCSRA, 1);
    // CLEAR_BIT(PRIVATE_ADCSRA, 0);

    // /* 5- Enable ADC Peripheral */
    // SET_BIT(PRIVATE_ADCSRA, 7);

    PRIVATE_ADCMUX = (MADC_ADJUST_VALUE & MADC_V_REFERENC_MODE);
    PRIVATE_ADCSRA = (MADC_TRIGGER_MODE & MADC_PRESCALER & MADC_ADC_ENABLE);
}

u8 MADC_u8ADCEnable(u8 Copy_u8ChannelNum)
{
    /* 1- Enable ADC Peripheral */
    SET_BIT(PRIVATE_ADCSRA, 7);

    return STD_TYPE_OK; // Missing return type for function
}

u8 MADC_u8GetADCValue(u8 Copy_u8ChannelNum, u16 *Copy_Pu16ADCValue)
{
    u8 Local_u8ErrorState = STD_TYPE_NOK;

    /* Validate channel number and pointer */
    if ((Copy_u8ChannelNum < 32) && (Copy_Pu16ADCValue != POINTER_NULL))
    {
        Local_u8ErrorState = STD_TYPE_OK;

        /* Clear Channel Number Bits */
        PRIVATE_ADCMUX &= 0b11100000;

        /* Set Channel Number */
        PRIVATE_ADCMUX |= Copy_u8ChannelNum;

        /* Start Conversion */
        SET_BIT(PRIVATE_ADCSRA, 6);

        /* Wait for ADC Flag */
        while (!(GET_BIT(PRIVATE_ADCSRA, 4)))
            ;

        /* Read ADC Value */
        *Copy_Pu16ADCValue = PRIVATE_U16_ADC;

        /* Clear Flag */
        SET_BIT(PRIVATE_ADCSRA, 4);
    }

    return Local_u8ErrorState;
}
