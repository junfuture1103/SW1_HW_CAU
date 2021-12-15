#include <stdio.h>
#include <string.h>

#define WORD_SIZE 5
#define SUB_NUM 5
#define STU_NUM 10

typedef struct _student {
	char name[WORD_SIZE];
	char sub[WORD_SIZE];
	int score[5][3];
	int total;
}stu_set;

typedef struct _result {
	char sub[WORD_SIZE];
	int stu_count;
	float avg;
	stu_set king;
}result_set;

//���� �̸����� ����, ���ϰ���� ���������� ����
void sort(stu_set stu[], int left, int right) {
	int min_index;
	stu_set temp;

	for (int i = left; i < right - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < right; j++) {
			if (strcmp(stu[min_index].sub, stu[j].sub) == 1) {
				min_index = j;
			}
			else if (strcmp(stu[min_index].sub, stu[j].sub) == 0) {
				if (stu[min_index].total > stu[j].total) {
					min_index = j;
				}
			}
		}
		temp = stu[i];
		stu[i] = stu[min_index];
		stu[min_index] = temp;
	}

	return;
};

void avg_sort(result_set stu[], int left, int right) {
	int min_index;
	result_set temp;

	for (int i = left; i < right - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < right; j++) {
			if (stu[min_index].avg > stu[j].avg) {
				min_index = j;
			}
			else if (stu[min_index].avg == stu[j].avg) {
				if (strcmp(stu[min_index].sub, stu[j].sub) == 1) {
					min_index = j;
				}
			}
		}
		temp = stu[i];
		stu[i] = stu[min_index];
		stu[min_index] = temp;
	}

	return;
}

void total_sort(result_set stu[], int left, int right) {
	int min_index;
	result_set temp;

	for (int i = left; i < right - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < right; j++) {
			if (stu[min_index].king.total > stu[j].king.total) {
				min_index = j;
			}
			else if (stu[min_index].king.total == stu[j].king.total) {
				if (strcmp(stu[min_index].sub, stu[j].sub) == 1) {
					min_index = j;
				}
			}
		}
		temp = stu[i];
		stu[i] = stu[min_index];
		stu[min_index] = temp;
	}

	return;
}

//sub_stu[][] => ����� / �л� ��
void classify_sub(stu_set stu[], stu_set sub_stu[][STU_NUM], int* sub_count, int sub_index[]) {
	for (int i = 0; i < STU_NUM; i++) {
		//�ƹ� ���� ���� ������ - ó���̸�
		if (*sub_count == 0) {
			//0��° ���� 0��° �л��� ���� �л� �߰��ϰ� ���񰹼� ����� �л����� +1
			sub_stu[*sub_count][sub_index[0]] = stu[i];
			(*sub_count)++;
			sub_index[0]++;
			continue;
		}
		for (int j = 0; j < *sub_count; j++) {
			//������ �̹� �ִ°��
			if (strcmp(stu[i].sub, sub_stu[j][0].sub) == 0) {
				sub_stu[j][sub_index[j]++] = stu[i];
				break;
			}
			//������ ���� ���
			if (j == (*sub_count) - 1) {
				sub_stu[*sub_count][sub_index[*sub_count]] = stu[i];
				sub_index[(*sub_count)++]++;
				break;
			}
		}
	}
	return;
}

float get_avg(stu_set stu[], int index) {
	float result = .0;
	for (int i = 0; i < index; i++) {
		result += (float)stu[i].total;
	}
	return (result / index);
}

void get_subinfo(result_set result[], stu_set sub_stu[][STU_NUM], int sub_count, int sub_index[]) {
	//����� result ����ü �ϳ���
	for (int i = 0; i < sub_count; i++) {
		strncpy(result[i].sub, sub_stu[i][0].sub, sizeof(sub_stu[i][0].sub));
		result[i].stu_count = sub_index[i];
		result[i].avg = get_avg(sub_stu[i], sub_index[i]);
		//�̹� �������� ������ ���ĵǾ��ֱ� ������ ���� ������ �ε����� �а� ����
		result[i].king = sub_stu[i][sub_index[i] - 1];
	}

	return;
}

int main() {
	stu_set stu[STU_NUM] = { 0, };
	//���� �л� ���� ��� �迭
	stu_set sub_stu[SUB_NUM][STU_NUM] = { 0, };

	for (int i = 0; i < STU_NUM; i++) {
		stu[i].total = 0;
		if (!scanf("%s %s", stu[i].name, stu[i].sub)) exit(1);
		for (int j = 0; j < SUB_NUM; j++) {
			if (!scanf("%d %d %d", &stu[i].score[j][0], &stu[i].score[j][1], &stu[i].score[j][2])) exit(1);
			for (int k = 0; k < 3; k++) {
				stu[i].total += stu[i].score[j][k];
			}
		}
	}

	/* for test - �Է� �Ϸ�*/
	/*
	printf("\n\n =========== for print test =========== \n\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%s %s\n", stu[i].name, stu[i].sub);
		printf("%d ", stu[i].total);
		for (int j = 0; j < SUB_NUM; j++) {
			for (int k = 0; k < 3; k++) {
				printf("%d ", stu[i].score[j][k]);
			}
			printf("\n");
		}
	}
	*/

	sort(stu, 0, STU_NUM);

	/* for test - �а��� �� ���� �Ϸ� - 1��*/
	printf("\n\n =========== �а��� �� ���� �Ϸ� - 1�� =========== \n\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%s %s ", stu[i].name, stu[i].sub);
		printf("%d\n", stu[i].total);
		for (int j = 0; j < SUB_NUM; j++) {
			for (int k = 0; k < 3; k++) {
				printf("%d ", stu[i].score[j][k]);
			}
			printf("\n");
		}
	}

	int sub_count = 0; // ���� �?
	int sub_index[10] = { 0, }; // ����� �л��� ���?

	classify_sub(stu, sub_stu, &sub_count, sub_index);

	/* for test - �а��� �з� �Ϸ� - 2�� (�̹� ���ĵǾ� �ִ� �迭 �̿��Ͽ� �з�)*/
	printf("\n\n =========== �а��� �з� �Ϸ� - 2�� (�̹� ���ĵǾ� �ִ� �迭 �̿��Ͽ� �з�) =========== \n\n");
	//for test classify_sub
	for (int i = 0; i < sub_count; i++) {
		printf("<%s>\n", sub_stu[i][0].sub);
		for (int j = 0; j < sub_index[i]; j++) {
			printf("%s %s %d\n", sub_stu[i][j].name, sub_stu[i][j].sub, sub_stu[i][j].total);
			for (int l = 0; l < SUB_NUM; l++) {
				for (int k = 0; k < 3; k++) {
					printf("%d ", sub_stu[i][j].score[l][k]);
				}
				printf("\n");
			}
		}
		printf("\n");
	}

	/* for test - �а��� ������ ���� ����ü ��� - 3��*/
	result_set result[STU_NUM] = { 0, };
	get_subinfo(result, sub_stu, sub_count, sub_index);

	printf("\n\n =========== �а��� ������ ���� ����ü ��� �� ��� �� ���� - 3�� =========== \n\n");
	//for test get_subinfo
	avg_sort(result, 0, sub_count);
	for (int i = 0; i < sub_count; i++) {
		printf("%s %d %.2f\n", result[i].sub, result[i].stu_count, result[i].avg);
	}

	printf("\n\n =========== �а� ���� ������ �߰��� �� �а��� ���� ���� �������� ��� - 4�� =========== \n\n");
	total_sort(result, 0, sub_count);
	for (int i = 0; i < sub_count; i++) {
		printf("%s %.2f %s %d\n", result[i].sub, result[i].avg, result[i].king.name, result[i].king.total);
	}
	return 0;
}