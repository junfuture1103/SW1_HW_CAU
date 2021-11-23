#include <stdio.h>
#include <string.h>

#define LINE_SIZE 50

int main() {
	char line[LINE_SIZE];
	char sub_string[LINE_SIZE];

	printf("문자열 : ");
	if (!gets(line)) exit(1);
	printf("입력한 문자열 : %s\n", line);

	printf("sub_string : ");
	if (!gets(sub_string)) exit(1);
	printf("입력한 sub_string : %s\n", line);

	char* result = line;
	int index = 0;
	int count = 1;
	printf("\n\n =========== 탐색결과  ===========\n\n");
	result = strstr(line, sub_string);
	while (result != NULL) {
		printf("%d번째 발견 : %d에 있음\n", count++, result - line); // char ptr - char ptr
		result = strstr(result + 1, sub_string);
	}
	printf("%d번 발견", count - 1);
	return 0;
}