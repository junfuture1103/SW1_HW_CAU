#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	char tmp;
	char name[3] = { 0, };
	float score[3] = { 0, };
	int rank[3] = { 0, };
	char grade[5] = { 0, };

	for (int i = 0; i < 3; i++) {
		printf("�л��� �̸��� �Է����ּ���(���ĺ� �� ����) : ");
		if (!scanf(" %c", &name[i])) exit(1);

		for (int j = 0; j < 5; j++) {
			if (!getchar()) exit(1); // \n �Է¹޾� ���� ����
			if (!scanf("%c", &grade[j])) exit(1);
		}

		char min = grade[0];
		char max = grade[0];

		for (int j = 0; j < 5; j++) {
			if (min < grade[j]) { //F�� ASCII ���� ���� ũ���� ������ ���� ����
				min = grade[j];
			}
			if (max > grade[j]) { //A�� ASCII ���� ���� ������ ������ ���� ����
				max = grade[j];
			}
		}

		printf("�ְ� ���� : %c �ּ� ���� : %c\n", max, min);
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
				printf("�Է��� �߸��Ǿ����ϴ�. (������ A,B,C,D,F�� �Է�)");
				exit(1);
			}
		}		
		score[i] /= 2;
		printf("���� : %.2f\n", score[i]);
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
		printf("%d�� : ", i + 1);
		printf("%.2f\n", score[i]);
	}

	return 0;
}