#include <stdio.h>

int main() {
	int score1, score2, score3;
	float avg_score = .0;
	char tmp;
	char tmp1, tmp2, tmp3;
	char mid_grade;
	char grade1, grade2, grade3, grade4, grade5;

	for (int i = 0; i < 5; i++) {
		printf("========== %d번째 학생입니다. ==========\n", i + 1);
		if (!scanf("%d", &score1) && score1 > 100) exit(1);
		if (!scanf("%d", &score2) && score2 > 100) exit(1);
		if (!scanf("%d", &score3) && score3 > 100) exit(1);

		if (score1 >= 90) {
			tmp1 = 'A';
		}
		else if (score1 >= 80) {
			tmp1 = 'B';
		}
		else if (score1 >= 70) {
			tmp1 = 'C';
		}
		else if (score1 >= 60) {
			tmp1 = 'D';
		}
		else {
			tmp1 = 'F';
		}

		if (score2 >= 90) {
			tmp2 = 'A';
		}
		else if (score2 >= 80) {
			tmp2 = 'B';
		}
		else if (score2 >= 70) {
			tmp2 = 'C';
		}
		else if (score2 >= 60) {
			tmp2 = 'D';
		}
		else {
			tmp2 = 'F';
		}

		if (score3 >= 90) {
			tmp3 = 'A';
		}
		else if (score3 >= 80) {
			tmp3 = 'B';
		}
		else if (score3 >= 70) {
			tmp3 = 'C';
		}
		else if (score3 >= 60) {
			tmp3 = 'D';
		}
		else {
			tmp3 = 'F';
		}

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

		printf("%d번째 학생 최종 학점 : %c\n\n", i + 1, mid_grade);

		switch (i) {
		case 0:
			grade1 = mid_grade;
			break;
		case 1:
			grade2 = mid_grade;
			break;
		case 2:
			grade3 = mid_grade;
			break;
		case 3:
			grade4 = mid_grade;
			break;
		case 4:
			grade5 = mid_grade;
			break;
		}
	}

	for (int j = 0; j < 5; j++) {

		switch (j) {
		case 0:
			tmp = grade1;
			break;
		case 1:
			tmp = grade2;
			break;
		case 2:
			tmp = grade3;
			break;
		case 3:
			tmp = grade4;
			break;
		case 4:
			tmp = grade5;
			break;
		}

		switch (tmp) {
		case 'A':
			avg_score += 4.5;
			break;
		case 'B':
			avg_score += 3.5;
			break;
		case 'C':
			avg_score += 2.5;
			break;
		case 'D':
			avg_score += 1.5;
			break;
		case 'F':
			avg_score += 0;
			break;
		}
	}



	printf("\n");
	printf("=================== 최종 결과 =================== \n\n");
	for (int k = 0; k < 5; k++) {
		switch (k) {
		case 0:
			tmp = grade1;
			break;
		case 1:
			tmp = grade2;
			break;
		case 2:
			tmp = grade3;
			break;
		case 3:
			tmp = grade4;
			break;
		case 4:
			tmp = grade5;
			break;
		}
		printf("%d번째 학생의 최종학점 : %c\n", k + 1, tmp);
	}
	printf("\n");

	printf("전체 학생의 평균 평점은 %.2f점 입니다.", avg_score / 5);

	return 0;
}