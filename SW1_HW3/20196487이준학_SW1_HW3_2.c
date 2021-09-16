#include <stdio.h>

int main() {
	int score = 0;

	if (!scanf("%d", &score) || score > 100) exit(1);

	if (score >= 90) {
		printf("%c", 'A');
	}
	else if (score >= 80) {
		printf("%c", 'B');
	}
	else if (score >= 70) {
		printf("%c", 'C');
	}
	else if (score >= 60) {
		printf("%c", 'D');
	}
	else {
		printf("%c", 'F');
	}

	return 0;
}