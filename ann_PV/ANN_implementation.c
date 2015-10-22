/*
 * ANN_implementation.c
 *
 *  Created on: 10/3/2015
 *      Author: Diego
 */

#include <stdio.h>
#include <stdint.h>
//#include <math.h>
#include "ANN_implementation.h"
#include "ANN_memory_saving.h"
#include "ANN_normalizad_limits.h"
//#include "../adc/averaged_adc.h"
//#include "../sensores/Light.h"



/* La matriz de salida constara de uno o 2 elementos. */
//float output[1]; // La dimensión dependera del vector de salida.

//TODO: implementar la devolución de la red en la ANN y ademas pasar por parametro un tipo de datos input, un la entrada y la salida.

static float VoltrageReferenceDenormalized (float VRefN);
static float CalTanh(float x);

#ifdef ANN3LAYERS
static void ClearArraysANN3Layer(void);

static void ClearArraysANN3Layer(void) {
	uint8_t i = 1;

	for (i = 1; i < FILAS_RINTERMEDIO1; ++i) {
		resultadoIntermedio1[i][0] = 0;
		if (i < FILAS_RINTERMEDIO2) {
			resultadoIntermedio2[i][0] = 0;
		}
	}
	tensionReferenciaN[0][0] = 0;
}

/* La operacion tangente hipperbólica requiere variables float con la funcion declarada previamente*/
float CalculoANN3Layer(AnnInputData dataN) {
	uint8_t i, j, z;
	/* La matriz de entrada esta compuesta por 3 elementos:
	 * [el primer elemento corresponde al umbral, Luz, Temperatura]. */
	float inputsN[3][1];
	float vRef = 0
	float vRefN = 0;

	inputsN [0][0] = 1;
	inputsN [1][0] = dataN.lux;
	inputsN [2][0] = dataN.temp;

	/*
	 % A con k filas y m columnas, t = size(A)
	 % k = t(1); m = t(2);
	 % B con m filas y n columnas. s = size(B)
	 % m = s(1); n = s(2);
	 % C es la matriz que resulta del producto AB.
	 % C presenta k filas y n columnas.
	 %
	 % C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j]
	 % + ... + A[i][m-1] * B[m-1][j]
	 % */

	i = 0;
	j = 0;
	z = 0;
	// Generamos la matriz C.
	for (i = 0; i < FILAS_B1IW11; ++i) {
		for (j = 0; j < COLUMNAS_INPUTS; ++j) {
			for (z = 0; z < FILAS_INPUTS; ++z) {
				resultadoIntermedio1[i + 1][j] = resultadoIntermedio1[i + 1][j]
						+ b1Iw11[i][z] * inputsN[z][j];
			}
		}
	}

	i = 1;
	for (i = 1; i < FILAS_RINTERMEDIO1; ++i) {
		resultadoIntermedio1[i][0] = (float) CalTanh(resultadoIntermedio1[i][0]);
	}

	i = 0;
	j = 0;
	z = 0;
	// Generamos la matriz C.
	for (i = 0; i < FILAS_B2LW21; ++i) {
		for (j = 0; j < COLUMNAS_RINTERMEDIO1; ++j) {
			for (z = 0; z < FILAS_RINTERMEDIO1; ++z) {
				resultadoIntermedio2[i + 1][j] = resultadoIntermedio2[i + 1][j]
						+ b2Lw21[i][z] * resultadoIntermedio1[z][j];
			}
		}
	}

	i = 1;
	for (i = 1; i < FILAS_RINTERMEDIO2; ++i) {
		resultadoIntermedio2[i][0] = (float) CalTanh(resultadoIntermedio2[i][0]);
	}

	i = 0;
	j = 0;
	z = 0;
	// Generamos la matriz C.
	for (i = 0; i < FILAS_B3LW32; ++i) {
		for (j = 0; j < COLUMNAS_RINTERMEDIO2; ++j) {
			for (z = 0; z < FILAS_RINTERMEDIO2; ++z) {
				tensionReferenciaN[i][j] = tensionReferenciaN[i][j]
						+ b3Lw32[i][z] * resultadoIntermedio2[z][j];
				vRefN = (float) tensionReferenciaN[i][j];// funcion de salida es lineal con ganancia unidad.
			}
		}
	}
	ClearArraysANN3Layer();
	vRef = VoltrageReferenceDenormalized(vRefN);
	return (float)vRef;
}
#endif

#ifdef ANN2LAYERS
static void ClearArraysANN2Layer(void);

static void ClearArraysANN2Layer(void) {
	uint8_t i = 1;

	for (i = 1; i < FILAS_RINTERMEDIO1; ++i) {
		resultadoIntermedio1[i][0] = 0;
	}
	tensionReferenciaN[0][0] = 0;
}

float CalculoANN2Layer(AnnInputData dataN) {
	uint8_t i, j, z;
	/* La matriz de entrada esta compuesta por 3 elementos:
	 * [el primer elemento corresponde al umbral, Luz, Temperatura]. */
	float inputsN[3][1];
	float vRefN = 0;
	float vRef = 0;

	inputsN [0][0] = 1;
	inputsN [1][0] = dataN.lux;
	inputsN [2][0] = dataN.temp;

	/*
	 % A con k filas y m columnas, t = size(A)
	 % k = t(1); m = t(2);
	 % B con m filas y n columnas. s = size(B)
	 % m = s(1); n = s(2);
	 % C es la matriz que resulta del producto AB.
	 % C presenta k filas y n columnas.
	 %
	 % C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j]
	 % + ... + A[i][m-1] * B[m-1][j]
	 % */

	i = 0;
	j = 0;
	z = 0;
	// Generamos la matriz C.
	for (i = 0; i < FILAS_B1IW11; ++i) {
		for (j = 0; j < COLUMNAS_INPUTS; ++j) {
			for (z = 0; z < FILAS_INPUTS; ++z) {
				resultadoIntermedio1[i + 1][j] = resultadoIntermedio1[i + 1][j]
						+ b1Iw11[i][z] * inputsN[z][j];
			}
		}
	}

	i = 1;
	for (i = 1; i < FILAS_RINTERMEDIO1; ++i) {
		resultadoIntermedio1[i][0] = (float) CalTanh(resultadoIntermedio1[i][0]);
	}

	i = 0;
	j = 0;
	z = 0;
	// Generamos la matriz C.
	for (i = 0; i < FILAS_B2LW21; ++i) {
		for (j = 0; j < COLUMNAS_RINTERMEDIO1; ++j) {
			for (z = 0; z < FILAS_RINTERMEDIO1; ++z) {
				tensionReferenciaN[i][j] = tensionReferenciaN[i][j]
						+ b2Lw21[i][z] * resultadoIntermedio1[z][j];
				vRefN = (float) tensionReferenciaN[i][j];// funcion de salida es lineal con ganancia unidad.
			}
		}
	}
	ClearArraysANN2Layer();
	vRef = VoltrageReferenceDenormalized(vRefN); //TODO: esto igual sobra
	return (float) vRef;
}
#endif

static float CalTanh(float x) {
	float resul;

	if (x <= -5.3) {
		resul = -1;
	} else if (x >= 5.3) {
		resul = 1;
	} else if ((x > -5.3) && (x < -0.9)) {
		// resul = 0.0127*x*x*x+0.1435*x*x+0.5234*x-0.3840;
		resul = 0.0014 * x * x * x * x * x + 0.0273 * x * x * x * x
				+ 0.2043 * x * x * x + 0.7599 * x * x + 1.4179 * x + 0.0746;
	} else if ((x > 0.9) && (x < 5.3)) {
		//resul =  0.0127*x*x*x-0.1435*x*x+0.5234*x+0.3840;
		resul = 0.0014 * x * x * x * x * x - 0.0273 * x * x * x * x
				+ 0.2043 * x * x * x - 0.7599 * x * x + 1.4179 * x - 0.0746;
	} else if ((x >= -0.9) && (x <= 0.9)) {
		//resul = x-(1/3)*x*x*x+(2/15)*x*x*x*x*x-17/315*x*x*x*x*x*x*x;
		resul = -0.2358 * x * x * x + 0.9834 * x;
	}

	return resul;
}

AnnInputData NormalizedInput (AnnInputData input) {
		AnnInputData annInputsN;
		annInputsN.lux = (input.lux-LIGHT_LOWER_LIMIT)/(LIGHT_UPPER_LIMIT-LIGHT_LOWER_LIMIT);
		annInputsN.temp = (input.temp-TEMPERATURE_LOWER_LIMIT)/(TEMPERATURE_UPPER_LIMIT-TEMPERATURE_LOWER_LIMIT);


		return annInputsN;
}

//TODO: esta función, no se si me hará falta.
static float VoltrageReferenceDenormalized(float VRefN) {
	float Vref = 0;

	Vref = (VRefN + VMMP_REF_LOWER_LIMIT)
			* (VMMP_REF_UPPER_LIMIT - VMMP_REF_LOWER_LIMIT);

	return Vref;
}

