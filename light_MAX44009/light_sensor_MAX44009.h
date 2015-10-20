/*
 * ligth_sensor_MAX44009.h
 *
 *  Created on: 4/6/2015
 *      Author: Diego
 */

#ifndef LIGTH_SENSOR_MAX44009_H_
#define LIGTH_SENSOR_MAX44009_H_
#include "../typedefs.h"

#define INT_STATUS_ADDR         0x00
#define INT_ENABLE_ADDR         0x01
#define CONFIG_ADDR             0x02
#define LUX_HIGH_ADDR           0x03
#define LUX_LOW_ADDR            0x04
#define THRESHOLD_HIGH_ADDR     0x05
#define THRESHOLD_LOW_ADDR      0x06
#define THRESHOLD_TIMER_ADDR    0x07

#define LUX_SLV_ADDR0           0b1001010 // A0 TO GND.
#define LUX_SLV_ADDR1           0b1001011 // A0 TO VCC.

void measureLight(twoBytes *lightBytes);
float calculateLight(twoBytes *lightBytes);
//#define SLV_ADDR_WRT1           0b10010100 // A0 TO GND.
//#define SLV_ADDR_WRT2           0b10010110 // A0 TO VCC.
//#define SLV_ADDR_RD1            0b10010101 // A0 TO GND.
//#define SLV_ADDR_RD2            0b10010111 // A0 TO VCC.


#endif /* LIGTH_SENSOR_MAX44009_H_ */
