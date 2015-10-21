/*
 * sensor_proxy.c
 *
 *  Created on: 20/10/2015
 *      Author: Diegol
 */


#include "sensor_proxy.h"
#include "light_MAX44009/light_sensor_MAX44009.h"
#include "temperature_tmp112/TMP112_I2C_temperature_sensor.h"


void measureSensors (float *light, float *temperature) {
	twoBytes lightBytes,temperatureBytes;

	measureTMP112(&temperatureBytes);
	*temperature = calculateTMP112(&temperatureBytes);
//
//	measureLight(&lightBytes);
//	*light = calculateLight(&lightBytes);

}


