#include <stdio.h>

#define MAX_SIZE 20
#define TRUE 1
#define FALSE 0

void avg_ascii(float* total_ascii, int* total_length, int tmp_size) {
	if ('A' <= tmp_size && tmp_size <= 'z') { //�빮�� �ΰ�� A == 65 Z == 90
		*total_ascii += tmp_size;
		(*total_length)++;
		if ('a' <= tmp_size && tmp_size <= 'z') {
			*total_ascii /= *total_length;
		}
	}

	return;
}

int main() {
	char tmp;
	int end_flag = TRUE;
	float total_ascii = 0;
	int total_length = 0;
	char word[MAX_SIZE] = { 0, };

	while (end_flag && total_length < 20) {
		if (!scanf("%c", &tmp)) exit(1);

		if ('A' <= tmp && tmp <= 'z') { //�빮��&�ҹ��� �ΰ�� A == 65 Z == 90
			word[total_length] = tmp;
			avg_ascii(&total_ascii, &total_length, tmp);
			if ('a' <= tmp && tmp <= 'z') { //�ҹ����� ��� a == 97 z == 122
				end_flag = FALSE;
			}
		}
	}

	printf("%s �ܾ���� : %d ASCII�ڵ� ��� �� : %.2f", word, total_length, total_ascii);

	return 0;
}