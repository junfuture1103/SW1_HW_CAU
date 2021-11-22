#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NAME_SIZE 10
#define STU_NUM 10

void sort(char list[][NAME_SIZE], int index_list[],  int index) {
	int min_index, temp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (strcmp(list[index_list[min_index]], list[index_list[j]])==1) {
				min_index = j;
			}
		}
		temp = index_list[i];
		index_list[i] = index_list[min_index];
		index_list[min_index] = temp;
	}
}

int recu_search(char find_name[], char list[][NAME_SIZE], int index_list[], int left, int right, int* count) {
	static int index = -1;

	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;

	printf("[%d]번째 순환 %d\n", (*count) + 1, mid);
	(*count)++;

	if (strcmp(list[index_list[mid]], find_name)==0) {
		//mid가 위치
		index = mid;
	}
	else if (strcmp(list[index_list[mid]], find_name) == -1) {
		recu_search(find_name, list, index_list, mid + 1, right, count);
	}
	else if (strcmp(list[index_list[mid]], find_name) == 1) {
		recu_search(find_name, list, index_list, left, mid - 1, count);
	}
	return index;
}

int main()
{
	char name_tmp[NAME_SIZE];
	char name[STU_NUM][NAME_SIZE];
	int score[STU_NUM];
	int index_list[STU_NUM] = {0,1,2,3,4,5,6,7,8,9};

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : ", i + 1);
		if (!scanf("%s", name[i])) exit(1);
		printf("%d번째 학생 점수 : ", i + 1);
		if (!scanf("%d", &score[i])) exit(1);
	}

	sort(name, index_list, STU_NUM);

	printf("\n\n======= 입력 결과 =======\n");

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : %s\n", i + 1, name[index_list[i]]);
		printf("%d번째 학생 점수 : %d\n", i + 1, score[index_list[i]]);
	}

	printf("\n\n찾을 이름 입력해주세요(위의 배열에 없어도 됨) : ");

	if (!scanf("%s", name_tmp)) exit(1);

	int index;
	int count = 0;

	printf("\n\n======= 순환 결과 =======\n");
	index = recu_search(name_tmp, name, index_list, 0, STU_NUM, &count);

	if (index == -1) {
		printf("없음. 비교 횟수 : %d", count);
	}
	else {
		printf("%d에 있음. 비교 횟수 : %d", index, count);
	}

	return 0;
}