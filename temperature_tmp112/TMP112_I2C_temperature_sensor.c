/*
 * TMP112_I2C_temperature_sensor.c
 *
 *  Created on: 7/10/2015
 *      Author: Diego
 */

#include "TMP112_I2C_temperature_sensor.h"
#include <driverlib/MSP430FR57xx/driverlib.h>

const float DEGREES_PER_LSB = 0.0625;

static bool signedByteCheker(uint16_t temperatureIn16Bits);

// Esta funcion no va a valer para nada es para generar una ISR si se excede una determinada temperature
bool temperatureStatus(void) {
	if (GPIO_INPUT_PIN_HIGH == GPIO_getInputPinValue(ALERT_PORT, ALERT_PIN)) {
		return true;
	} else {
		return false;
	}
}

void configTMP112(void) {
	EUSCI_B_I2C_disable(EUSCI_B0_BASE);
	EUSCI_B_I2C_setSlaveAddress(EUSCI_B0_BASE, TMP112_SLV_ADDR0);
	EUSCI_B_I2C_enable(EUSCI_B0_BASE);

	EUSCI_B_I2C_masterSendMultiByteStart(EUSCI_B0_BASE, TMP112_CONFIG_ADDR);
	EUSCI_B_I2C_masterSendMultiByteNext(EUSCI_B0_BASE, BYTE1_INIT_CFG);
	__no_operation();
	EUSCI_B_I2C_masterSendMultiByteFinish(EUSCI_B0_BASE, BYTE2_INIT_CFG);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE))
		;
	EUSCI_B_I2C_masterSendMultiByteStop(EUSCI_B0_BASE);
}

void measureTMP112(twoBytes *temperatureBytes) {

	EUSCI_B_I2C_disable(EUSCI_B0_BASE); // To ensure the I2C disable until to change the slave address.
	EUSCI_B_I2C_setSlaveAddress(EUSCI_B0_BASE, TMP112_SLV_ADDR0);
	EUSCI_B_I2C_enable(EUSCI_B0_BASE);

	//	EUSCI_B_I2C_masterSendMultiByteStart(EUSCI_B0_BASE,TMP112_CONFIG_ADDR);
	//	EUSCI_B_I2C_masterSendMultiByteNext(EUSCI_B0_BASE,SHOOT_CONVERSION1);
	//	__no_operation();
	//	EUSCI_B_I2C_masterSendMultiByteFinish(EUSCI_B0_BASE,SHOOT_CONVERSION2);
	//	while(EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE));
	//	EUSCI_B_I2C_masterSendMultiByteStop(EUSCI_B0_BASE);

	EUSCI_B_I2C_masterSendMultiByteStart(EUSCI_B0_BASE,
	TMP112_TEMPERATURE_ADDR);
	while (EUSCI_B_I2C_masterIsStartSent(EUSCI_B0_BASE) != EUSCI_B_I2C_STOP_SEND_COMPLETE);
	EUSCI_B_I2C_masterReceiveMultiByteStop(EUSCI_B0_BASE);

	__no_operation();
	__no_operation();
	EUSCI_B_I2C_masterReceiveStart(EUSCI_B0_BASE);
	temperatureBytes->lowByte = EUSCI_B_I2C_masterReceiveMultiByteNext(
	EUSCI_B0_BASE);
	temperatureBytes->highByte = EUSCI_B_I2C_masterReceiveMultiByteFinish(
	EUSCI_B0_BASE);

	EUSCI_B_I2C_masterReceiveMultiByteStop(EUSCI_B0_BASE);

	while (EUSCI_B_I2C_masterIsStopSent(EUSCI_B0_BASE) != EUSCI_B_I2C_STOP_SEND_COMPLETE);
	while (EUSCI_B_I2C_isBusBusy(EUSCI_B0_BASE) == EUSCI_B_I2C_BUS_BUSY);
	__no_operation();
	__no_operation();
	EUSCI_B_I2C_disable(EUSCI_B0_BASE);
}


//The results achieved, shown that the behaviour is not as the datasheed indicate. The byte that is received fist is the LSB instead of the MSB.
float calculateTMP112(twoBytes *temperatureBytes) {
	uint16_t temperatureIn16Bits;
	float temperature;

	temperatureIn16Bits = ((temperatureBytes->highByte) << 4);
	temperatureIn16Bits += ((temperatureBytes->lowByte) >> 4);
	if (signedByteCheker(temperatureIn16Bits)) {
		temperatureIn16Bits |= 0xF000;
		temperatureIn16Bits = (!temperatureIn16Bits) + 1;

		temperature = (float) -(temperatureIn16Bits * DEGREES_PER_LSB);

	} else {
		temperature = (float) temperatureIn16Bits * DEGREES_PER_LSB;
	}
	return temperature;
}

static bool signedByteCheker(uint16_t temperatureIn16Bits) {
	if ((temperatureIn16Bits & BIT12) == BIT12) {
		return true;
	} else {
		return false;
	}
}

