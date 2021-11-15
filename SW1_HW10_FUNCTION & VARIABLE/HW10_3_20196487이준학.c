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

int main() {
	int test = 0;
	int n = 5;
	int total = 0;

	test = recu_fib(n);
	printf("RECU : %d\n", test);

	return 0;
}