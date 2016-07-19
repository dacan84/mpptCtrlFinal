/*
 * dactest.c
 *
 *  Created on: 18/7/2016
 *      Author: Diegol
 */


#include "dactest.h"
#include <stdint.h>
#include <driverlib/MSP430FR57xx/driverlib.h>

void setDACValue (float vref){
	uint8_t out;

	out = (uint8_t)vref;

	if(out && GPIO_PIN0){
		GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN0);
	} else {
		GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN0);
	}

	if(out && GPIO_PIN1){
			GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN1);
	} else {
			GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN1);
	}


	if(out && GPIO_PIN2){
			GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN2);
	} else {
			GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN2);
	}


	if(out && GPIO_PIN3){
			GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN3);
	} else {
			GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN3);
	}


	if(out && GPIO_PIN4){
			GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN4);
	} else {
			GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN4);
	}


	if(out && GPIO_PIN5){
			GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN5);
	} else {
			GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN5);
	}


	if(out && GPIO_PIN6){
			GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);
	} else {
			GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);
	}


	if(out && GPIO_PIN7){
			GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN7);
	} else {
			GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN7);
	}

}

