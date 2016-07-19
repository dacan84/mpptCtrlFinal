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
#include "dactest.h"

const float SC_VOLTAGE_LIMIT_2V1 = 2.1; /* Sirve para definir el máximo valor de tensión
que el supercap es capaz de soportar. En el caso generico en el que se está
trabajando este valor es de 2.1V, valor que no se puede introducir de forma
directa, es necesario calcular la representación decimal del mismo en 10 bits.
Para ello se realiza la siguiente operación : NºDecimal = Limite_Vsc/(Vcc/2^10)
En nuestro caso: NºDecimal(2.1V) = 2.1/(3/1024) = 716.8 */

const float SC_VOLTAGE_LIMIT_2V5 = 2.5;
const float SC_VOLTAGE_LIMIT_5V = 5;

extern float setPoint;

#define WINDOW              0.1		/* Este valor establece la ventana de
                                    comparación para el comparador de ventana
                                    implementado. */

static void buckConverterCtrl(float vRef, float currentVolt);
static void buckConverterCtrlWindow(float vRef, float currentVolt);
static void buckStop(void);
static bool superCapConnectionCtrl(float superCapVoltage);

//TODO: en la decision del mppt para habilitar o deshabilitar el MPPT.
void mpptCtrl(void) {
	float voltageSetpoint = 0.0;
	bool superCapActivationCondition = true;
	DecimalVoltages decimalVoltages;

	decimalVoltages = adquisitionVoltages();

	superCapActivationCondition = superCapConnectionCtrl(decimalVoltages.superCapCharge);

	if (superCapActivationCondition) {
		voltageSetpoint = calculateVref();
		setDACValue(voltageSetpoint); // Poner en el valor en el convertidor digital analógico y evaluar el funcionamiento
		setPoint = voltageSetpoint;
		buckConverterCtrl(voltageSetpoint, decimalVoltages.pvOperationVoltage);
	} else {
		buckStop();
	}
}


//TODO: en la decision del mppt para habilitar o deshabilitar el MPPT.
void mpptWindowComparatorCtrl(void) {
	float voltageSetpoint = 0.0;
	bool superCapActivationCondition = true;
	DecimalVoltages decimalVoltages;

	decimalVoltages = adquisitionVoltages();

	superCapActivationCondition = superCapConnectionCtrl(decimalVoltages.superCapCharge);

	if (superCapActivationCondition) {
		voltageSetpoint = calculateVref();
		setDACValue(voltageSetpoint); // Poner en el valor en el convertidor digital analógico y evaluar el funcionamiento
		setPoint = voltageSetpoint;
		buckConverterCtrlWindow(voltageSetpoint, decimalVoltages.pvOperationVoltage);
	} else {
		buckStop();
	}
}



static void buckConverterCtrl(float vRef, float currentVolt) {

	if (currentVolt >= vRef) {
		GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
		//GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1); //ORIGINAL
	} else {
		GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
		//GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1); //ORIGINAL
	}
}

static void buckConverterCtrlWindow(float vRef, float currentVolt) {

	if (currentVolt+WINDOW >= vRef) {
		GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
		//GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1); //ORIGINAL
	} else if (currentVolt-WINDOW <= vRef){
		GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
		//GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1); //ORIGINAL
	}
}

static void buckStop(void) {
	GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

static bool superCapConnectionCtrl(float superCapVoltage) {

	if (superCapVoltage < SC_VOLTAGE_LIMIT_2V1) {
		//SuperCapChargeON();
		GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
		return true;
	} else {
		//SuperCapChargeOFF();
		GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
		return false;
	}
}
