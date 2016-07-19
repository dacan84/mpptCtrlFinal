/*
 * adc_proxy.c
 *
 *  Created on: 22/10/2015
 *      Author: Diegol
 */

#include "adc_proxy.h"
#include "adc/averaged_adc.h"
#include <driverlib/MSP430FR57xx/driverlib.h>

DecimalVoltages adquisitionVoltages (void){
		BinaryVoltages binaryVoltages;
		DecimalVoltages decimalVoltages;
		float voltageReference;

		voltageReference = voltageReferenceSelector(REF_VREF2_5V);
		measureVoltages(&binaryVoltages);
		voltagesCalculation(&binaryVoltages,&decimalVoltages,&voltageReference);
		return decimalVoltages;
}


