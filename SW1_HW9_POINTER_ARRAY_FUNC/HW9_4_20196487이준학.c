#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MAX 30
#define GROUP_NUM 10

void tmp_sort(int list[], char name[], int left, int right) {
	if (left >= right) return;
	int min_index, temp;
	char name_tmp;

	for (int i = left; i < right; i++) {
		min_index = i;
		for (int j = i + 1; j < right + 1; j++) {
			if (name[min_index] > name[j]) {
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
	return;
}

void sort(int list[], char name[], int index) {
	int min_index, temp;
	char name_tmp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min_index] < list[j]) {
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
	return;
}

int main() {
	srand(time(NULL));
	char group[GROUP_NUM] = { 'A', 'B', 'C','D','E','F','G','H','I','J' };
	int group_index[GROUP_NUM] = { 0, };

	for (int i = 0; i < RAND_MAX; i++)
	{
		int random = rand() % 100;
		if (random < 10) {
			group_index[0]++;
		}
		else if (random < 20) {
			group_index[1]++;
		}
		else if (random < 30) {
			group_index[2]++;
		}
		else if (random < 40) {
			group_index[3]++;
		}
		else if (random < 50) {
			group_index[4]++;
		}
		else if (random < 60) {
			group_index[5]++;
		}
		else if (random < 70) {
			group_index[6]++;
		}
		else if (random < 80) {
			group_index[7]++;
		}
		else if (random < 90) {
			group_index[8]++;
		}
		else if (random < 100) {
			group_index[9]++;
		}
	}

	sort(group_index, group, GROUP_NUM);
	for (int i = 0; i < GROUP_NUM; i++) {
		printf("%c ", group[i]);
	}
	printf("\n");
	for (int i = 0; i < GROUP_NUM; i++) {
		printf("%d ", group_index[i]);
	}
	printf("\n");
	int left = 0;
	int right = 0;

	for (int i = 1; i < GROUP_NUM; i++) {
		//printf("left : %d right : %d\n", left, right);
		if (group_index[left] == group_index[i]) {
			right++;
		}
		else {
			tmp_sort(group_index, group, left, right);
			right++;
			left = right;
		}
	}

	for (int i = 0; i < GROUP_NUM; i++) {
		printf("%c ", group[i]);
	}
	printf("\n");
	for (int i = 0; i < GROUP_NUM; i++) {
		printf("%d ", group_index[i]);
	}

	return 0;
}