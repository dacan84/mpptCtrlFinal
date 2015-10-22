/*
 * typedefs.h
 *
 *  Created on: 20/10/2015
 *      Author: Diegol
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_
#include <stdint.h>

typedef struct  {
	uint8_t highByte;
	uint8_t lowByte;
} twoBytes;

typedef struct  {
	uint8_t mantissa;
	uint8_t exponent;
} floatBytes;


typedef struct {
	uint16_t supplyVoltage;
	uint16_t superCapCharge;
	uint16_t pvOperationVoltage;
} BinaryVoltages;

typedef struct {
	float supplyVoltage;
	float superCapCharge;
	float pvOperationVoltage;
} DecimalVoltages;


#endif /* TYPEDEFS_H_ */
