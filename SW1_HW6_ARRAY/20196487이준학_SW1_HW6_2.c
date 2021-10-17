#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	char tmp;
	char name[3] = { 0, };
	float score[3] = { 0, };
	int rank[3] = { 0, };
	char grade[5] = { 0, };

	for (int i = 0; i < 3; i++) {
		printf("학생의 이름을 입력해주세요(알파벳 한 글자) : ");
		if (!scanf(" %c", &name[i])) exit(1);

		for (int j = 0; j < 5; j++) {
			if (!getchar()) exit(1); // \n 입력받아 버퍼 비우기
			if (!scanf("%c", &grade[j])) exit(1);
		}

		char min = grade[0];
		char max = grade[0];

		for (int j = 0; j < 5; j++) {
			if (min < grade[j]) { //F가 ASCII 값이 제일 크지만 학점은 제일 낮음
				min = grade[j];
			}
			if (max > grade[j]) { //A가 ASCII 값이 제일 작지만 학점은 제일 높음
				max = grade[j];
			}
		}

		printf("최고 학점 : %c 최소 학점 : %c\n", max, min);
		char tmp[2] = { max, min };

		for (int k = 0; k < 2; k++) {
			switch (tmp[k]) {
			case 'A':
				score[i] += 4.5;
				break;
			case 'B':
				score[i] += 3.5;
				break;
			case 'C':
				score[i] += 2.5;
				break;
			case 'D':
				score[i] += 1.5;
				break;
			case 'F':
				score[i] += 0;
				break;
			defalut:
				printf("입력이 잘못되었습니다. (성적은 A,B,C,D,F로 입력)");
				exit(1);
			}
		}		
		score[i] /= 2;
		printf("성적 : %.2f\n", score[i]);
	}

	int least;
	float temp;

	for (int i = 0; i < 2; i++) {
		least = i;
		for (int j = i+1; j < 3; j++) {
			if (score[least] > score[j]) {
				least = j;
			}
		}
		temp = score[i];
		score[i] = score[least];
		score[least] = temp;
	}

	for (int i = 0; i < 3; i++) {
		printf("%d위 : ", i + 1);
		printf("%.2f\n", score[i]);
	}

	return 0;
}