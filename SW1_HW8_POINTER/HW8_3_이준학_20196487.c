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

void recu_search(int find_num, int list[], int left, int right, int* index, int* count) {
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;

	printf("[%d]��° ��ȯ %d\n", (*count) + 1, mid);
	(*count)++;

	if (list[mid] == find_num) {
		//mid�� ��ġ
		*index = mid;
	}
	else if (list[mid] < find_num) {
		recu_search(find_num, list, mid + 1, right, index, count);
	}
	else if (list[mid] > find_num) {
		recu_search(find_num, list, left, mid - 1, index, count);
	}
	return;
}

void iter_search(int find_num, int list[], int size, int* index, int* iter_count) {
	int mid = size / 2;
	int left = 0;
	int right = size;

	while (left < right) {
		mid = (left + right) / 2;
		printf("[%d]��° �ݺ��� %d\n", (*iter_count) + 1, mid);
		(*iter_count)++;
		//������� �������� 
		if (list[mid] == find_num) {
			//mid�� ��ġ
			*index = mid;
			return;
		}
		else if (list[mid] < find_num) {
			left = mid + 1;
		}
		else if (list[mid] > find_num) {
			right = mid - 1;
		}
	}
	return;
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

	printf("========== ������ �ڿ��� ==========\n");
	for (int i = 0; i < NUM_MAX; i++) {
		printf("%2d ", tmp[i]);
	}

	sort(tmp, NUM_MAX);

	printf("\n\n========== ���ĵ� �ڿ��� ==========\n");
	for (int i = 0; i < NUM_MAX; i++) {
		printf("%2d ", tmp[i]);
	}

	printf("\n");
	for (int i = 0; i < NUM_MAX; i++) {
		printf("%2d ", i);
	}
	printf("\n\nã�� ���ڸ� �Է����ּ���(���� �迭�� ��� ��) : ");

	if (!scanf("%d", &find_num)) exit(1);

	int index = -1;
	int iter_count = 0;
	printf("\n\n======= �ݺ� ��� =======\n");
	iter_search(find_num, tmp, NUM_MAX, &index, &iter_count);
	if (index == -1) {
		printf("����. �� Ƚ�� : %d", iter_count);
	}
	else {
		printf("%d�� ����. �� Ƚ�� : %d", index, iter_count);
	}

	printf("\n\n======= ��ȯ ��� =======\n");
	index = -1;
	int recu_count = 0;
	recu_search(find_num, tmp, 0, NUM_MAX, &index, &recu_count);

	if (index == -1) {
		printf("����. �� Ƚ�� : %d", recu_count);
	}
	else {
		printf("%d�� ����. �� Ƚ�� : %d", index, recu_count);
	}

	return 0;
}