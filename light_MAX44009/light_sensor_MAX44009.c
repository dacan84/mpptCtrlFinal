/*
 * ligth_sensor_MAX44009.c
 *
 *  Created on: 20/10/2015
 *      Author: Diegol
 */

#include "../light_MAX44009/light_sensor_MAX44009.h"
#include <driverlib/MSP430FR57xx/driverlib.h>

static uint16_t twoPower(uint8_t exponent);

void measureLight(twoBytes *lightBytes) {
	EUSCI_B_I2C_disable(EUSCI_B0_BASE);
	EUSCI_B_I2C_setSlaveAddress(EUSCI_B0_BASE, LUX_SLV_ADDR0);
	EUSCI_B_I2C_enable(EUSCI_B0_BASE);

	EUSCI_B_I2C_masterSendSingleByte(EUSCI_B0_BASE, LUX_HIGH_ADDR);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE) == EUSCI_B_I2C_BUS_BUSY)
		;

	lightBytes->highByte = EUSCI_B_I2C_masterReceiveSingleByte(EUSCI_B0_BASE);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE))
		;

	EUSCI_B_I2C_masterSendSingleByte(EUSCI_B0_BASE, LUX_LOW_ADDR);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE) == EUSCI_B_I2C_BUS_BUSY)
		;

	lightBytes->lowByte = EUSCI_B_I2C_masterReceiveSingleByte(EUSCI_B0_BASE);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE) == EUSCI_B_I2C_BUS_BUSY)
		;
	EUSCI_B_I2C_disable(EUSCI_B0_BASE);

}

float calculateLight(twoBytes *lightBytes) {
	FloatBytes lightFloatBytes;
	float light;

	lightFloatBytes.exponent = lightBytes->highByte >> 4;
	lightFloatBytes.mantissa = (lightBytes->highByte << 4)
			| lightBytes->lowByte;

	lightFloatBytes.mantissa = lightFloatBytes.mantissa * 0.045;

	light = (float) (twoPower(lightFloatBytes.exponent) * lightFloatBytes.mantissa * 0.045);

	return light;
}

static uint16_t twoPower(uint8_t exponent) {
	uint8_t i = 0;
	uint16_t result = 1;

	if (exponent > 0) {
		for(i=0; i<exponent; ++i){
			result *= 2;
		}
	}
	return result;

}
