#include <stdio.h>

int main() {
	int num = 0;
	
	if(!scanf("%d", &num) || num > 999) exit(1);

	printf("%d%d%d",num % 10, num % 100 /10 ,  num / 100);

	return 0;
}