#ifndef ADC_H
#define ADC_H

#include <msp430.h>
#include <intrinsics.h>

#define ADC_RESOLUTION 1024

typedef struct {
	uint16_t supplyVoltage;
	uint16_t superCapCharge;
	uint16_t pvOperationVoltage;
} VoltageMeasures;

typedef struct {
	float supplyVoltage;
	float superCapCharge;
	float pvOperationVoltage;
} CalculateVoltages;


VoltageMeasures measureVoltages (void);

CalculateVoltages voltagesCalculation (VoltageMeasures voltageMeasures);

#endif

