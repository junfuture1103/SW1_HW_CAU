#include <stdio.h>

int main() {
	int time, min;
	int tmp = 0;

	if (!scanf("%d:%d", &time, &min) || time > 23 || min > 59) {
		printf("�ùٸ� �ð� �������� �Է����ּ��� 00:00-23:59");
		exit(1);
	}
	tmp = time * 60 + min;

	/*
		480
		595
		619
		725
		840
		945
		1140
		1305
	*/

	return 0;
}