#include <stdio.h>

int main() {
	int time = 0;
	
	if(!scanf("%d", &time)) exit(1);

	printf("%d:%d:%d", time / 3600, time % 3600 / 60, time % 3600 % 60);

	return 0;
}