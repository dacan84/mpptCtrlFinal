/*
 * ANN_implementation.h
 *
 *  Created on: 10/3/2015
 *      Author: Diego
 */

#ifndef ANN_IMPLEMENTATION_H_
#define ANN_IMPLEMENTATION_H_

#include "anndatatype.h"

#define ANN2LAYERS

#ifdef ANN3LAYERS
	float CalculoANN3Layer (AnnInputData *dataN));
#endif

#ifdef ANN2LAYERS
	float calculoANN2Layer(AnnInputData *dataN);
#endif

void normalizedInput (AnnInputData *input, AnnInputData *annInputsN);
float VoltrageReference (float tensionReferenciaN);

#endif /* ANN_IMPLEMENTATION_H_ */
