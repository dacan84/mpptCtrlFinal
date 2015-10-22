/*
 * ANN_normalizad_limits.h
 *
 *  Created on: 14/7/2015
 *      Author: Diego
 */

#ifndef ANN_ANN_NORMALIZAD_LIMITS_H_
#define ANN_ANN_NORMALIZAD_LIMITS_H_

/* Definir l�mites de normalizaci�n. */
	/* L�mites luz.*/
	#define LIGHT_UPPER_LIMIT			100000
	#define LIGHT_LOWER_LIMIT			1000

	/* L�mites temperatura. */
	#define TEMPERATURE_UPPER_LIMIT		 75
	#define TEMPERATURE_LOWER_LIMIT		-20

	/* L�mites valores de tensi�n. */
	#define VOC_UPPER_LIMIT				5
	#define VOC_LOWER_LIMIT				1.8

	#define VMMP_REF_UPPER_LIMIT		0.74*5
	#define VMMP_REF_LOWER_LIMIT		0.74*1.8


#endif /* ANN_ANN_NORMALIZAD_LIMITS_H_ */
