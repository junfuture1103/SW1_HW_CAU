#include <stdio.h>

int main() {
	int score[4] = { 0, };
	int max = 0;
	int min = 0;

	for (int i = 0; i < 4; i++) {
		if (!scanf("%d", &score[i]) || score[i] > 100) exit(1);
	}

	max = score[0];
	//ÃÖ´ñ°ª
	for (int k = 0; k < 4; k++) {
		if (max < score[k]) {
			max = score[k];
		}
	}

	min = score[0];
	//ÃÖ¼Ú°ª
	for (int l = 0; l < 4; l++) {
		if (min > score[l]) {
			min = score[l];
		}
	}

	printf("input : %d %d %d %d max : %d min : %d", score[0], score[1], score[2], score[3], max, min);

	return 0;
}