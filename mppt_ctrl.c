/*
 * mppt_ctrl.c
 *
 *  Created on: 13/7/2015
 *      Author: Diego
 */

#include "mppt_ctrl.h"
#include "ann_proxy.h"
#include <driverlib/MSP430FR57xx/driverlib.h>
#include <driverlib/MSP430FR57xx/inc/hw_memmap.h>
#include "adc/averaged_adc.h"

static void CompareVoltageLevelsAndActuaction (float vRef, float currentVolt);

void MpptCtrl (void){
	float vRef;
	float currentVolt;

	vRef = CalculateVref();
	currentVolt = MeasurePVvoltage() * VOLTAGE_CONVERTION_REFERENCE / 1024;
	CompareVoltageLevelsAndActuaction(vRef,currentVolt);
}


static void CompareVoltageLevelsAndActuaction (float vRef, float currentVolt){
	if (currentVolt >= vRef){
		GPIO_setOutputLowOnPin(GPIO_PORT_P2,GPIO_PIN1);
	} else {
		GPIO_setOutputLowOnPin(GPIO_PORT_P2,GPIO_PIN1);
	}
}
