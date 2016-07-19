/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/Grace.h>
#include "temperature_tmp112/TMP112_I2C_temperature_sensor.h"
#include "sensor_proxy.h"
#include "adc_proxy.h"
#include "typedefs.h"
#include "ann_PV/anndatatype.h"
#include "mppt_ctrl.h"
#include <driverlib/MSP430FR57xx/driverlib.h>//TODO: para los gpio de prueba
#include <driverlib/MSP430FR57xx/timer_a.h>

/*
 *  ======== main ========
 */

//AnnInputData enviromentalMeasures;
//DecimalVoltages voltages;
float setPoint=0;
//TODO: quitar, solo para verificacion
 uint16_t exponente = 0;
 uint16_t mantisa  = 0;

int main(void) {
	Grace_init();                   // Activate Grace-generated configuration
	// >>>>> Fill-in user code here <<<<<
	//configTMP112();

	//__bis_SR_register(GIE);
	//Timer_A_startCounter(TIMER_A0_BASE,TIMER_A_CONTINUOUS_MODE);

	while (1) {
		mpptWindowComparatorCtrl();
//		__no_operation();
	}
}
