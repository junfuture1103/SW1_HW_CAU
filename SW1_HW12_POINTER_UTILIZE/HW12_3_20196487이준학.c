#include <stdio.h>
#include <string.h>
#define NAME_SIZE 20
#define MJ_SIZE 4
#define GROUP_NUM 4
#define STU_NUM 10

void sort(char list[][NAME_SIZE], int index) {
	int min_index, temp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (strcmp(list[min_index], list[j]) == 1) {
				min_index = j;
			}
		}
		temp = i;
		i = min_index;
		min_index = temp;
	}
}

int main()
{
	char major[STU_NUM][MJ_SIZE];

	int index_list[STU_NUM] = { 0,1,2,3,4,5,6,7,8,9 };
	int index[GROUP_NUM] = { 0, };

	char IS_GROUP[STU_NUM][NAME_SIZE];
	char CS_GROUP[STU_NUM][NAME_SIZE];
	char ECE_GROUP[STU_NUM][NAME_SIZE];
	char MA_GROUP[STU_NUM][NAME_SIZE];

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 학과 : ", i + 1);
		if (!scanf("%s", major[i])) exit(1);

		if (strcmp(major[i], "IS") == 0) {
			printf("%d번째 학생 이름 : ", i + 1);
			if (!scanf("%s", IS_GROUP[index[0]])) exit(1);
			index[0]++;
		}
		else if (strcmp(major[i], "CS") == 0) {
			printf("%d번째 학생 이름 : ", i + 1);
			if (!scanf("%s", CS_GROUP[index[1]])) exit(1);
			index[1]++;
		}
		else if (strcmp(major[i], "ECE") == 0) {
			printf("%d번째 학생 이름 : ", i + 1);
			if (!scanf("%s", ECE_GROUP[index[2]])) exit(1);
			index[2]++;
		}
		else if (strcmp(major[i], "MA") == 0) {
			printf("%d번째 학생 이름 : ", i + 1);
			if (!scanf("%s", MA_GROUP[index[3]])) exit(1);
			index[3]++;
		}
		else {
			exit(1);
		}
	}

	sort(IS_GROUP, index[0]);
	sort(CS_GROUP, index[1]);
	sort(ECE_GROUP, index[2]);
	sort(MA_GROUP, index[3]);

	int min_group = 0;

	int IS_index = 0;
	int CS_index = 0;
	int ECE_index = 0;
	int MA_index = 0;

	for (int i = 0; i < STU_NUM; i++) {
		if (strcmp(IS_GROUP[IS_index], min_group) == 0) {
	}

	return 0;
}