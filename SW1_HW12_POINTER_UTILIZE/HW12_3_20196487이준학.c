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
	char major[STU_NUM][MJ_SIZE]; //전공 입력받기 위한 배열 -> 초기 입력시에 이 배열을 이용해 그룹 구분

	int index_list[STU_NUM] = { 0,1,2,3,4,5,6,7,8,9 }; // 인덱스 배열 (두번이상 SWAP회피.. 구조체 대용)

	int index[GROUP_NUM] = { 0, }; //그룹별 학생 수를 담는 배열
	int start_index[GROUP_NUM] = { 0, }; //merge시에 현재 가리키고있는 가장 작은 값을 나타내기 위함 -> 이 값 == index 인 경우 해당 배열의 값 전부 merge 완료

	char GROUP[GROUP_NUM][STU_NUM][NAME_SIZE]; //3차원 배열 -> 4개학과, 10명의 학생, 20글자 이름

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
	char result_group[STU_NUM][NAME_SIZE] = { 0, }; // 최종적으로 merge하여 만들어진 이름 순 배열
	int result_group_mj[STU_NUM] = { 0, }; // 최종적으로 merge하여 만들어진 이름 순 배열 각 학생들의 전공 배열 -> 0 IS 1 CS 2 ECE 3 MA

	for (int j = 0; j < STU_NUM; j++) {
		//초기 min 값 찾기 -> 이 min 값을 각 학과의 가장 작은 이름과 비교해서 이번에 merge될 값 선택
		for (int i = 0; i < GROUP_NUM; i++) {
			if (start_index[i] < index[i]) {
				strcpy(min, GROUP[i][start_index[i]]);
				result_group_mj[j] = i;
				find = 1;
				break;
			}
		}

		if (!find) {
			break;
		}

		for (int i = 0; i < GROUP_NUM; i++) {
			if (strcmp(min, GROUP[i][start_index[i]]) == 1) {
				strcpy(min, GROUP[i][start_index[i]]);
				result_group_mj[j] = i;
			}
		}

		start_index[result_group_mj[j]]++; //result_group_mj[j]가 그룹을 구분함. 
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