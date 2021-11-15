#include <stdio.h>

#define MAX_SIZE 20
#define TRUE 1
#define FALSE 0

void recu_fib(int n, int list[]) {
	if (n == 1 || n == 2) {
		list[n - 1] = 1;
		return;
	}
	recu_fib(n - 1, list);
	recu_fib(n - 2, list);
	list[n - 1] = list[n - 2] + list[n - 3];
	return;
}

/*
void recu_nodu_fib(int n, int list[]) {
	if (n < 3) {
		return 1;
	}

	return recu_fib(n - 2) + recu_fib(n - 1);
}
*/

void iter_fib(int n, int list[]) {
	if (n < 3) {
		printf("올바른 수를 입력해주세요 n>=3");
		return;
	}

	list[0] = list[1] = 1;

	for (int i = 2; i < n; i++) {
		list[i] = list[i - 1] + list[i - 2];
	}
	return;
}

int main() {
	int n = 0;
	int total = 0;
	int list[MAX_SIZE] = { 0, };

	printf("피보나치 항 개수를 입력해주세요 : ");
	if (!scanf("%d", &n) || n > 20) exit(1);

	iter_fib(n, list);
	printf("ITER : ");

	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
		list[i] = 0;
	}

	recu_fib(n, list);
	printf("\nREC : ");

	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}

	return 0;
}