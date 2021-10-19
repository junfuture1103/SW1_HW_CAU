#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));

	char sign[5] = { 'A','B','C','D','F' };
	char name[5] = { 'J','U','N','T','H' };

	printf("========= HW6_4 입력데이터 자동 생성기 =========\n");
	printf("\n이름은 JUNTH");

	for (int j = 0; j < 5; j++) {
		printf("\n\n");
		printf("학생이름 : %c\n", name[j]);
		for (int k = 0; k < 2; k++) {
			if (k == 0) {
				printf("국어 : ");
			}
			else {
				printf("수학 : ");
			}
			for (int i = 0; i < 5; i++) {
				int tmp = rand() % 5;
				printf("%c", sign[tmp]);
			}
		}
	}


	return 0;
}