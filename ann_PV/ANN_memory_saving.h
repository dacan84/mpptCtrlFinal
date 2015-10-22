/*
 * ANN_memory_saving.h
 *
 *  Created on: 25/3/2015
 *      Author: Diego
 */

#ifndef ANN_MEMORY_SAVING_H_
#define ANN_MEMORY_SAVING_H_
/* Antes de programar la ANN es necesario definir el número de capas y
 * las dimensiones de la misma para que se compilen las funciones
 * y parámetros necesarios para su correcto funcionamiento. */
	#define NETWORK21
	#define ANN2LAYERS


	#define FILAS_INPUTS		3
	#define COLUMNAS_INPUTS		1

	/* Vector de salida común. */
	#define FILAS_VREFN			1
	#define COLUMNAS_VREFN		1

	float tensionReferenciaN [FILAS_VREFN][COLUMNAS_VREFN] = {
			{0}
	};

	#ifdef NETWORK631

		/* Se definen los valores de los pesos de las matrices de la ANN.*/
		#define FILAS_B1IW11		6
		#define COLUMNAS_B1IW11		3

		static const float b1Iw11[FILAS_B1IW11][COLUMNAS_B1IW11] = {
				{-4.1228,	 2.1502,	 1.4281},
				{ 0.13292,  -1.7624 ,    2.1475},
				{ 0.25937,   4.0117 ,    1.7858},
				{ 0.23423,  -0.93467,   -1.7368},
				{-2.618,    -2.9238,    -1.5757},
				{-2.9083,    2.0272,     1.2967},
		};

		#define FILAS_RINTERMEDIO1		FILAS_B1IW11+1
		#define COLUMNAS_RINTERMEDIO1	1

		float resultadoIntermedio1[FILAS_RINTERMEDIO1][COLUMNAS_RINTERMEDIO1] = {
				{1},
				{0},
				{0},
				{0},
				{0},
				{0},
				{0}
		};


		#define FILAS_B2LW21		3
		#define COLUMNAS_B2LW21		6
		static const float b2Lw21[FILAS_B2LW21][COLUMNAS_B2LW21] = {
				{ 3.5097,  -2.0613,   1.8027,    -0.35374,   -0.61249,  -0.23467},
				{-0.22758,  0.27913,  0.093191,  -0.41848,    0.046984, -1.0759},
				{-2.0538,   2.5734,  -1.8432,  	 -1.1108,     0.82392,   0.31374}
		};

		#define FILAS_RINTERMEDIO2			FILAS_B2LW21+1
		#define COLUMNAS_RINTERMEDIO2		1
		float resultadoIntermedio2[FILAS_RINTERMEDIO2][COLUMNAS_RINTERMEDIO2] = {
				{1},
				{0},
				{0}
		};

		#define FILAS_B3LW32		1
		#define COLUMNAS_B3LW32		4
		static const float b3Lw32[FILAS_B3LW32][COLUMNAS_B3LW32] = {
				{-0.45341,   -0.55917,    -0.021222,	-0.00098412}
		};

	#endif

	#ifdef NETWORK421

		#define FILAS_B1IW11		4
		#define COLUMNAS_B1IW11		3

		/* Se definen los valores de los pesos de las matrices de la ANN.*/
		static const float b1Iw11[FILAS_B1IW11][COLUMNAS_B1IW11] = {
				{1.9549,  	-0.055038, 	-2.1733},
				{2.0094,  	-3.703, 	 3.6165},
				{-12.8204,  -12.7495, 	-0.61469},
				{3.1387,   	 7.5155, 	-4.4244}
		};


		#define FILAS_RINTERMEDIO1		FILAS_B1IW11+1
		#define COLUMNAS_RINTERMEDIO1	1

		float resultadoIntermedio1[FILAS_RINTERMEDIO1][COLUMNAS_RINTERMEDIO1] = {
				{1},
				{0},
				{0},
				{0},
				{0}
		};

		#define FILAS_B2LW21		2
		#define COLUMNAS_B2LW21		5

		static const float b2Lw21[FILAS_B2LW21][COLUMNAS_B2LW21] = {
				{ 13.387,	 -2.0478,	 0.12775, 	9.4193, 	-0.4947},
				{-11.7159, 	-0.75468, 	12.5854,	1.3579, 	-0.11956}
		};

		#define FILAS_RINTERMEDIO2			FILAS_B2LW21+1
		#define COLUMNAS_RINTERMEDIO2		1

		float resultadoIntermedio2[FILAS_RINTERMEDIO2][COLUMNAS_RINTERMEDIO2] = {
				{1},
				{0},
				{0}
		};

		#define FILAS_B3LW32		1
		#define COLUMNAS_B3LW32		3

		static const float b3Lw32[FILAS_B3LW32][COLUMNAS_B3LW32] = {
				{3.5178,   -3.341,	 -0.27858}
		};

	#endif

	#ifdef NETWORK51

		/* Se definen los valores de los pesos de las matrices de la ANN.*/
		#define FILAS_B1IW11		5
		#define COLUMNAS_B1IW11		3

		static const float b1Iw11[FILAS_B1IW11][COLUMNAS_B1IW11] = {
				{-0.44562,	 0.29923,	 -0.29461},
				{ 0.2779,  	 0.64061,     0.83424},
				{ 0.51133,  -0.11978,    -0.12344},
				{ 0.13303,	 0.24116,     1.04660},
				{-0.60905,   0.30002,     0.83192}
		};

		#define FILAS_RINTERMEDIO1		FILAS_B1IW11+1
		#define COLUMNAS_RINTERMEDIO1	1

		float resultadoIntermedio1[FILAS_RINTERMEDIO1][COLUMNAS_RINTERMEDIO1] = {
				{1},
				{0},
				{0},
				{0},
				{0},
				{0}
		};

		#define FILAS_RINTERMEDIO2			FILAS_B2LW21+1
		#define COLUMNAS_RINTERMEDIO2		1
		float resultadoIntermedio2[FILAS_RINTERMEDIO2][COLUMNAS_RINTERMEDIO2] = {
				{1},
				{0},
				{0}
		};

		#define FILAS_B3LW32		1
		#define COLUMNAS_B3LW32		4
		static const float b3Lw32[FILAS_B3LW32][COLUMNAS_B3LW32] = {
				{-0.45341,   -0.55917,    -0.021222,	-0.00098412}
		};

	#endif

	#ifdef NETWORK21
		/* Se definen los valores de los pesos de las matrices de la ANN.*/
		#define FILAS_B1IW11		2
		#define COLUMNAS_B1IW11		3

		static const float b1Iw11[FILAS_B1IW11][COLUMNAS_B1IW11] = {
				{-0.25044, -0.24245, 0.23006},
				{-0.72088,	0.89272, 0.68782}
		};

		#define FILAS_RINTERMEDIO1		FILAS_B1IW11+1
		#define COLUMNAS_RINTERMEDIO1	1

		float resultadoIntermedio1[FILAS_RINTERMEDIO1][COLUMNAS_RINTERMEDIO1] = {
				{1},
				{0},
				{0},
		};

		#define FILAS_B2LW21		1
		#define COLUMNAS_B2LW21		3
		static const float b2Lw21[FILAS_B2LW21][COLUMNAS_B2LW21] = {
				{0.44977, -0.56567, 0.063738}
		};

	#endif

#endif /* ANN_MEMORY_SAVING_H_ */
