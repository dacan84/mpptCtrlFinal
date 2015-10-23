/*
 * ann_proxy.c
 *
 *  Created on: 8/7/2015
 *      Author: Diego
 */


#include "ann_PV/ANN_implementation.h"
#include "ann_PV/anndatatype.h"
#include "sensor_proxy.h"

float calculateVref (void) {
	AnnInputData data, dataN;
	//FIXME: en principio devuelve el valor ya estandarizado (desnormalizado) de tensi�n.
	//float VrefN;
	float vRef;

	measureSensors(&data);
	normalizedInput(&data,&dataN);

	#ifdef ANN2LAYERS
	vRef = calculoANN2Layer(&dataN);
	#endif

	#ifdef ANN3LAYERS
	vRef = CalculoANN3Layer(dataN);
	#endif

	return vRef;
}
