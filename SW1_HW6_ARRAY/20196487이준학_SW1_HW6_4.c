#include <stdio.h>
#define STU_NUM 5
#define TEST_NUM 5
#define SUB_NUM 2
#define KOR 0
#define MATH 1

int main() {
	char tmp;
	char sign[5] = { 'A','B', 'C', 'D', 'F' };
	
	char name[STU_NUM] = { 0, };
	int score[STU_NUM] = { 0, };
	char grade[TEST_NUM] = { 0, };

	char result_grade[SUB_NUM][TEST_NUM] = { 0, };
	int result_score[SUB_NUM][STU_NUM] = { 0, };
	float avg_result[STU_NUM] = { 0, };

	for (int i = 0; i < STU_NUM; i++) {
		printf("학생의 이름을 입력해주세요(알파벳 한 글자) : ");
		if (!scanf(" %c", &name[i])) exit(1);

		//k==0 -> 국어 k ==1 -> 수학
		//k반복 한번당 과목별 최고점수 결정
		for (int k = 0; k < 2; k++) {
			if (k == 0) {
				printf("학생의 국어성적을 입력해주세요(알파벳 한 글자) : ");
			}
			else {
				printf("학생의 수학성적을 입력해주세요(알파벳 한 글자) : ");
			}

			//tmp_index => 등급갯수 세기 위한 배열
			char tmp_index[TEST_NUM] = { 0, };

			for (int j = 0; j < TEST_NUM; j++) {
				if (!getchar()) exit(1); // \n 입력받아 버퍼 비우기
				if (!scanf("%c", &grade[j])) exit(1);

				switch (grade[j]) {
				case 'A':
					tmp_index[0]++;
					break;
				case 'B':
					tmp_index[1]++;
					break;
				case 'C':
					tmp_index[2]++;
					break;
				case 'D':
					tmp_index[3]++;
					break;
				case 'F':
					tmp_index[4]++;
					break;
				default:
					printf("입력이 잘못되었습니다. (성적은 A,B,C,D,F로 입력)");
					exit(1);
				}
			}

			//갯수가 가장 많은 성적 선택
			int max = tmp_index[0];
			int max_index = 0;
			for (int j = 0; j < TEST_NUM; j++) {
				if (max < tmp_index[j]) { // < 을 사용하여 등급갯수가 같을때 상위등급으로 결정 char ASCII값이 작으면 높은 점수
					max = tmp_index[j];
					max_index = j;
				}
			}
			result_grade[k][i] = sign[max_index]; //sign배열에는 {A,B,C,D,E} 가 담겨 있음
		}

		//과목별 최고 점수 결정완료
		printf("\n\n");
		printf("kor : %c", result_grade[KOR][i]);
		printf("math : %c", result_grade[MATH][i]);

		//등급 성적 변환
		for (int k = 0; k < SUB_NUM; k++) {
			switch (result_grade[k][i]) {
			case 'A':
				result_score[k][i] = 95;
				break;
			case 'B':
				result_score[k][i] = 85;
				break;
			case 'C':
				result_score[k][i] = 75;
				break;
			case 'D':
				result_score[k][i] = 65;
				break;
			case 'F':
				result_score[k][i] = 0;
				break;
			default:
				printf("입력이 잘못되었습니다. (성적은 A,B,C,D,F로 입력)");
				exit(1);
			}
		}
		printf("\n\n");
	}

	printf("======= 정렬 전 result_score : =======\n");
	for (int k = 0; k < 2; k++) {
		printf("\n성적 : ");
		for (int i = 0; i < 5; i++) {
			printf("%c:%d ", name[i], result_score[k][i]);
		}
	}

	//순위 결정(국어, 수학, 평균)을 위한 이름 순서 배열 정의 및 초기화
	char name_rank[3][5] = { 0, };
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 5; i++) {
			name_rank[k][i] = name[i];
		}
	}

	//평균 점수 석차를 위한 배열 정의 및 초기화
	for (int i = 0; i < 5; i++) {
		avg_result[i] = ((float)result_score[KOR][i] + result_score[MATH][i]) / 2;
	}

	//정렬
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 4; i++) {
			int least = i;
			for (int j = i + 1; j < 5; j++) {
				if (result_score[k][least] > result_score[k][j]) {
					least = j;
				}
			}
			int temp = result_score[k][least];
			result_score[k][least] = result_score[k][i];
			result_score[k][i] = temp;

			temp = name_rank[k][least];
			name_rank[k][least] = name_rank[k][i];
			name_rank[k][i] = temp;
		}
	}

	for (int i = 0; i < 4; i++) {
		int least = i;
		for (int j = i + 1; j < 5; j++) {
			if (avg_result[least] > avg_result[j]) {
				least = j;
			}
		}
		float temp = avg_result[least];
		avg_result[least] = avg_result[i];
		avg_result[i] = temp;

		char tmp_name = name_rank[2][least];
		name_rank[2][least] = name_rank[2][i];
		name_rank[2][i] = tmp_name;
	}


	printf("\n\n======= 최종 RANK =======\n");
	for (int k = 0; k < 2; k++) {
		if (k == 0) {
			printf("국어 성적 순위 : ");
		}
		else if (k == 1) {
			printf("수학 성적 석차 : ");
		}
		for (int i = 0; i < 5; i++) {
			printf("%d위 %c:%d ", i + 1, name_rank[k][4 - i], result_score[k][4 - i]);
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("\n평균 성적 석차 : %d위 %c:%.2f ", i + 1, name_rank[2][4 - i], avg_result[4 - i]);
	}

	for (int k = 0; k < SUB_NUM; k++) {
		int result = 0;
		for (int i = 0; i < STU_NUM; i++) {
			result += result_score[k][i];
		}

		printf("\n");

		if (k == 0) {
			printf("국어 성적 평균은 %.2f점 입니다.\n", (float)result / STU_NUM);
		}
		else if (k == 1) {
			printf("수학 성적 평균은 %.2f점 입니다.\n", (float)result / STU_NUM);
		}

	}

	return 0;
}