#include <stdio.h>
#define NAME_SIZE 4

int main() {
	int kor_sc_A = 0;
	int eng_sc_A = 0;

	int kor_sc_B = 0;
	int eng_sc_B = 0;

	char name_A[NAME_SIZE] = { 0, };
	char name_B[NAME_SIZE] = { 0, };

	//�л�A
	if (!scanf("%d", &kor_sc_A)) exit(1);
	if (!scanf("%d", &eng_sc_A)) exit(1);
	if (!getchar()) exit(1);
	if (!scanf("%s", name_A)) exit(1);

	//�л�B
	if (!scanf("%d", &kor_sc_B)) exit(1);
	if (!scanf("%d", &eng_sc_B)) exit(1);
	if (!getchar()) exit(1);
	if (!scanf("%s", name_B)) exit(1);

	//�л� A ���
	int total_sc = kor_sc_A + eng_sc_A;
	float average_sc = (float)total_sc / 2;
	printf("\nNAME ENGLISH KOREAN TOTAL AVERAGE\n");
	printf("       SCORE  SCORE SCORE   SCORE\n");
	printf("%-4s %-7d %-6d %-5d %-7.2f\n", name_A, eng_sc_A, kor_sc_A, total_sc, average_sc);

	//�л� B ���
	total_sc = kor_sc_B + eng_sc_B;
	average_sc = (float)total_sc / 2;
	printf("\nNAME ENGLISH KOREAN TOTAL AVERAGE\n");
	printf("       SCORE  SCORE SCORE   SCORE\n");
	printf("%-4s %-7d %-6d %-5d %-7.2f", name_B, eng_sc_B, kor_sc_B, total_sc, average_sc);

	return 0;
}