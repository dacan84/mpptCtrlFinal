#include <stdint.h>
#include <msp430.h>
#include <driverlib/MSP430FR57xx/driverlib.h>
#include <intrinsics.h>
#include "averaged_adc.h"

//#define NUMBER_SAMPLES  4

static uint16_t voltageSupplyMeasure(void);
static uint16_t superCapChargeMeasure(uint8_t channel);
static uint16_t pvOperationVoltageMeasure(uint8_t channel);
static float voltageSupplyCalculation(uint16_t supplyVoltage);
static float superCapChargeCalculation(uint16_t superCapVoltage);
static float pvOperationVoltageCalculation(uint16_t pvOperationVoltage);

static uint16_t voltageSupplyMeasure(void) {
	uint16_t supplyVoltage;
	ADC10_B_configureMemory(ADC10_B_BASE, ADC10_B_INPUT_BATTERYMONITOR,
	ADC10_B_VREFPOS_INT, ADC10_B_VREFNEG_AVSS);
	ADC10_B_startConversion(ADC10_B_BASE, ADC10_B_SINGLECHANNEL);
	while (ADC10_B_isBusy(ADC10_B_BASE) == ADC10_B_BUSY);
	supplyVoltage = ADC10_B_getResults(ADC10_B_BASE);
	return supplyVoltage;
}

static uint16_t superCapChargeMeasure(uint8_t channel) {
	uint16_t superCapVoltage;
	ADC10_B_configureMemory(ADC10_B_BASE, channel, ADC10_B_VREFPOS_INT,
			ADC10_B_VREFNEG_AVSS);
	ADC10_B_startConversion(ADC10_B_BASE, ADC10_B_SINGLECHANNEL);
	while (ADC10_B_isBusy(ADC10_B_BASE) == ADC10_B_BUSY);
	superCapVoltage = ADC10_B_getResults(ADC10_B_BASE);
	return superCapVoltage;

}
static uint16_t pvOperationVoltageMeasure(uint8_t channel) {
	uint16_t pvOperationVoltage;
	ADC10_B_configureMemory(ADC10_B_BASE, channel, ADC10_B_VREFPOS_INT,
	ADC10_B_VREFNEG_AVSS);
	ADC10_B_startConversion(ADC10_B_BASE, ADC10_B_SINGLECHANNEL);
	while (ADC10_B_isBusy(ADC10_B_BASE) == ADC10_B_BUSY);
	pvOperationVoltage = ADC10_B_getResults(ADC10_B_BASE);
	return pvOperationVoltage;
}

VoltageMeasures measureVoltages (void) {

	VoltageMeasures voltageMeasures;

	ADC10_B_enable(ADC10_B_BASE);
	voltageMeasures.supplyVoltage = voltageSupplyMeasure();
	voltageMeasures.superCapCharge = superCapChargeMeasure(ADC10_B_INPUT_A0);
	voltageMeasures.pvOperationVoltage = pvOperationVoltageMeasure(ADC10_B_INPUT_A1);
	ADC10_B_disable(ADC10_B_BASE);

	return voltageMeasures;
}

static float voltageSupplyCalculation(uint16_t supplyVoltage) {

}

static float superCapChargeCalculation(uint16_t superCapVoltage) {

}

static float pvOperationVoltageCalculation(uint16_t pvOperationVoltage) {

}


CalculateVoltages voltagesCalculation (VoltageMeasures voltageMeasures){
	CalculateVoltages calculateVoltages;

	calculateVoltages.supplyVoltage = voltageSupplyCalculation(voltageMeasures.supplyVoltage);
	calculateVoltages.superCapCharge = superCapChargeCalculation(voltageMeasures.superCapCharge);
	calculateVoltages.pvOperationVoltage = pvOperationVoltageCalculation(voltageMeasures.pvOperationVoltage);

	return calculateVoltages;
}
