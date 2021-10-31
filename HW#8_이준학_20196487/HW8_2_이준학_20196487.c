#include <stdio.h>
#define LINE_MAX 5


void sort(int list[], int line[], int count[], float avg[], int index) {
	int min_index, temp;
	int line_tmp;
	int count_tmp;
	int avg_tmp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min_index] > list[j]) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;

		line_tmp = line[i];
		line[i] = line[min_index];
		line[min_index] = line_tmp;

		count_tmp = count[i];
		count[i] = count[min_index];
		count[min_index] = count_tmp;

		avg_tmp = avg[i];
		avg[i] = avg[min_index];
		avg[min_index] = avg_tmp;
	}
}

void line_scan(int* line_num, int word_rank[], int all_rank[], float avg_rank[]) {
	char tmp;
	int count = 0;
	int tmp_size = 0;
	int avg_size = 0;
	int empty_flag = 2;
	int end_flag = 1;

	while (end_flag) {
		if (!scanf("%c", &tmp)) exit(1);

		switch (tmp) {
		case ' ': // "apple banna" -> count == 3
			if (tmp_size == 0) {
				break;
			}
			if (empty_flag) {
				continue;
			}
			count++;
			avg_size += tmp_size;
			empty_flag = 1;
			tmp_size = 0;
			break;
		case '\t':
			if (tmp_size == 0) {
				break;
			}
			if (empty_flag) {
				continue;
			}
			count++;
			avg_size += tmp_size;
			empty_flag = 1;
			tmp_size = 0;
			break;
		case '\n':
			if (empty_flag == 0) {
				count++;
			}
			avg_size += tmp_size;
			end_flag = 0;
			break;
		default:
			empty_flag = 0;
			tmp_size++;
		}
	}

	word_rank[(*line_num) - 1] = count;
	all_rank[(*line_num) - 1] = avg_size;
	avg_rank[(*line_num) - 1] = (count == 0 ? 0 : (float)avg_size / count);
	(*line_num)++;

	return;
}

int main() {
	int line_num = 1;

	int word_rank[LINE_MAX] = { 0, };
	int all_rank[LINE_MAX] = { 0, };
	float avg_rank[LINE_MAX] = { .0, };
	int rank_tmp[LINE_MAX] = { 1,2,3,4,5 };

	while (line_num <= LINE_MAX) {
		line_scan(&line_num, word_rank, all_rank, avg_rank);
	}

	/*
	for (int i = 0; i < LINE_MAX; i++) {
		printf("%d ", word_rank[i]);
	}
	*/
	printf("\n============= 정렬 전 =============\n");
	for (int i = 0; i < LINE_MAX; i++) {
		printf("[%d]번 라인 단어의 갯수는 %d 총 알파벳 갯수는 %d 평균 단어 길이는 %.2f 입니다.\n", rank_tmp[i], word_rank[i], all_rank[i], avg_rank[i]);
	}

	sort(word_rank, rank_tmp, all_rank, avg_rank, LINE_MAX);

	/*
	for (int i = 0; i < LINE_MAX; i++) {
		printf("%d ", word_rank[i]);
	}
	*/

	printf("\n============= 정렬(by 단어 갯수) 후 =============\n");
	for (int i = 0; i < LINE_MAX; i++) {
		printf("[%d]번 라인 단어의 갯수는 %d 총 알파벳 갯수는 %d 평균 단어 길이는 %.2f 입니다.\n", rank_tmp[i], word_rank[i], all_rank[i], avg_rank[i]);
	}

	//텍스트전체 단어 갯수와 평균길이 구하기
	int text_count = 0;
	int text_word = 0;
	float text_avg = .0;

	for (int i = 0; i < LINE_MAX; i++) {
		text_count += word_rank[i];
		text_word += all_rank[i];
	}
	text_avg = (float)text_word/text_count;

	printf("\n");
	printf("전체 단어 갯수 : %d 전체 단어 길이 평균 : %.2f", text_count, text_avg);

	return 0;
}