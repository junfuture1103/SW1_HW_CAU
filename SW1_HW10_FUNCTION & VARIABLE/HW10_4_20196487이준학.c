#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_MAX 25

void sort(int list[], int index) {
	int min_index, temp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min_index] > list[j]) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;
	}
}

int recu_search(int find_num, int list[], int left, int right, int* count) {
	static int index = -1;

	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;

	printf("[%d]번째 순환 %d\n", (*count) + 1, mid);
	(*count)++;

	if (list[mid] == find_num) {
		//mid가 위치
		index = mid;
	}
	else if (list[mid] < find_num) {
		recu_search(find_num, list, mid + 1, right, count);
	}
	else if (list[mid] > find_num) {
		recu_search(find_num, list, left, mid - 1, count);
	}
	return index;
}

int main()
{
	int find_num;
	int tmp[NUM_MAX] = { 0, };
	int flag = 0;

	srand(time(NULL));
	for (int i = 0; i < NUM_MAX; i++)
	{
		int random = rand() % 30 + 71;
		tmp[i] = random;

		if (i != 0) {
			flag = 0;
			while (!flag) {
				for (int j = 0; j < i; j++) {
					if (tmp[j] == random) {
						random = rand() % 30 + 71;
						tmp[i] = random;
						break;
					}
					if (j == i - 1) {
						flag = 1;
					}
				}
			}
		}
	}

	printf("========== 생성된 자연수 ==========\n");
	for (int i = 0; i < NUM_MAX; i++) {
		printf("%2d ", tmp[i]);
	}

	sort(tmp, NUM_MAX);

	printf("\n\n========== 정렬된 자연수 ==========\n");
	for (int i = 0; i < NUM_MAX; i++) {
		printf("%2d ", tmp[i]);
	}

	printf("\n");
	for (int i = 0; i < NUM_MAX; i++) {
		printf("%2d ", i);
	}
	printf("\n\n찾을 숫자를 입력해주세요(위의 배열에 없어도 됨) : ");

	if (!scanf("%d", &find_num)) exit(1);

	int index;
	int count = 0;

	printf("\n\n======= 순환 결과 =======\n");
	index = recu_search(find_num, tmp, 0, NUM_MAX, &count);

	if (index == -1) {
		printf("없음. 비교 횟수 : %d", count);
	}
	else {
		printf("%d에 있음. 비교 횟수 : %d", index, count);
	}

	return 0;
}