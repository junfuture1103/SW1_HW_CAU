#include <stdio.h>
#define NAME_SIZE 10
#define TEAM_NUM 6
#define WTL 3

typedef struct _team{
	char name[NAME_SIZE];
	char home[NAME_SIZE];
	int score[WTL]; //Win Tie Lose
	int total;
}team_set;

void sort(team_set team[], int index) {
	int min_index;
	team_set temp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (team[min_index].total <= team[j].total) {
				if (team[min_index].total == team[j].total) {
					if (team[min_index].score[0] < team[j].score[0]) {
						min_index = j;
						continue;
					}
					else {
						if (team[min_index].score[1] < team[j].score[1]) {
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
		temp = team[i];
		team[i] = team[min_index];
		team[min_index] = temp;
	}
}


int main()
{
	team_set team[6];

	for (int i = 0; i < TEAM_NUM; i++) {
		printf("%d번째 팀 이름 : ", i + 1);
		if (!scanf("%s", team[i].name)) exit(1);
		printf("%d번째 홈 구장명 이름 : ", i + 1);
		if (!scanf("%s", team[i].home)) exit(1);
		printf("승 무 패 수 : ");
		if (!scanf("%d %d %d", &team[i].score[0], &team[i].score[1], &team[i].score[2])) exit(1);
		team[i].total = 2 * team[i].score[0] + team[i].score[1];
	}

	printf("\n\n======= 입력 결과 =======\n");

	for (int i = 0; i < TEAM_NUM; i++) {
		printf("[%d번] 팀 이름 : %s 구장 : %s\n", i + 1, team[i].name, team[i].home);
		printf("승/무/패 : %d/%d/%d 총 승점 : %d\n\n", team[i].score[0], team[i].score[1], team[i].score[2], team[i].total);
	}

	sort(team, TEAM_NUM);

	printf("\n\n======= 순위 결정 결과 =======\n");

	for (int i = 0; i < TEAM_NUM; i++) {
		printf("[%d위] 팀 이름 : %s 구장 : %s\n", i + 1, team[i].name, team[i].home);
		printf("승/무/패 : %d/%d/%d 총 승점 : %d\n\n", team[i].score[0], team[i].score[1], team[i].score[2], team[i].total);
	}

	printf("\n\n======= 대진표 결과 =======\n");

	printf("%s VS %s 구장 : %s\n", team[0].name, team[5].name, team[0].home);
	printf("%s VS %s 구장 : %s\n", team[1].name, team[4].name, team[1].home);
	printf("%s VS %s 구장 : %s\n", team[2].name, team[3].name, team[2].home);

	return 0;
}