#ifndef MADC_PRIVATE_H
#define MADC_PRIVATE_H

/*Define ADC Registers*/
#define PRIVATE_ADCMUX 		 *((volatile u8 *)0x27)
#define PRIVATE_ADCSRA   	 *((volatile u8 *)0x26)

#define PRIVATE_SFIOR 		 *((volatile u8 *)0x50)

#define PRIVATE_ADCH   		 *((volatile u8 *)0x25)
#define PRIVATE_ADCL   		 *((volatile u8 *)0x24)
#define PRIVATE_U16_ADC		*((volatile u16 *)0x24)
#endif
