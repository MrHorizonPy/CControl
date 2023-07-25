/*
 * mul.c
 *
 *  Created on: 1 mars 2020
 *      Author: Daniel Mårtensson
 */

#include "../../Headers/functions.h"

/*
 * C = A*B
 * A [row_a*column_a]
 * B [column_a*column_b]
 * C [row_a*column_b]
 */
void mul(float A[], float B[], float C[], size_t row_a, size_t column_a, size_t column_b) {
	/* Decleration */
	size_t i, j, k;

	/* Data matrix */
	float* data_a, * data_b;

	for (i = 0; i < row_a; i++) {
		/* Then we go through every column of b */
		for (j = 0; j < column_b; j++) {
			data_a = A;
			data_b = &B[j];

			C[0] = 0; /* Reset */
			/* And we multiply rows from a with columns of b */
			for (k = 0; k < column_a; k++) {
				*C += data_a[0] * data_b[0];
				data_a++;
				data_b += column_b;
			}
			C++; /* ;) */
		}
		A += column_a;
	}
}

/*
 * GNU Octave code:
 *  >> A = [4 23; 2  5];
	>> B = [3; 1];
	>> C = A*B
	C =

	   35
	   11

	>>
 *
 */


