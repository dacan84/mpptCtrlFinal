/*
 * ligth_sensor_MAX44009.c
 *
 *  Created on: 20/10/2015
 *      Author: Diegol
 */

#include "../light_MAX44009/light_sensor_MAX44009.h"
#include <driverlib/MSP430FR57xx/driverlib.h>
#include <math.h>

void measureLight(twoBytes *lightBytes) {
	EUSCI_B_I2C_setSlaveAddress(EUSCI_B0_BASE, LUX_SLV_ADDR0);

//	EUSCI_B_I2C_enable(EUSCI_B0_BASE);

	EUSCI_B_I2C_masterSendSingleByte(EUSCI_B0_BASE, LUX_HIGH_ADDR);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE));

	lightBytes->highByte = EUSCI_B_I2C_masterReceiveSingleByte(EUSCI_B0_BASE);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE));

	EUSCI_B_I2C_masterSendSingleByte(EUSCI_B0_BASE, LUX_LOW_ADDR);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE));

	lightBytes->lowByte = EUSCI_B_I2C_masterReceiveSingleByte(EUSCI_B0_BASE);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE));
	//EUSCI_B_I2C_disable(EUSCI_B0_BASE);

}

float calculateLight(twoBytes *lightBytes) {
	floatBytes lightFloatBytes;
	float light;

	lightFloatBytes.exponent = lightBytes->highByte>> 4;
	lightFloatBytes.mantissa = (lightBytes->highByte << 4) | lightBytes->lowByte;

	light = (float)(pow(2,lightFloatBytes.exponent)*lightFloatBytes.mantissa*0.045);

	return light;
}
