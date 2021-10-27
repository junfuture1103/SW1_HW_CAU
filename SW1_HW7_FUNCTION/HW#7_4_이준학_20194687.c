#include <stdio.h>
#include <stdlib.h>

void selection_sort(int list[10], int right) {
	if (right == 0) {
		return;
	}

	int max = 0;
	for (int i = 0; i <= right; i++) {
		if (list[max] < list[i]) {
			max = i;
		}
	}
	int tmp = list[right];
	list[right] = list[max];
	list[max] = tmp;
	right--;

	selection_sort(list, right);
	return;
}

int main() {
	srand(time(NULL));
	int list[10] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		list[i] = rand() % 100;
	}
	
	for (int i = 0; i < 10; i++) {
		printf("%d ", list[i]);
	}

	selection_sort(list, 9);
	printf("\n");

	for (int i = 0; i < 10; i++) {
		printf("%d ", list[i]);
	}
	return 0;
}