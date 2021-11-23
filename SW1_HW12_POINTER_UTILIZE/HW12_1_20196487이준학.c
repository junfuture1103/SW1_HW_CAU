#include <stdio.h>
#define NAME_SIZE 10
#define TEAM_NUM 6

void sort(int list[], int win[], int tie[], int index_list[], int index) {
	int min_index, temp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[index_list[min_index]] <= list[index_list[j]]) {
				if (list[index_list[min_index]] == list[index_list[j]]) {
					if (win[index_list[min_index]] < win[index_list[j]]) {
						min_index = j;
						continue;
					}
					else {
						if (tie[index_list[min_index]] < tie[index_list[j]]) {
							min_index = j;
							continue;
						}
						else {
							continue;
						}
					}
				}
				min_index = j;
			}
		}
		temp = index_list[i];
		index_list[i] = index_list[min_index];
		index_list[min_index] = temp;
	}
}

int main()
{
	char name[TEAM_NUM][NAME_SIZE];
	char home[TEAM_NUM][NAME_SIZE];
	int index_list[TEAM_NUM] = { 0,1,2,3,4,5 };
	int score[3][TEAM_NUM];
	int total[TEAM_NUM];

	for (int i = 0; i < TEAM_NUM; i++) {
		printf("%d번째 팀 이름 : ", i + 1);
		if (!scanf("%s", name[i])) exit(1);
		printf("%d번째 홈 구장명 이름 : ", i + 1);
		if (!scanf("%s", home[i])) exit(1);
		printf("승 무 패 수 : ");
		if (!scanf("%d %d %d", &score[0][i], &score[1][i], &score[2][i])) exit(1);
		total[i] = 2 * score[0][i] + score[1][i];
	}

	sort(total, score[0], score[1], index_list, TEAM_NUM);

	printf("\n\n======= 순위 결정 결과 =======\n");

	for (int i = 0; i < TEAM_NUM; i++) {
		printf("[%d위] 팀 이름 : %s 구장 : %s 승/무/패 : %d/%d/%d\n", i+1, name[index_list[i]], home[index_list[i]], score[0][index_list[i]], score[1][index_list[i]], score[2][index_list[i]]);
	}

	printf("\n\n======= 대진표 결과 =======\n");

	printf("%s VS %s 구장 : %s\n", name[index_list[0]], name[index_list[5]], home[index_list[0]]);
	printf("%s VS %s 구장 : %s\n", name[index_list[1]], name[index_list[3]], home[index_list[1]]);
	printf("%s VS %s 구장 : %s\n", name[index_list[2]], name[index_list[4]], home[index_list[2]]);

	return 0;
}