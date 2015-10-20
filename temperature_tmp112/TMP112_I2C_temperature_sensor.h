/*
 * TMP112_I2C_temperature_sensor.h
 *
 *  Created on: 7/10/2015
 *      Author: Diego
 */

#ifndef TMP112_I2C_TEMPERATURE_SENSOR_H_
#define TMP112_I2C_TEMPERATURE_SENSOR_H_

#include <driverlib/MSP430FR57xx/driverlib.h>
#include "../typedefs.h"

#define ALERT_PORT 		GPIO_PORT_P2
#define ALERT_PIN		GPIO_PIN3


#define TMP112_SLV_ADDR0  	 0b1001000 // A0 TO GND.
#define TMP112_SLV_ADDR1     0b1001001 // A1 TO VCC.

#define TMP112_TEMPERATURE_ADDR	   0x00
#define TMP112_CONFIG_ADDR         0x01

// Configuration parameters
//Byte 1
#define BYTE1_INIT_CFG		0b01100001
#define BYTE2_INIT_CFG		0b10100000

#define SHOOT_CONVERSION1	0b11100001
#define SHOOT_CONVERSION2	0b10100000

//Byte 2

bool temperatureStatus (void);
void measureTMP112(twoBytes *temperatureBytes);
void configTMP112(void);
float calculateTMP112(twoBytes *temperatureBytes);

#endif /* TMP112_I2C_TEMPERATURE_SENSOR_H_ */
