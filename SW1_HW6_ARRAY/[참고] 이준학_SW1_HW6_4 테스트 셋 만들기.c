#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));

	char sign[5] = { 'A','B','C','D','F' };
	char name[5] = { 'J','U','N','T','H' };

	printf("========= HW6_4 �Էµ����� �ڵ� ������ =========\n");
	printf("\n�̸��� JUNTH");

	for (int j = 0; j < 5; j++) {
		printf("\n\n");
		printf("�л��̸� : %c\n", name[j]);
		for (int k = 0; k < 2; k++) {
			if (k == 0) {
				printf("���� : ");
			}
			else {
				printf("���� : ");
			}
			for (int i = 0; i < 5; i++) {
				int tmp = rand() % 5;
				printf("%c", sign[tmp]);
			}
		}
	}


	return 0;
}