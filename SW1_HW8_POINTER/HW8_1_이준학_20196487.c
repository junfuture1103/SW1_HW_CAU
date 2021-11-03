#include <stdio.h>

void swap(int* m, int* n) {
	int tmp = *m;
	*m = *n;
	*n = tmp;
	return;
}

void add_sub(int m, int n) {
	int add_result = m + n;
	int sub_result = m - n;

	printf("ADD_RESULT(m+n) : %d\n", add_result);
	printf("ADD_RESULT(m-n) : %d\n", sub_result);

	return;
}

int main() {
	int m, n;
	if (!scanf("%d", &m)) exit(1);
	if (!scanf("%d", &n)) exit(1);

	add_sub(&m, &n);
	swap(&m, &n);
	printf("After Swap\n");
	add_sub(&m, &n);
	return 0;
}