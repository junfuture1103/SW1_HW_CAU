#include <stdio.h>

int main() {
	int time, min;
	int tmp = 0;

	if (!scanf("%d:%d", &time, &min) || time > 23 || min > 59) {
		printf("올바른 시간 형식으로 입력해주세요 00:00-23:59");
		exit(1);
	}

	//시간 0-1439
	tmp = time * 60 + min;

	if (tmp <= 480) {
		printf("8:00 a.m.   9:16 a.m.");
	}
	else if (tmp > 480 && tmp < 595) {
		printf("9:55 a.m.   10:52 a.m.");
	}
	else if (tmp > 595 && tmp < 619) {
		printf("12:05 p.m.  1:30 p.m.");
	}
	else if (tmp > 619 && tmp < 725) {
		printf("2:00 p.m.    3:08 p.m.");
	}
	else if (tmp > 725 && tmp < 840) {
		printf("3:45 p.m.    4:55 p.m.");
	}
	else if (tmp > 840 && tmp < 945) {
		printf("7:00 p.m.    8:20 p.m.");
	}
	else if (tmp > 945 && tmp < 1140) {
		printf("9:45 p.m.    10:58 p.m.");
	}
	else if (tmp > 1140 && tmp < 1305) {
		printf("9:55 a.m.   10:52 a.m.");
	}
	else {
		printf("Uhm...");
	}

	return 0;
}