#include <stdio.h>

int main() {
	int score[3] = { 0, };
	int A[3] = { 0, };
	int B[3] = { 0, };

	int A_index = 0;
	int B_index = 0;

	int max = 0;
	int min = 0;

	for (int i = 0; i < 3; i++) {
		if (!scanf("%d", &score[i]) || score[i] > 100) exit(1);
	}

	//그룹 분류
	for (int k = 0; k < 3; k++) {
		if (score[k] < 50 && score[k] % 2 == 1) {
			A[A_index] = score[k];
			A_index += 1;
		}
		else {
			B[B_index] = score[k];
			B_index += 1;
		}
	}

	if (A_index > B_index) {
		printf("%c : ", 'A');
		for (int l = 0; l < A_index; l++) {
			printf("%d ", A[l]);
		}
	}
	else {
		printf("%c : ", 'B');
		for (int l = 0; l < B_index; l++) {
			printf("%d ", B[l]);
		}
	}

	return 0;
}