#include <stdio.h>
#define STU_NUM 5

int mid_cal(int grade[3]) {
	int tmp1 = grade[0];
	int tmp2 = grade[1];
	int tmp3 = grade[2];

	int mid_grade;

	if (tmp1 > tmp2) {
		if (tmp2 > tmp3) {
			mid_grade = tmp2;
		}
		else {
			if (tmp1 > tmp3) {
				mid_grade = tmp3;
			}
			else {
				mid_grade = tmp1;
			}
		}
	}
	else {
		if (tmp1 > tmp3) {
			mid_grade = tmp1;
		}
		else {
			if (tmp2 > tmp3) {
				mid_grade = tmp3;
			}
			else {
				mid_grade = tmp2;
			}
		}
	}

	return mid_grade;
}

float avg_cal(int rank[5]) {
	//정렬
	float result = 0.0;
	for (int i = 0; i < 5; i++) {
		result += rank[i];
	}

	result /= 5;
	return result;
}

int main() {
	char name[5] = { 0, };	
	int grade[3] = { 0, };
	int rank[5] = { 0, };
	int tmp_grade;
	float avg;

	for (int i = 0; i < STU_NUM; i++) {
		printf("학생의 이름을 입력해주세요(알파벳 한 글자) : ");
		if (!scanf(" %c", &name[i])) exit(1);

		for (int j = 0; j < 3; j++) {
			if (!scanf("%d", &grade[j])) exit(1);
		}

		tmp_grade = mid_cal(grade);

		printf("%c의 중간 점수 %d\n", name[i], tmp_grade);
		rank[i] = tmp_grade;
	}

	avg = avg_cal(rank);

	int min_index, temp;
	char name_tmp;

	for (int i = 0; i < 4; i++) {
		min_index = i;
		for (int j = i + 1; j < 5; j++) {
			if (rank[min_index] > rank[j]) {
				min_index = j;
			}
		}
		temp = rank[i];
		rank[i] = rank[min_index];
		rank[min_index] = temp;

		name_tmp = name[i];
		name[i] = name[min_index];
		name[min_index] = name_tmp;
	}

	printf("\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%c : %d ", name[i], rank[i]);
		if (temp != rank[i]) {
			printf("\n");
		}
		temp = rank[i];
	}

	printf("전체 평균 : %.f", avg);


	return 0;
}