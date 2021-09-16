#include <stdio.h>

int main() {
	int num = 0;
	int digit = 1;
	int octal = 0;

	if (!scanf("%d", &num) || num > 20000) exit(1);

	while (num != 0) {
		octal += (num % 8) * digit;
		digit *= 10;
		num /= 8;
	}

	printf("%d", octal);

	return 0;
}