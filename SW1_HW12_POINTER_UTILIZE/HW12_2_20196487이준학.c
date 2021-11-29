#include <stdio.h>
#include <string.h>
#define NAME_SIZE 20
#define STU_NUM 10

void sort(char list[][NAME_SIZE], int index_list[], int index) {
	int min_index, temp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (strcmp(list[index_list[min_index]], list[index_list[j]]) == 1) {
				min_index = j;
			}
		}
		temp = index_list[i];
		index_list[i] = index_list[min_index];
		index_list[min_index] = temp;
	}
}

void tmp_sort(char list[][NAME_SIZE], int index_list[], int left, int right) {
	int min_index, temp;

	for (int i = left; i < right - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < right; j++) {
			if (strcmp(list[index_list[min_index]], list[index_list[j]]) == 1) {
				min_index = j;
			}
		}
		temp = index_list[i];
		index_list[i] = index_list[min_index];
		index_list[min_index] = temp;
	}
}

//학과별로 이름이 서로다른 학생의 수 계산
void decision_num(char list[][NAME_SIZE], int index_list[], int diff_name[], int diff_result[], int diff_index) {
	int left = 0;
	int tmp = 1;
	for (int i = 0; i < diff_index + 1; i++) {
		int min = left;
		int right;
		tmp = 1;

		if (i == diff_index) right = STU_NUM;
		else right = diff_name[i];

		for (int j = left; j < right; j++) {
			if (strcmp(list[index_list[min]], list[index_list[j]]) != 0) {
				tmp++;
				min = j;
			}
		}
		left = diff_name[i];
		diff_result[i] = tmp;
	}
	return;
}

//이름 별로 같은 이름 개수 구하기
void decision_name(char list[][NAME_SIZE], int index_list[], int diff_name[], int diff_result[], int* index) {
	sort(list, index_list, STU_NUM);

	int min = 0;
	int tmp = 0;
	for (int j = 0; j < STU_NUM; j++) {
		if (strcmp(list[index_list[min]], list[index_list[j]]) != 0) {
			min = j;
			diff_name[*index] = j;
			diff_result[(*index)++] = tmp;
			tmp = 1;
		}
		else {
			tmp++;
		}
	}
	diff_result[(*index)++] = tmp;
	return;
}

int main()
{
	char name[STU_NUM][NAME_SIZE];
	char major[STU_NUM][NAME_SIZE];
	int index_list[STU_NUM] = { 0,1,2,3,4,5,6,7,8,9 };
	int diff_name[STU_NUM];
	int diff_result[STU_NUM];
	int same_name[STU_NUM];
	int same_result[STU_NUM];

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : ", i + 1);
		if (!scanf("%s", name[i])) exit(1);
		printf("%d번째 학생 학과 : ", i + 1);
		if (!scanf("%s", major[i])) exit(1);
	}

	sort(major, index_list, STU_NUM);

	int now = 0;
	int diff_index = 0;

	//diff_index에는 학과명이 달라지는 인덱스가 담김
	for (int i = 1; i < STU_NUM; i++) {
		if (strcmp(major[index_list[now]], major[index_list[i]]) != 0) {
			tmp_sort(name, index_list, now, i);
			now = i;
			diff_name[diff_index] = now;
			diff_index++;
		}
	}

	printf("\n\n======= 1. 학과별 학과명 소속학생 이름 =======\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : %s\n", i + 1, name[index_list[i]]);
		printf("%d번째 학생 학과 : %s\n", i + 1, major[index_list[i]]);
	}

	decision_num(name, index_list, diff_name, diff_result, diff_index);

	printf("\n\n======= 2. 학과별 서로 다른 학생의 수 =======\n");
	for (int i = 0; i < diff_index + 1; i++) {
		if (i == 0) printf("%s : ", major[index_list[0]]); else printf("%s : ", major[index_list[diff_name[i - 1]]]);
		printf("%d ", diff_result[i]);
	}

	int same_index = 0;
	decision_name(name, index_list, same_name, same_result, &same_index);

	printf("\n\n======= 3. 이름별 학생 이름과 해당 이름 수 =======\n");
	for (int i = 0; i < same_index; i++) {
		if (i == 0) printf("%s : ", name[index_list[0]]); else printf("%s : ", name[index_list[same_name[i - 1]]]);
		printf("%d ", same_result[i]);
	}

	return 0;
}