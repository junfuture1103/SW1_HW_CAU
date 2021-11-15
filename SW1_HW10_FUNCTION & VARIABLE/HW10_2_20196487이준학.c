#include <stdio.h>

#define MAX_SIZE 20
#define TRUE 1
#define FALSE 0

int recu_fib(int n) {
	if (n < 3) {
		return 1;
	}
	return recu_fib(n - 2) + recu_fib(n - 1);
}

void recu_nodu_fib(int n, int* total) {
	if (n < 3) {
		(*total) = 1;
		return;
	}
	return recu_fib(n - 2) + recu_fib(n - 1);
}

int iter_fib(int n) {
	if (n < 3) {
		return 1;
	}

	int a1 = 1;
	int a2 = 1;
	int tmp;

	for (int i = 0; i < n - 2; i++) {
		tmp = a1 + a2;
		a1 = a2;
		a2 = tmp;
	}

	return tmp;
}

int main() {
	int test = 0;
	int n = 5;
	int total = 0;

	test = iter_fib(n);
	printf("ITER : %d\n", test);

	test = recu_fib(n);
	printf("RECU : %d\n", test);

	test = recu_nodu_fib(n, &total);
	printf("RECU (non duplicate) : %d", test);
	return 0;
}