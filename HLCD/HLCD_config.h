#ifndef HLCD_CONFIG_H
#define HLCD_CONFIG_H

/*Configuration for Control Pins */

/* Rs pin */
#define HLCD_RS_PORT MDIO_PORTD
#define HLCD_RS_PIN MDIO_PIN_2

/* R/W pin */
#define HLCD_RW_PORT MDIO_PORTD
#define HLCD_RW_PIN MDIO_PIN_1

/* EN pin */
#define HLCD_EN_PORT MDIO_PORTD
#define HLCD_EN_PIN  MDIO_PIN_0

/* Configuration forData Pins Port */
#define HLCD_DATA_PORT MDIO_PORTC

#endif
