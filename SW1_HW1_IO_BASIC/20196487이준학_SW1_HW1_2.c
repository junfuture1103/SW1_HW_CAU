#include <stdio.h>

int main() {
	int kor_sc = 0;
	int eng_sc = 0;
	char name = '\0';

	if (!scanf("%d", &kor_sc)) exit(1);
	if (!scanf("%d", &eng_sc)) exit(1);
	if (!getchar()) exit(1);
	if (!scanf("%c", &name)) exit(1);

	int total_sc = kor_sc + eng_sc;
	float average_sc = total_sc / 2;

	printf("NAME ENGLISH KOREAN TOTAL AVERAGE\n");
	printf("     SCORE   SCORE  SCORE SCORE\n");
	printf("%-4c %-7d %-6d %-5d %-7.2f\n", name, eng_sc, kor_sc, total_sc, average_sc);

	return 0;
}