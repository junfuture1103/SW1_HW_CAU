#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int A_index = 0;
	int B_index = 0;
	int C_index = 0;
	int D_index = 0;

	int max = 0, min = 0;
	char max_c = '\0', min_c = '\0';

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 100 + 1;
		printf("========== 생성된 자연수 : %d ==========\n", random);

		if (random < 50 && random % 2 != 0) {
			A_index++;
		}
		else if (random >= 50 && random % 2 != 0) {
			B_index++;
		}
		else if (random < 50 && random % 2 == 0) {
			C_index++;
		}
		else if (random >= 50 && random % 2 == 0) {
			D_index++;
		}
		else {
			printf("뭔가 잘못 됨");
			exit(1);
		}
	}

	max = A_index;
	min = A_index;
	max_c = 'A';
	min_c = 'A';

	if (max < B_index) {
		max = B_index;
		max_c = 'B';
	}
	if (max < C_index) {
		max = C_index;
		max_c = 'C';
	}
	if (max < D_index) {
		max = D_index;
		max_c = 'D';
	}

	if (min > B_index) {
		min = B_index;
		min_c = 'B';
	}
	if (min > C_index) {
		min = C_index;
		min_c = 'C';
	}
	if (min > D_index) {
		min = D_index;
		min_c = 'D';
	}

	printf("\n");
	printf("MAX Group : %c \nNUM of Members : %d\n", max_c, max);
	printf("MIN Group : %c \nNUM of Members : %d\n", min_c, min);
	return 0;
}