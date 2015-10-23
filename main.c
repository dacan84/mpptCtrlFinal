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

/*
 *  ======== main ========
 */

AnnInputData enviromentalMeasures;
DecimalVoltages voltages;

int main(void) {
	Grace_init();                   // Activate Grace-generated configuration
	// >>>>> Fill-in user code here <<<<<

	//configTMP112();

	while (1) {
		MpptCtrl();
		measureSensors(&enviromentalMeasures);
		voltages = adquisitionVoltages();
	}

}
