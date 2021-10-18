#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 50

int main() {
	srand(time(NULL));
	int group_num[4] = { 0, };
	int tmp = 0;
	
	for (int i = 0; i < 50; i++) {
		tmp = rand() % 100 + 1;
		if (tmp < 50 && tmp % 2 == 1) {
			group_num[0]++;
		}
		else if (tmp >= 50 && tmp % 2 == 1) {
			group_num[1]++;
		}
		else if (tmp < 50 && tmp % 2 == 0) {
			group_num[2]++;
		}
		else if (tmp >= 50 && tmp % 2 == 0) {
			group_num[3]++;
		}
		else {
			printf("입력이 잘못되었습니다.");
			exit(1);
		}
	}

	char name[4] = { 'A','B','C','D' };

	printf("====== 정렬 전 ======\n");
	for (int i = 0; i < 4; i++) {
		printf("%c:%d ", name[i], group_num[i]);
	}

	int min;
	int min_index;
	int temp;
	char name_tmp;

	for (int i = 0; i < 3; i++) {
		min = group_num[i];
		min_index = i;
		for (int j = i+1; j < 4; j++) {
			if (min > group_num[j]) {
				min = group_num[j];
				min_index = j;
			}
		}
		temp = group_num[i];
		group_num[i] = group_num[min_index];
		group_num[min_index] = temp;

		name_tmp = name[i];
		name[i] = name[min_index];
		name[min_index] = name_tmp;
	}

	printf("\n\n====== 정렬완료 ======\n");
	for (int i = 0; i < 4; i++) {
		printf("%c:%d ", name[i], group_num[i]);
	}

	printf("\n\n");

	printf("MAX %c:%d\n", name[3], group_num[3]);
	printf("MIN %c:%d", name[0], group_num[0]);

	return 0;
}