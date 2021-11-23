#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NAME_SIZE 10
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

int main()
{
	char name[STU_NUM][NAME_SIZE];
	char major[STU_NUM][NAME_SIZE];
	char stu_num[STU_NUM][NAME_SIZE] = { "0", "0", "0", "0", "0", "0", "0", "0", "0", "0" };
	int index_list[STU_NUM] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : ", i + 1);
		if (!scanf("%s", name[i])) exit(1);
		printf("%d번째 학과 이름 : ", i + 1);
		if (!scanf("%s", major[i])) exit(1);
	}

	sort(name, index_list, STU_NUM);

	printf("\n\n======= 입력 결과 =======\n");

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : %s\n", i + 1, name[index_list[i]]);
		printf("%d번째 학과 이름 : %s\n", i + 1, major[index_list[i]]);
	}

	printf("\n\n======= 학번 배정 결과 =======\n");

	char tmp[3];
	int now = 0;
	for (int i = 0; i < STU_NUM; i++) {
		if (i != 0 && strcmp(name[index_list[i - 1]], name[index_list[i]]) == 0) {
			now--;
			for (int j = i; j > i - 2; j--) {
				char majortmp[NAME_SIZE] = { 0, };
				memcpy(majortmp, major[index_list[j]], 2); //in
				strcat(majortmp, stu_num[j]); //in0
				memcpy(stu_num[j], majortmp, strlen(majortmp)); // stu_num 0 -> in0
			}
		}

		sprintf(tmp, "%d", now + 1);
		now++;

		if (now > 9) {
			memcpy(stu_num[i], tmp, strlen(tmp));
			printf("%s\n", stu_num[i]);
			continue;
		}
		strcat(stu_num[i], tmp); // "01"
	}

	for (int i = 0; i < STU_NUM; i++) {
		printf("%s %s \n학번 : %s\n\n", name[index_list[i]], major[index_list[i]], stu_num[i]);
	}

	return 0;
}