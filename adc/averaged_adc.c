#include "averaged_adc.h"
#include <driverlib/MSP430FR57xx/driverlib.h>

//#define NUMBER_SAMPLES  4
//TODO: comprobar como funciona la medida del control de la tensión interna puesto que da 1.8V, por otro lado, pensar que hacemos con las referencias para la medida.

static uint16_t voltageAdquisitionMeasure(uint8_t channel);
static float binaryVoltageToDecimalVoltage(uint16_t binaryVoltage,
		float *voltageReference);

static uint16_t voltageAdquisitionMeasure(uint8_t channel) {
	uint16_t voltage;

	ADC10_B_disableConversions(ADC10_B_BASE,ADC10_B_COMPLETECONVERSION);
	ADC10_B_configureMemory(ADC10_B_BASE, channel,
	ADC10_B_VREFPOS_INT, ADC10_B_VREFNEG_AVSS);

	ADC10_B_startConversion(ADC10_B_BASE, ADC10_B_SINGLECHANNEL);
	while (ADC10_B_isBusy(ADC10_B_BASE) == ADC10_B_BUSY)
		;
	voltage = ADC10_B_getResults(ADC10_B_BASE);

	return voltage;
}

void measureVoltages(BinaryVoltages *binaryVoltages) {
	Ref_enableReferenceVoltage(REF_BASE);
	ADC10_B_enableReferenceBurst(ADC10_B_BASE);
	ADC10_B_enable(ADC10_B_BASE);

	binaryVoltages->supplyVoltage = voltageAdquisitionMeasure(
			ADC10_B_INPUT_BATTERYMONITOR);
	binaryVoltages->superCapCharge = voltageAdquisitionMeasure(
	ADC10_B_INPUT_A0);
	binaryVoltages->pvOperationVoltage = voltageAdquisitionMeasure(
	ADC10_B_INPUT_A1);

	ADC10_B_disable(ADC10_B_BASE);
	ADC10_B_disableReferenceBurst(ADC10_B_BASE);
	Ref_disableReferenceVoltage(REF_BASE);
}

static float binaryVoltageToDecimalVoltage(uint16_t binaryVoltage,
		float *voltageReference) {
	float voltage;
	voltage = *voltageReference / ADC_RESOLUTION * binaryVoltage;
	return voltage;
}

//TODO: implement a function that change de reference depending on the voltage measured in the supply voltage.
float voltageReferenceSelector(uint8_t vRef) {
	float voltageReference;

	switch (vRef) {
	case REF_VREF1_5V:
		Ref_setReferenceVoltage(REF_BASE, REF_VREF1_5V);
		return voltageReference = 1.5;

	case REF_VREF2_0V:
		Ref_setReferenceVoltage(REF_BASE, REF_VREF2_0V);
		return voltageReference = 2.0;

	case REF_VREF2_5V:
		Ref_setReferenceVoltage(REF_BASE, REF_VREF2_5V);
		return voltageReference = 2.5;

	default:
		Ref_setReferenceVoltage(REF_BASE, REF_VREF1_5V);
		return voltageReference = 1.5;
	}
}

void voltagesCalculation(BinaryVoltages *binaryVoltages,
		DecimalVoltages *decimalVoltages, float *voltageReference) {

	decimalVoltages->supplyVoltage = binaryVoltageToDecimalVoltage(
			binaryVoltages->supplyVoltage, voltageReference);
	decimalVoltages->superCapCharge = binaryVoltageToDecimalVoltage(
			binaryVoltages->superCapCharge, voltageReference);
	decimalVoltages->pvOperationVoltage = binaryVoltageToDecimalVoltage(
			binaryVoltages->pvOperationVoltage, voltageReference);

}
