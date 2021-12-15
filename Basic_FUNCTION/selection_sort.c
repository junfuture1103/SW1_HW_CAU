#include <stdio.h>

void sort(int list[], int index) {
	int min;
	int temp;

	for (int i = 0; i < index - 1; i++) {
		min = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min] > list[j]) {
				min = j;
			}
		}
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
	return;
}

int main() {
	int test[5] = { 5,4,3,2,1 };
	sort(test, 5);
	printf("\n\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", test[i]);
	}
	return 0;
}