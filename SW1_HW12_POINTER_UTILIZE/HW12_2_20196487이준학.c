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

	for (int i = left; i < right-1; i++) {
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

void decision_num(char list[][NAME_SIZE], int index_list[], int diff_name[], int diff_index) {
	int left = 0;
	int tmp = 1;
	for (int i = 0; i < diff_index; i++) {
		int min = left;
		for (int j = left; j < diff_name[i]; j++) {
			tmp = 0;
			if (strcmp(list[index_list[min]], list[index_list[j]]) != 0) {
				tmp++;
				min = j;
			}
		}
		left = diff_name[i];
		diff_name[i] = tmp;
	}
}

int main()
{
	char name[STU_NUM][NAME_SIZE];
	char major[STU_NUM][NAME_SIZE];
	int index_list[STU_NUM] = { 0,1,2,3,4,5,6,7,8,9};
	int diff_name[STU_NUM];

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : ", i + 1);
		if (!scanf("%s", name[i])) exit(1);
		printf("%d번째 학생 학과 : ", i + 1);
		if (!scanf("%s", major[i])) exit(1);
	}

	sort(major, index_list, STU_NUM);

	int now = 0;
	int diff_index = 0;

	for (int i = 1; i < STU_NUM; i++) {
		if (strcmp(major[index_list[now]], major[index_list[i]]) != 0) {
			tmp_sort(name, index_list, now, i);
			now = i;
			diff_name[diff_index] = now;
			diff_index++;
		}
	}

	printf("\n\n======= 입력 결과 =======\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : %s\n", i + 1, name[index_list[i]]);
		printf("%d번째 학생 학과 : %s\n", i + 1, major[index_list[i]]);
	}

	decision_num(name, index_list, diff_name, diff_index);
	for (int i = 0; i < diff_index; i++) {
		printf("%d ", diff_name[i]);
	}


	return 0;
}