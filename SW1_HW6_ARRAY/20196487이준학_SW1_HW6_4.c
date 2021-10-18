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
	int rank[STU_NUM] = { 0, };
	char grade[TEST_NUM] = { 0, };
	char result_grade[SUB_NUM][TEST_NUM] = { 0, };
	int result_score[SUB_NUM][STU_NUM] = { 0, };

	for (int i = 0; i < STU_NUM; i++) {
		printf("�л��� �̸��� �Է����ּ���(���ĺ� �� ����) : ");
		if (!scanf(" %c", &name[i])) exit(1);

		//k==0 -> ���� k ==1 -> ����
		//k�ݺ� �ѹ��� ���� �ְ����� ����
		for (int k = 0; k < 2; k++) {
			if (k == 0) {
				printf("�л��� ������� �Է����ּ���(���ĺ� �� ����) : ");
			}
			else {
				printf("�л��� ���м����� �Է����ּ���(���ĺ� �� ����) : ");
			}

			//tmp_index => ��ް��� ���� ���� �迭
			char tmp_index[TEST_NUM] = { 0, };

			for (int j = 0; j < TEST_NUM; j++) {
				if (!getchar()) exit(1); // \n �Է¹޾� ���� ����
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
					printf("�Է��� �߸��Ǿ����ϴ�. (������ A,B,C,D,F�� �Է�)");
					exit(1);
				}
			}

			//������ ���� ���� ���� ����
			int max = tmp_index[0];
			int max_index = 0;
			for (int j = 0; j < TEST_NUM; j++) {
				if (max <= tmp_index[j]) { // <=�� ����Ͽ� ��ް����� ������ ����������� ���� 
					max = tmp_index[j];
					max_index = j;
				}
			}
			result_grade[k][i] = sign[max_index]; //sign�迭���� {A,B,C,D,E} �� ��� ����
		}

		//���� �ְ� ���� �����Ϸ�
		printf("\n\n");
		printf("kor : %c", result_grade[KOR][i]);
		printf("math : %c", result_grade[MATH][i]);

		//��� ���� ��ȯ
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
				printf("�Է��� �߸��Ǿ����ϴ�. (������ A,B,C,D,F�� �Է�)");
				exit(1);
			}
		}
	}

	printf("result_score : ");
	for (int k = 0; k < 2; k++) {
		printf("\n���� : ");
		for (int i = 0; i < 5; i++) {
			printf("%c:%d ", name[i], result_score[k][i]);
		}
	}

	//����

	return 0;
}