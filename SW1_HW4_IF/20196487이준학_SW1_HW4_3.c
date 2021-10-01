#include <stdio.h>

int main() {
	int a, b, c, d;
	int A_index = 0, B_index = 0;

	if (!scanf("%d", &a) || a > 100) exit(1);
	if (!scanf("%d", &b) || b > 100) exit(1);
	if (!scanf("%d", &c) || c > 100) exit(1);
	if (!scanf("%d", &d) || d > 100) exit(1);

	if (a < 50 && a % 2 == 1) {
		A_index++;
	}
	else {
		B_index++;
	}
	if (b < 50 && b % 2 == 1) {
		A_index++;
	}
	else {
		B_index++;
	}
	if (c < 50 && c % 2 == 1) {
		A_index++;
	}
	else {
		B_index++;
	}
	if (d < 50 && d % 2 == 1) {
		A_index++;
	}
	else {
		B_index++;
	}

	if (A_index > B_index) {
		printf("멤버수가 많은 그룹 : A 멤버수 : %d", A_index);
	}
	else if (A_index == B_index) {
		printf("멤버 수가 동일합니다. A 멤버수 : %d B 멤버수 : %d", A_index, B_index);
	}
	else {
		printf("멤버수가 많은 그룹 : B 멤버수 : %d", B_index);
	}


	return 0;
}