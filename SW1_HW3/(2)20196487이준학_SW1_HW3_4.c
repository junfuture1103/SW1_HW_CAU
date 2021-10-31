#include <stdio.h>

int main() {
	int a, b, c;
	int A_index = 0;
	int B_index = 0;


	if (!scanf("%d", &a) || a > 100) exit(1);
	if (!scanf("%d", &b) || b > 100) exit(1);
	if (!scanf("%d", &c) || c > 100) exit(1);

	(a < 50 && a % 2 == 1) ? A_index++ : B_index++;
	(b < 50 && b % 2 == 1) ? A_index++ : B_index++;
	(c < 50 && c % 2 == 1) ? A_index++ : B_index++;

	printf("GROUP : %c, A_index : %d B_index : %d", (A_index > B_index) ? 'A' : 'B', A_index, B_index);

	return 0;
}