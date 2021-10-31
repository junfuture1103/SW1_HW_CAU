#include <stdio.h>

int main() {
	int a, b, c, d;
	int max = 0;
	int min = 0;


	if (!scanf("%d", &a) || a > 100) exit(1);
	if (!scanf("%d", &b) || b > 100) exit(1);
	if (!scanf("%d", &c) || c > 100) exit(1);
	if (!scanf("%d", &d) || d > 100) exit(1);

	max = a;
	max = (max > b) ? max : b;
	max = (max > c) ? max : c;
	max = (max > d) ? max : d;

	min = a;
	min = (min < b) ? min : b;
	min = (min < c) ? min : c;
	min = (min < d) ? min : d;

	printf("input : %d %d %d %d max : %d min : %d", a, b, c, d, max, min);

	return 0;
}