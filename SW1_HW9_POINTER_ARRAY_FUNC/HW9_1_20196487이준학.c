#include <stdio.h>
#define STU_NUM 5
#define SUB_NUM 3


void sort(int list[], float list2[], char name[], int index) {
	int min_index, temp;
	float temp2;
	char name_tmp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (name[min_index] > name[j]) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;

		temp2 = list2[i];
		list2[i] = list2[min_index];
		list2[min_index] = temp2;

		name_tmp = name[i];
		name[i] = name[min_index];
		name[min_index] = name_tmp;
	}
	return;
}

void total_cal(char name[], int score[STU_NUM][SUB_NUM], int result_score[]) {
	for (int i = 0; i < STU_NUM; i++) {
		for (int j = 0; j < SUB_NUM; j++) {
			result_score[i] += score[i][j];
		}
	}
	return;
}

void avg_cal(char name[], int score[STU_NUM][SUB_NUM], float avg_score[]) {
	for (int i = 0; i < STU_NUM; i++) {
		int tmp = 0;
		for (int j = 0; j < SUB_NUM; j++) {
			tmp += score[i][j];
		}
		avg_score[i] = (float)tmp / SUB_NUM;
	}
	return;
}

int main() {
	char name[STU_NUM] = { 0, };
	int score[STU_NUM][SUB_NUM] = { 0, };
	int result_score[STU_NUM] = { 0, };
	float avg_score[STU_NUM] = { 0, };

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 입력 해주세요 : ", i + 1);
		if (!scanf("%c", &name[i])) exit(1);
		for (int j = 0; j < SUB_NUM; j++) {
			if (!scanf("%d", &score[i][j]) || score[i][j] >= 100) exit(1);
		}
		if (!getchar()) exit(1);
	}

	total_cal(name, score, result_score);
	avg_cal(name, score, avg_score);
	sort(result_score, avg_score, name, STU_NUM);

	for (int i = 0; i < STU_NUM; i++) {
		printf("%c의 총점 : %d 평균 : %.2f\n", name[i], result_score[i], avg_score[i]);
	}

	return 0;
}