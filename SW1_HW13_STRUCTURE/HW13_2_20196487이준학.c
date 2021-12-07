#include <stdio.h>
#define NAME_SIZE 5
#define STU_NUM 5
#define EXAM_NUM 3
#define element student

typedef struct _stu {
	char PF;
	char name[NAME_SIZE];
	int score[EXAM_NUM];
	int total;
	float avg;
}student;


void read_data(student* stu) {
	printf("학생 이름 : ");
	if (!scanf("%s", stu->name)) exit(1);
	printf("시험 점수 3번 : ");
	if (!scanf("%d %d %d", &stu->score[0], &stu->score[1], &stu->score[2])) exit(1);
	return;
}

void calculate(student* stu) {
	stu->total = stu->score[0] + stu->score[1] + stu->score[2];
	stu->avg = (float)stu->total / EXAM_NUM;
	if (stu->avg >= 60) {
		stu->PF = 'T';
	}
	else {
		stu->PF = 'F';
	}
	return;
}

void ranking(element list[], int index) {
	int min_index;
	element temp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min_index].total < list[j].total) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;
	}
}

int main()
{
	student stu[STU_NUM];
	student stu_pass[STU_NUM];

	for (int i = 0; i < STU_NUM; i++) {
		read_data(&stu[i]);
	}
	for (int i = 0; i < STU_NUM; i++) {
		calculate(&stu[i]);
	}

	printf("\n\n======= 입력 결과 =======\n");
	int pass_index = 0;
	for (int i = 0; i < STU_NUM; i++) {
		printf("이름 : %s\n", stu[i].name);
		printf("시험1/시험2/시험3 : %d/%d/%d\n", stu[i].score[0], stu[i].score[1], stu[i].score[2]);
		printf("총점 : %d 평균 : %.2f\n", stu[i].total, stu[i].avg);
		printf("합격 여부 : %c\n\n", stu[i].PF);
		if (stu[i].PF == 'T') {
			stu_pass[pass_index++] = stu[i];
		}
	}

	printf("\n\n======= 합격생 결과 =======\n");
	for (int i = 0; i < pass_index; i++) {
		printf("이름 : %s\n", stu_pass[i].name);
		printf("시험1/시험2/시험3 : %d/%d/%d\n", stu_pass[i].score[0], stu_pass[i].score[1], stu_pass[i].score[2]);
		printf("총점 : %d 평균 : %.2f\n", stu_pass[i].total, stu_pass[i].avg);
		printf("합격 여부 : %c\n\n", stu_pass[i].PF);
	}

	ranking(stu_pass, pass_index);

	printf("\n\n======= 합격생 순위 결정 결과 =======\n");
	for (int i = 0; i < pass_index; i++) {
		printf("이름 : %s\n", stu_pass[i].name);
		printf("시험1/시험2/시험3 : %d/%d/%d\n", stu_pass[i].score[0], stu_pass[i].score[1], stu_pass[i].score[2]);
		printf("총점 : %d 평균 : %.2f\n", stu_pass[i].total, stu_pass[i].avg);
		printf("합격 여부 : %c\n\n", stu_pass[i].PF);
	}
	return 0;
}