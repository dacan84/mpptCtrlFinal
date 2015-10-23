/*
 * sensor_proxy.c
 *
 *  Created on: 20/10/2015
 *      Author: Diegol
 */


#include "sensor_proxy.h"
#include "light_MAX44009/light_sensor_MAX44009.h"
#include "temperature_tmp112/TMP112_I2C_temperature_sensor.h"
#include "ann_PV/anndatatype.h"


void measureSensors (AnnInputData *data) {
	twoBytes lightBytes,temperatureBytes;

	measureTMP112(&temperatureBytes);
	data->temp = calculateTMP112(&temperatureBytes);
	__no_operation();
	__no_operation();
	measureLight(&lightBytes);
	data->lux = calculateLight(&lightBytes);

}


