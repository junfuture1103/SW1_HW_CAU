#include <stdio.h>
#include <string.h>

#define LINE_SIZE 50

int main() {
	char line[LINE_SIZE];
	char sub_string[LINE_SIZE];

	printf("���ڿ� : ");
	if (!gets(line)) exit(1);
	printf("�Է��� ���ڿ� : %s\n", line);

	printf("sub_string : ");
	if (!gets(sub_string)) exit(1);
	printf("�Է��� sub_string : %s\n", line);

	char* result = line;
	int index = 0;
	int count = 1;
	printf("\n\n =========== Ž�����  ===========\n\n");
	result = strstr(line, sub_string);
	while (result != NULL) {
		printf("%d��° �߰� : %d�� ����\n", count++, result - line); // char ptr - char ptr
		result = strstr(result + 1, sub_string);
	}
	printf("%d�� �߰�", count - 1);
	return 0;
}