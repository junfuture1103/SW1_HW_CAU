#include <stdio.h>

#define MAX_SIZE 20
#define TRUE 1
#define FALSE 0

void recu_fib(int n, int list[], int count_list[]) {
	if (n == 1 || n == 2) {
		list[n - 1] = 1;
		count_list[n - 1]++;
		return;
	}
	recu_fib(n - 1, list, count_list);
	recu_fib(n - 2, list, count_list);
	list[n - 1] = list[n - 2] + list[n - 3];
	count_list[n - 1]++;
	return;
}

int main() {
	int n = 0;
	int total = 0;
	int list[MAX_SIZE] = { 0, };
	int count_list[MAX_SIZE] = { 0, };

	printf("피보나치 항 개수를 입력해주세요 : ");
	if (!scanf("%d", &n) || n > 20) exit(1);

	recu_fib(n, list, count_list);
	printf("\nRECU : ");

	for (int i = 0; i < n; i++) {
		printf("%d(%d) ", list[i], count_list[i]);
	}

	return 0;
}