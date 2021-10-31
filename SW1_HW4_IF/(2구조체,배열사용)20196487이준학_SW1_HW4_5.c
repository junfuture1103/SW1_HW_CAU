#include <stdio.h>
#include <malloc.h>

#define LIST_NUM 8

typedef struct {
	int start;
	int end;
}t_table;

t_table* make_table(t_table* tmp) {
	tmp[0].start = 480;
	tmp[1].start = 595;
	tmp[2].start = 619;
	tmp[3].start = 725;
	tmp[4].start = 840;
	tmp[5].start = 945;
	tmp[6].start = 1140;
	tmp[7].start = 1305;

	tmp[0].end = 556;
	tmp[1].end = 652;
	tmp[2].end = 691;
	tmp[3].end = 810;
	tmp[4].end = 908;
	tmp[5].end = 1015;
	tmp[6].end = 1220;
	tmp[7].end = 1378;

	return tmp;
}

int main() {
	int time, min;
	int gap[LIST_NUM] = { 0, };
	t_table* time_list = malloc(sizeof(t_table) * LIST_NUM);
	int tmp = 0;

	time_list = make_table(time_list);

	if (!scanf("%d:%d", &time, &min) || time > 23 || min > 59) {
		printf("올바른 시간 형식으로 입력해주세요 00:00-23:59");
		exit(1);
	}

	tmp = time * 60 + min;

	for (int i = 0; i < LIST_NUM; i++) {
		printf("%d, %d\n", time_list[i].start, time_list[i].end);
	}

	int gap_tmp = 0;

	for (int i = 0; i < LIST_NUM; i++) {
		gap_tmp = time_list[i].start - tmp;
		if (gap_tmp < 0) {
			gap[i] = -gap_tmp;
		}
		else {
			gap[i] = gap_tmp;
		}
	}

	min = gap[0];
	int min_index = 0;

	for (int i = 1; i < LIST_NUM; i++) {
		if (min > gap[i]) {
			min = gap[i];
			min_index = i;
		}
	}

	printf("min : %d index : %d \nstart : %02d:%02d end: %02d:%02d", min, min_index, time_list[min_index].start / 60, time_list[min_index].start % 60, time_list[min_index].end / 60, time_list[min_index].end % 60);

	return 0;
}