#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int tmp = 0;
	int matrix_A[3][4] = { 0, };
	int matrix_B[3][4] = { 0, };
	int matrix_C[3][4] = { 0, }; //for ADD result
	int matrix_D[4][3] = { 0, };
	int matrix_E[3][3] = { 0, }; // for Multiply result

	//create matrix A, B, D
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			matrix_A[i][j] = rand() % 11;
			matrix_B[i][j] = rand() % 11;
			matrix_D[j][i] = rand() % 11;
		}
	}

	//ADD matrix A + B
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
		}
	}
	printf("==== matrix A ====\n");
	//print matrix A
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d ", matrix_A[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
	printf("==== matrix B ====\n");

	//print matrix B
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d ", matrix_B[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
	printf("==== matrix C (A+B) ====\n");

	//print matrix C = A+B
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d ", matrix_C[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
	printf("==== matrix D ====\n");
	//print matrix D
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%2d ", matrix_D[i][j]);
		}
		printf("\n");
	}

	//Multiply matrix C * D
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				matrix_E[j][i] += matrix_D[k][i] * matrix_C[j][k];
			}
		}
	}

	printf("\n\n");
	printf("==== matrix C*D ====\n");
	//print matrix E = C*D
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%2d ", matrix_E[i][j]);
		}
		printf("\n");
	}

	return 0;
}