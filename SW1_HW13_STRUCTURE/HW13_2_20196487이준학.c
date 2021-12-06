#include <stdio.h>
#define NAME_SIZE 5
#define STU_NUM 5
#define EXAM_NUM 3
#define element student

typedef struct _stu{
	char PF;
	char name[NAME_SIZE];
	int score[EXAM_NUM];
	int total;
	float avg;
}student;


void read_data(student stu[]) {
	for (int i = 0; i < STU_NUM; i++) {
		printf("%d��° �л� �̸� : ", i + 1);
		if (!scanf("%s", stu[i].name)) exit(1);
		printf("���� ���� 3�� : ");
		if (!scanf("%d %d %d", &stu[i].score[0], &stu[i].score[1], &stu[i].score[2])) exit(1);
	}

	return;
}

void calculate(student stu[]) {
	for (int i = 0; i < STU_NUM; i++) {
		stu[i].total = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
		stu[i].avg = (float)stu[i].total / EXAM_NUM;
		if (stu[i].avg >= 60) {
			stu[i].PF = 'T';
		}
		else {
			stu[i].PF = 'F';
		}
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

	read_data(stu);
	calculate(stu);

	printf("\n\n======= �Է� ��� =======\n");
	int pass_index = 0;
	for (int i = 0; i < STU_NUM; i++) {
		printf("�̸� : %s\n", stu[i].name);
		printf("����1/����2/����3 : %d/%d/%d\n", stu[i].score[0], stu[i].score[1], stu[i].score[2]);
		printf("���� : %d ��� : %.2f\n", stu[i].total, stu[i].avg);
		printf("�հ� ���� : %c\n\n", stu[i].PF);
		if (stu[i].PF == 'T') {
			stu_pass[pass_index++] = stu[i];
		}
	}

	printf("\n\n======= �հݻ� ��� =======\n");
	for (int i = 0; i < pass_index; i++) {
		printf("�̸� : %s\n", stu_pass[i].name);
		printf("����1/����2/����3 : %d/%d/%d\n", stu_pass[i].score[0], stu_pass[i].score[1], stu_pass[i].score[2]);
		printf("���� : %d ��� : %.2f\n", stu_pass[i].total, stu_pass[i].avg);
		printf("�հ� ���� : %c\n\n", stu_pass[i].PF);
	}

	ranking(stu_pass, pass_index);

	printf("\n\n======= �հݻ� ���� ���� ��� =======\n");
	for (int i = 0; i < pass_index; i++) {
		printf("�̸� : %s\n", stu_pass[i].name);
		printf("����1/����2/����3 : %d/%d/%d\n", stu_pass[i].score[0], stu_pass[i].score[1], stu_pass[i].score[2]);
		printf("���� : %d ��� : %.2f\n", stu_pass[i].total, stu_pass[i].avg);
		printf("�հ� ���� : %c\n\n", stu_pass[i].PF);
	}
	return 0;
}