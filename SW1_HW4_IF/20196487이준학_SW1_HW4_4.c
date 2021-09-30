#include <stdio.h>

int main() {
	int num1 = 0, num2 = 0;
	float result=0;
	char oper;

	if (!scanf("%d%c%d", &num1, &oper, &num2)) exit(1);

	switch (oper) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '/':
			result = (float)num1 / num2;
			printf("%.2f", result);
			exit(1);
		case '*':
			result = num1 * num2;
			break;
		case '&':
			result = num1 & num2;
			printf("%#x", (int)result);
			exit(1);
		case '|':
			result = num1 | num2;			
			printf("%#x", (int)result);
			exit(1);
		case '^':
			result = num1 ^ num2;
			printf("%#x", (int)result);
			exit(1);
		default:
			printf("연산자를 잘 입력해주세요 가능한 연산 (+, -, /, *, &, |, ^)");
			exit(1);
	}

	printf("%d", (int)result);

	return 0;
}