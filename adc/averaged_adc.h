#ifndef ADC_H
#define ADC_H

#include <msp430.h>
#include <intrinsics.h>
#include "../typedefs.h"

#define ADC_RESOLUTION 1024

float voltageReferenceSelector(uint8_t vRef);

void measureVoltages(BinaryVoltages *binaryVoltages);

void voltagesCalculation(BinaryVoltages *binaryVoltages,
		DecimalVoltages *decimalVoltages, float *voltageReference);

#endif

