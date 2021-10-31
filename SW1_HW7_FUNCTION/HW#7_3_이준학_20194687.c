#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_NUM 20
#define GROUP_NUM 10

void sort(int list[], char name[], int index) {
	int min_index, temp;
	char name_tmp;

	for (int i = 0; i < index-1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min_index] > list[j]) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;

		name_tmp = name[i];
		name[i] = name[min_index];
		name[min_index] = name_tmp;
	}
}

char choice_group(int random) {

	if (random <= 9) {
		return 'A';
	}
	else if (random <= 19) {
		return 'B';
	}
	else if (random <= 29) {
		return 'C';
	}
	else if (random <= 39) {
		return 'D';
	}
	else if (random <= 49) {
		return 'E';
	}
	else if (random <= 59) {
		return 'F';
	}
	else if (random <= 69) {
		return 'G';
	}
	else if (random <= 79) {
		return 'H';
	}
	else if (random <= 89) {
		return 'I';
	}
	else {
		return 'J';
	}
}

void print_list(int list[], char name[], int size) {
	for (int i = 0; i < size; i++) {
		if (list[0] == list[i]) {	
			printf("%c : ", name[i]);
			printf("%d ", list[i]);
		}
		if (list[size-1] == list[i]) {
			printf("%c : ", name[i]);
			printf("%d ", list[i]);
		}
	}


}

int main()
{
	int A[RAND_NUM] = { 0, };
	int B[RAND_NUM] = { 0, };
	int C[RAND_NUM] = { 0, };
	int D[RAND_NUM] = { 0, };
	int E[RAND_NUM] = { 0, };
	int F[RAND_NUM] = { 0, };
	int G[RAND_NUM] = { 0, };
	int H[RAND_NUM] = { 0, };
	int I[RAND_NUM] = { 0, };
	int J[RAND_NUM] = { 0, };

	int index[GROUP_NUM] = { 0, };
	char name[GROUP_NUM] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	srand(time(NULL));
	for (int i = 0; i < RAND_NUM; i++)
	{
		int random = rand() % 100;
		//printf("========== 생성된 자연수 : %d ==========\n", random);
		char tmp = choice_group(random);

		switch (tmp) {
			case'A':
				A[index[0]++] = random;
				break;
			case'B':
				B[index[1]++] = random;
				break;
			case'C':
				C[index[2]++] = random;
				break;
			case'D':
				D[index[3]++] = random;
				break;
			case'E':
				E[index[4]++] = random;
				break;
			case'F':
				F[index[5]++] = random;
				break;
			case'G':
				G[index[6]++] = random;
				break;
			case'H':
				H[index[7]++] = random;
				break;
			case'I':
				I[index[8]++] = random;
				break;
			case'J':
				J[index[9]++] = random;
				break;
		}
		sort(index, name, GROUP_NUM);

	}
	print_list(index, name, GROUP_NUM);

	printf("\n");
	printf("그룹 별 인덱스 상태 : ");

	for (int i = 0; i < GROUP_NUM; i++) {
			printf("%c : ", name[i]);
			printf("%d ", index[i]);
	}

	return 0;
}