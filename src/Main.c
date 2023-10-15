/*
 ============================================================================
 Name        : lbp.c
 Author      : <Your Name Here>
 Version     : 1.0
 Copyright   : MIT
 Description : Find a descriptor from Local Binary Pattern
 ============================================================================
 */

#include "CControl/ccontrol.h"

#define row 20
#define column 20

int main() {
	clock_t start, end;
	float cpu_time_used;
	start = clock();

	/* Create X */
	float X[row * column];

	/* Random */
	randn(X, row * column, 0, 1);

	/* Local binary pattern */
	uint64_t descriptor = lbp(X, row, column, 0.0f, 3, LBP_BIT_16);

	/* Print descriptor */
	size_t i;
	printf("0b");
	for (i = 0; i < 16; i++) {
		printf("%i", 0b1 & (descriptor >> i));
	}
	printf("\n");

	end = clock();
	cpu_time_used = ((float)(end - start)) / CLOCKS_PER_SEC;
	printf("\nTotal speed  was %f\n", cpu_time_used);
	return EXIT_SUCCESS;
}