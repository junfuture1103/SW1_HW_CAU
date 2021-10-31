#include <stdio.h>

int main() {
	int a, b, c, d, e, f, g, h;
	int min = 0, max = 0;

	if (!scanf("%d", &a) || a > 100) exit(1);
	if (!scanf("%d", &b) || b > 100) exit(1);
	if (!scanf("%d", &c) || c > 100) exit(1);
	if (!scanf("%d", &d) || d > 100) exit(1);
	if (!scanf("%d", &e) || e > 100) exit(1);
	if (!scanf("%d", &f) || f > 100) exit(1);
	if (!scanf("%d", &g) || g > 100) exit(1);
	if (!scanf("%d", &h) || h > 100) exit(1);

	max = a;
	min = a;

	if (max < b) {
		max = b;
	}
	if (max < c) {
		max = c;
	}
	if (max < d) {
		max = d;
	}
	if (max < e) {
		max = e;
	}
	if (max < f) {
		max = f;
	}	
	if (max < g) {
		max = g;
	}
	if (max < h) {
		max = h;
	}

	if (min > b) {
		min = b;
	}
	if (min > c) {
		min = c;
	}
	if (min > d) {
		min = d;
	}
	if (min > e) {
		min = e;
	}
	if (min > f) {
		min = f;
	}
	if (min > g) {
		min = g;
	}
	if (min > h) {
		min = h;
	}

	printf("최대 : %d 최소 : %d", max, min);

	return 0;
}