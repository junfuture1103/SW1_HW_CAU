#include <stdio.h>
#define STU_NUM 5
#define SUB_NUM 3

#define KOR 0
#define ENG 1
#define MATH 2

void sort(int list[], int stu_num[], char name[], char major[], int index) {
	int min_index, temp, temp2;
	char name_tmp, major_tmp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min_index] < list[j]) {
				min_index = j;
			}
		}
		temp2 = stu_num[i];
		stu_num[i] = stu_num[min_index];
		stu_num[min_index] = temp2;

		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;

		name_tmp = name[i];
		name[i] = name[min_index];
		name[min_index] = name_tmp;

		major_tmp = major[i];
		major[i] = major[min_index];
		major[min_index] = major_tmp;
	}
	return;
}

int main() {
	int score[SUB_NUM][STU_NUM] = { 0, }; // SUB0 : KOR SUB 1: ENG SUB 2: MATH
	int stu_num[SUB_NUM][STU_NUM] = { 0, };
	char name[SUB_NUM][STU_NUM] = { 0, };
	char major[SUB_NUM][STU_NUM] = { 0, };


	for (int i = 0; i < STU_NUM; i++) {
		char tmp_name = '0';
		char tmp_major = '0';
		int tmp_num = 0;

		printf("%d번째 이름 입력 해주세요 : ", i + 1);
		if (!scanf("%c", &tmp_name)) exit(1);
		if (!getchar()) exit(1);

		printf("%d번째 학과 입력 해주세요 : ", i + 1);
		if (!scanf("%c", &tmp_major)) exit(1);
		if (!getchar()) exit(1);

		printf("%d번째 학번 입력 해주세요 : ", i + 1);
		if (!scanf("%d", &tmp_num)) exit(1);
		if (!getchar()) exit(1);

		for (int j = 0; j < SUB_NUM; j++) {
			name[j][i] = tmp_name; // SUB 0 : KOR SUB 1: ENG SUB 2: MATH
			major[j][i] = tmp_major;// SUB 0 : KOR SUB 1: ENG SUB 2: MATH
			stu_num[j][i] = tmp_num;

			printf("%d번째 국영수 성적 입력 해주세요 : ", i + 1);
			if (!scanf("%d", &score[j][i]) || score[j][i] > 100) exit(1);
		}
		if (!getchar()) exit(1);
	}

	for (int i = 0; i < SUB_NUM; i++) {
		sort(score[i], stu_num[i], name[i], major[i], STU_NUM);
	}


	for (int j = 0; j < SUB_NUM; j++) {
		if (j == KOR) {
			printf("\n\n==== [국어] ====\n");
		}
		else if (j == ENG) {
			printf("\n\n==== [영어] ====\n");
		}
		else if (j == MATH) {
			printf("\n\n==== [수학] ====\n");
		}

		int rank = 1;
		int tmp_rank = 0;
		for (int i = 0; i < STU_NUM; i++) {
			tmp_rank = i + 1;
			printf("%d위 : %c 학과 %c 학번 %d %d \n", rank, name[j][i], major[j][i], stu_num[j][i], score[j][i]);
			if ((i + 1 < STU_NUM) && (score[j][i] == score[j][i + 1])) {
				continue;
			}
			else {
				rank = tmp_rank + 1;
			}
		}
	}

	return 0;
}