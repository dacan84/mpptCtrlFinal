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
/*
 *  ======== main ========
 */

float light, temperature;

int main(void) {
	Grace_init();                   // Activate Grace-generated configuration
	// >>>>> Fill-in user code here <<<<<

	configTMP112();

	while (1) {
		measureSensors(&light,&temperature);
	}
	return (0);
}
