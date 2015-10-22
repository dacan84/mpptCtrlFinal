/*
 * ann_proxy.c
 *
 *  Created on: 8/7/2015
 *      Author: Diego
 */


#include "ann_PV/ANN_implementation.h"
#include "ann_PV/anndatatype.h"
#include "sensor_proxy.h"

float CalculateVref (void) {
	AnnInputData data, dataN;
	//FIXME: en principio devuelve el valor ya estandarizado (desnormalizado) de tensión.
	//float VrefN;
	float vRef;

	data = MeasureSensors();
	dataN = NormalizedInput(data);

	#ifdef ANN2LAYERS
	vRef = CalculoANN2Layer(dataN);
	#endif

	#ifdef ANN3LAYERS
	vRef = CalculoANN3Layer(dataN);
	#endif

	return vRef;
}
