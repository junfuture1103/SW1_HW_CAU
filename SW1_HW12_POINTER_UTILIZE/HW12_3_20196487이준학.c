#include <stdio.h>
#include <string.h>
#define NAME_SIZE 20
#define MJ_SIZE 4
#define GROUP_NUM 4
#define STU_NUM 10

#define IS 0
#define CS 1
#define ECE 2
#define MA 3

void sort(char list[][NAME_SIZE], int index) {
	int min_index;
	char temp[NAME_SIZE];

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (strcmp(list[min_index], list[j]) == 1) {
				min_index = j;
			}
		}
		strcpy(temp, list[i]);
		strcpy(list[i], list[min_index]);
		strcpy(list[min_index], temp);
	}
}

int main()
{
	char major[STU_NUM][MJ_SIZE];

	int index_list[STU_NUM] = { 0,1,2,3,4,5,6,7,8,9 };

	int index[GROUP_NUM] = { 0, };
	int start_index[GROUP_NUM] = { 0, };

	char GROUP[GROUP_NUM][STU_NUM][NAME_SIZE];

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 학과 : ", i + 1);
		if (!scanf("%s", major[i])) exit(1);

		if (strcmp(major[i], "IS") == 0) {
			printf("%d번째 학생 이름 : ", i + 1);
			if (!scanf("%s", GROUP[IS][index[IS]])) exit(1);
			index[IS]++;
		}
		else if (strcmp(major[i], "CS") == 0) {
			printf("%d번째 학생 이름 : ", i + 1);
			if (!scanf("%s", GROUP[CS][index[CS]])) exit(1);
			index[CS]++;
		}
		else if (strcmp(major[i], "ECE") == 0) {
			printf("%d번째 학생 이름 : ", i + 1);
			if (!scanf("%s", GROUP[ECE][index[ECE]])) exit(1);
			index[ECE]++;
		}
		else if (strcmp(major[i], "MA") == 0) {
			printf("%d번째 학생 이름 : ", i + 1);
			if (!scanf("%s", GROUP[MA][index[MA]])) exit(1);
			index[MA]++;
		}
		else {
			exit(1);
		}
	}

	for (int i = 0; i < GROUP_NUM; i++) {
		sort(GROUP[i], index[i]);
	}

	//정렬 후 그룹 별 이름 출력
	printf("\n====== 그룹 별 정렬 후 이름 출력 ======\n\n");
	for (int i = 0; i < GROUP_NUM; i++) {
		printf("%d번째 그룹\n", i);
		for (int j = 0; j < index[i]; j++) {
			printf("%s", GROUP[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	char min[NAME_SIZE];
	char find = 1;
	char result_group[STU_NUM][NAME_SIZE] = { 0, };
	int result_group_mj[STU_NUM] = { 0, };

	for (int j = 0; j < STU_NUM; j++) {
		//초기 min 값 찾기
		for (int i = 0; i < GROUP_NUM; i++) {
			if (start_index[i] < index[i]) {
				strcpy(min, GROUP[i][start_index[i]]);
				result_group_mj[j] = i;
				find = 1;
				break;
			}
		}

		//못찾은 경우는 start_index가 모두 인덱스보다 큰 경우 (새로운 배열 생성이 완료)
		if (!find) {
			break;
		}

		for (int i = 0; i < GROUP_NUM; i++) {
			if (strcmp(min, GROUP[i][start_index[i]]) == 1) {
				strcpy(min, GROUP[i][start_index[i]]);
				result_group_mj[j] = i;
			}
		}
		start_index[result_group_mj[j]]++;
		strcpy(result_group[j], min);
	}

	for (int i = 0; i < STU_NUM; i++) {
		char tmp_mj[MJ_SIZE + 1] = { 0, };
		switch (result_group_mj[i]) {
		case 0:
			strcpy(tmp_mj, "IS");
			break;
		case 1:
			strcpy(tmp_mj, "CS");
			break;
		case 2:
			strcpy(tmp_mj, "ECE");
			break;
		case 3:
			strcpy(tmp_mj, "MA");
			break;
		}

		printf("%s", result_group[i]);
		printf("%s ", tmp_mj);
	}

	return 0;
}