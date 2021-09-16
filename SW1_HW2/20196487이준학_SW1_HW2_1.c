#include <stdio.h>

int main() {
	int num = 0;
	
	if(!scanf("%d", &num) || num > 99) exit(1);

	printf("%d%d",num % 10, num / 10);

	return 0;
}