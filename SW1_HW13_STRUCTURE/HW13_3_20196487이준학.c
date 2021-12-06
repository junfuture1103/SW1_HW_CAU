#include <stdio.h>
#include <string.h>

#define NAME_SIZE 5
#define STU_NUM 10
#define MJ_SIZE 3
#define STUID_SIZE 4
#define element student

typedef struct _stu {
	char PF;
	char name[NAME_SIZE];
	char major[MJ_SIZE];
	char stuid[STUID_SIZE];
	int score;
}student;

void sort(element list[], int index) {
	int min_index;
	element temp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (strcmp(list[min_index].stuid, list[j].stuid)==1) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;
	}
	return;
}

void read_data(student stu[], student stu_pass[], int* pass_index) {
	for (int i = 0; i < STU_NUM; i++) {
		printf("%d번째 학생 이름 : ", i + 1);
		if (!scanf("%s", stu[i].name)) exit(1);		
		printf("지원 전공 명 : ");
		if (!scanf("%s", stu[i].major)) exit(1);
		printf("점수 : ");
		if (!scanf("%d", &stu[i].score)) exit(1);

		if (stu[i].score >= 60) {
			stu[i].PF = 'T';
			stu[i].stuid[0] = stu[i].major[0];
			stu[i].stuid[1] = stu[i].major[1];
			stu[i].stuid[2] = stu[i].name[0];
			stu[i].stuid[3] = '\0';
			stu_pass[(*pass_index)++] = stu[i];
		}
		else {
			stu[i].PF = 'F';
		}
	}
	return;
}

int find_many_mj(student stu[], char temp[][MJ_SIZE], int pass_index, int mj_count[]) {
	int temp_index=0;
	int duplicate = 0;

	//make test_set
	for (int i = 0; i < pass_index; i++) {
		if (i == 0) {
			strncpy(temp[temp_index], stu[temp_index].major, sizeof(stu[temp_index].major));
			temp_index++;
			continue;
		}

		for (int j = 0; j < temp_index; j++) {
			if (strcmp(stu[i].major, temp[j]) == 0) {
				duplicate = 1;
				break;
			}
		}

		if (duplicate) {
			duplicate = 0;
			continue;
		}
		else {
			strncpy(temp[temp_index], stu[i].major, sizeof(stu[i].major));
			temp_index++;
		}
	}

	//make count
	for (int i = 0; i < temp_index; i++) {
		for (int j = 0; j < pass_index; j++) {
			if (strcmp(temp[i], stu[j].major) == 0) {
				mj_count[i]++;
			}
		}
	}

	return temp_index;
}

int main() {
	student stu[STU_NUM];
	student stu_pass[STU_NUM];
	int mj_count[STU_NUM] = { 0, };

	int pass_index = 0;
	read_data(stu, stu_pass, &pass_index);

	for (int i = 0; i < pass_index; i++) {
		printf("[%d] %s %s %s %d\n", i+1, stu_pass[i].stuid, stu_pass[i].name, stu_pass[i].major, stu_pass[i].score);
	}
	sort(stu_pass, pass_index);
	printf("\n======== sorting완료 ========\n\n");
	for (int i = 0; i < pass_index; i++) {
		printf("[%d] %s %s %s %d\n", i + 1, stu_pass[i].stuid, stu_pass[i].name, stu_pass[i].major, stu_pass[i].score);
	}

	char temp[STU_NUM][MJ_SIZE];
	int temp_index = find_many_mj(stu_pass, temp, pass_index, mj_count);

	printf("\n======== 전공명과 합격자수 출력 ========\n\n");
	for (int i = 0; i < temp_index; i++) {
		if (mj_count[i] > 1) {
			printf("%s:%d ", temp[i], mj_count[i]);
		}
	}

	return 0;
}