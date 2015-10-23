/*
 * mppt_ctrl.c
 *
 *  Created on: 13/7/2015
 *      Author: Diego
 */

#include "mppt_ctrl.h"
#include "ann_proxy.h"
#include <driverlib/MSP430FR57xx/driverlib.h>
#include "adc_proxy.h"
#include "typedefs.h"
#include <stdbool.h>

const float SC_VOLTAGE_LIMIT = 2.1; /* Sirve para definir el máximo valor de tensión
que el supercap es capaz de soportar. En el caso generico en el que se está
trabajando este valor es de 2.1V, valor que no se puede introducir de forma
directa, es necesario calcular la representación decimal del mismo en 10 bits.
Para ello se realiza la siguiente operación : NºDecimal = Limite_Vsc/(Vcc/2^10)
En nuestro caso: NºDecimal(2.1V) = 2.1/(3/1024) = 716.8 */
#define WINDOW              0x03    /* Este valor establece la ventana de
                                    comparación para el comparador de ventana
                                    implementado. */

static void buckConverterCtrl(float vRef, float currentVolt);
static void buckStop(void);
static bool superCapConnectionCtrl(float superCapVoltage);

void mpptCtrl(void) {
	float vRef;
	bool superCapActivationCondition = true;
	DecimalVoltages decimalVoltages;

	decimalVoltages = adquisitionVoltages();

	superCapActivationCondition = superCapConnectionCtrl(decimalVoltages.superCapCharge);

	if (superCapActivationCondition) {
		vRef = calculateVref();
		buckConverterCtrl(vRef, decimalVoltages.pvOperationVoltage);
	} else {
		buckStop();
	}


}

static void buckConverterCtrl(float vRef, float currentVolt) {
	if (currentVolt >= vRef) {
		GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
	} else {
		GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
	}
}


static void buckStop(void) {
	GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
}


static bool superCapConnectionCtrl(float superCapVoltage) {

	if (superCapVoltage < SC_VOLTAGE_LIMIT) {
		//SuperCapChargeON();
		GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
		return true;
	} else {
		//SuperCapChargeOFF();
		GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
		return false;
	}
}

