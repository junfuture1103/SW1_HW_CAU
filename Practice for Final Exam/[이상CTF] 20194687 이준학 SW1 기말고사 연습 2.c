#include <stdio.h>
#include <string.h>

#define NAME_SIZE 20
#define BOOK_NUM 10
#define SUB_NUM 4
#define SUB_SIZE 25

typedef struct _book {
	char book[NAME_SIZE];
	char author[NAME_SIZE];
	int price;
	int year;
	int month;
}book_type;

void store_book(book_type group[], int* group_index, book_type book) {
	int now_index = 0;
	book_type tmp;
	if (*group_index == 0) {
		group[*group_index] = book;
		(*group_index)++;
	}
	else {
		for (int i = 0; i < *group_index; i++) {
			if (strcmp(group[i].author, book.author) == 1) {
				now_index = i;
				for (int j = (*group_index) - 1; j > i - 1; j--) {
					group[j + 1] = group[j];
				}
				group[now_index] = book;
				(*group_index)++;
				break;
			}
			if (i == (*group_index) - 1) {
				group[*group_index] = book;
				(*group_index)++;
				break;
			}
		}
	}
	return;
}

char classify_book(book_type book) {
	if (book.book[0] == 'I') {
		return 'I';
	}
	else if (book.book[0] == 'C') {
		return 'C';
	}
	else if (book.book[0] == 'M') {
		return 'M';
	}
	else if (book.book[0] == 'E') {
		return 'E';
	}
	else {
		printf("some problem..");
		exit(1);
	}
}

int find_author(book_type group[][BOOK_NUM], int group_index[]) {
	int now[SUB_NUM] = { 0, };
	int min = 0;

	char dup_author[BOOK_NUM][NAME_SIZE];
	char temp[NAME_SIZE] = { 0, };
	int dup_index = 0;
	int dup_count = 0;

	while (now[0] != group_index[0] || now[1] != group_index[1] || now[2] != group_index[2] || now[3] != group_index[3]) {
		for (int i = 0; i < 4; i++) {
			if (now[i] != group_index[i]) {
				min = i;
				break;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (now[i] == group_index[i]) {
				continue;
			}
			//더 작은애 찾음
			if (strcmp(group[min][now[min]].author, group[i][now[i]].author) == 1) {
				min = i;
			}
		}
		if (dup_index != 0) {
			//만약에 지금 들어가는애가 이전애랑 같은데
			if (strcmp(dup_author[dup_index - 1], group[min][now[min]].author) == 0) {
				//아까 같아서 기억해놨던애랑 다르면 count++ -> 같으면 3명이상인 경우
				//지금 같은애 이거 지금 temp야~ 다른 경우에만 count 해줘
				if (strcmp(temp, group[min][now[min]].author) != 0) {
					strncpy(temp, group[min][now[min]].author, NAME_SIZE);
					dup_count++;
				}
			}

			/* 동일 아이디어
			정렬되어있음!!
			중복됐을때 일단 카운트 + 그 중복 발생시키는 숫자 기억하기
			또 중복됐을때 그 중복 발생시키는 숫자랑 같은지 비교 -> 같으면 넘어감 -> 다르면 카운트! 하고 temp 업뎃
			12223334445

			1222333445
		temp: 2  3  4
			*/

		}
		strncpy(dup_author[dup_index], group[min][now[min]].author, NAME_SIZE);
		dup_index++;
		now[min]++;
	}

	printf("========================= for test dup 배열 완성 =========================\n\n");
	for (int j = 1; j < 10; j++) {
		printf("%s ", dup_author[j]);
	}

	char temp_2[NAME_SIZE] = { 0, };
	int dup_count_2 = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			continue;
		}
		if (strcmp(dup_author[i - 1], dup_author[i]) == 0) {
			//temp 지금 같은애 애야!
			if (strcmp(temp_2, dup_author[i]) != 0) {
				strncpy(temp_2, dup_author[i], NAME_SIZE);
				dup_count_2++;
			}
		}
	}

	printf("\n함수 안에서 구한 dup_count(배열 완성 후 계산) : %d\n", dup_count_2);

	return dup_count;
}

int main() {
	book_type book[BOOK_NUM];
	book_type group[SUB_NUM][BOOK_NUM];
	int group_index[SUB_NUM] = { 0, };

	for (int i = 0; i < BOOK_NUM; i++) {
		if (!scanf("%s %s %d %d/%d", book[i].book, book[i].author, &book[i].price, &book[i].year, &book[i].month)) exit(1);
		char tmp = classify_book(book[i]);
		if (tmp == 'I') {
			store_book(group[0], &group_index[0], book[i]);
		}
		else if (tmp == 'C') {
			store_book(group[1], &group_index[1], book[i]);
		}
		else if (tmp == 'M') {
			store_book(group[2], &group_index[2], book[i]);
		}
		else if (tmp == 'E') {
			store_book(group[3], &group_index[3], book[i]);
		}
		else {
			printf("get problem...");
			exit(1);
		}
	}

	printf("========================= for test 입력 완료 =========================\n\n");
	for (int i = 0; i < 4; i++) {
		printf("===========================\n");
		for (int j = 0; j < group_index[i]; j++) {
			printf("%s %s %d %d/%d\n", group[i][j].book, group[i][j].author, group[i][j].price, group[i][j].year, group[i][j].month);
		}
		printf("===========================\n");
	}

	printf("중복되는 저자 수는 : %d\n", find_author(group, group_index));

	return 0;
}