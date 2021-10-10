#include <stdio.h>

int main() {
	int score;
	char tmp, tmp_a;
	char tmp_result = '\0';
	char a, b, c, d, e;
	char score_arr[5];

	for (int i = 0; i < 5; i++) {
		printf("========= %d¹ø ÇÐ»ý =========\n", i + 1);

		for (int j = 0; j < 3; j++) {
			if (!scanf("%d", &score) && score > 100) exit(1);

			if (score >= 90) {
				tmp = 'A';
			}
			else if (score >= 80) {
				tmp = 'B';
			}
			else if (score >= 70) {
				tmp = 'C';
			}
			else if (score >= 60) {
				tmp = 'D';
			}
			else {
				tmp = 'F';
			}

			if (tmp_result == '\0') {
				tmp_result = tmp;
				tmp_a = tmp;
				continue;
			}
			if (tmp_result < tmp && j==1) {
				tmp_result = tmp;
			}
			else if (tmp_result > tmp && tmp > tmp_a && j == 2) {
				tmp_result = tmp;
			}
		}

		score_arr[i] = tmp_result;
	}

	for (int k = 0; k < 5; k++) {
		printf("%c", score_arr[k]);
	}

	return 0;
}