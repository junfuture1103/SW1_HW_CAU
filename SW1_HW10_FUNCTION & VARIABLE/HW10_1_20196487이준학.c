#include <stdio.h>

#define MAX_SIZE 20
#define TRUE 1
#define FALSE 0

void avg_ascii(int* total_ascii, int* total_length, int tmp_size) {
	*total_ascii += tmp_size;
	(*total_length)++;
	return;
}

int main() {
	char tmp;
	int end_flag = TRUE;
	int total_ascii = 0;
	int total_length = 0;
	char word[MAX_SIZE] = { 0, };

	while (end_flag && total_length < 20) {
		if (!scanf("%c", &tmp)) exit(1);

		if (65 <= tmp && tmp <= 122) { //대문자 인경우 A == 65 Z == 90
			word[total_length] = tmp;
			avg_ascii(&total_ascii, &total_length, tmp);
			if (97 <= tmp && tmp <= 122) {
				end_flag = FALSE;
			}
		}
	}

	printf("%s 단어길이 : %d ASCII코드 평균 값 : %.2f", word, total_length, (float)total_ascii / total_length);

	return 0;
}