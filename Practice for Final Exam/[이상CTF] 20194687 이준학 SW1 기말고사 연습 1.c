#include <stdio.h>
#define NAME_SIZE 20
#define YM 10
#define BOOK_NUM 10

typedef struct _book {
	char book[NAME_SIZE];
	char author[NAME_SIZE];
	int price;
	int year;
	int month;
}book_type;

char classify_book(book_type book) {
	if (book.year < 2000) {
		return 'A';
	}
	else {
		return 'B';
	}
}

void store_book(book_type book, book_type group[BOOK_NUM], int* group_index) {
	int now_index = 0;
	book_type tmp;
	if (*group_index == 0) {
		group[*group_index] = book;
		(*group_index)++;
	}
	else {
		for (int i = 0; i < *group_index; i++) {
			if (group[i].year > book.year) {
				now_index = i;
				for (int j = (*group_index)-1; j > i-1; j--) {
					group[j + 1] = group[j];
				}
				group[now_index] = book;
				(*group_index)++;
				break;
			}
			else if (group[i].year == book.year) {
				if (group[i].month > book.month) {
					now_index = i;
					for (int j = (*group_index) - 1; j > i - 1; j--) {
						group[j + 1] = group[j];
					}
					group[now_index] = book;
					(*group_index)++;
					break;
				}
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

book_type find_next(book_type group_A[], book_type group_B[], int index[], int* now_A, int* now_B) {
	book_type tmp;
	while (*now_A != index[0] || *now_B != index[1]) {
		if (*now_A == index[0]) {
			tmp = group_B[*now_B];
			(*now_B)++;
			return tmp;
		}
		else if (*now_B == index[1]) {
			tmp = group_A[*now_A];
			(*now_A)++;
			return tmp;
		}
		else {
			if (group_A[*now_A].year < group_B[*now_B].year) {
				tmp = group_A[*now_A];
				(*now_A)++;
				return tmp;
			}
			else if (group_A[*now_A].year == group_B[*now_B].year) {
				if (group_A[*now_A].month <= group_B[*now_B].month) {
					tmp = group_A[*now_A];
					(*now_A)++;
					return tmp;
				}
				else {
					tmp = group_B[*now_B];
					(*now_B)++;
					return tmp;
				}
			}
			else {
				tmp = group_B[*now_B];
				(*now_B)++;
				return tmp;
			}
		}
	}
}

int main() {
	book_type book[BOOK_NUM];
	book_type group[2][BOOK_NUM];

	int group_index[2] = { 0, 0 };

	for (int i = 0; i < BOOK_NUM; i++) {
		if(!scanf("%s %s %d %d/%d", book[i].book, book[i].author, &book[i].price, &book[i].year, &book[i].month)) exit(1);
		char tmp = classify_book(book[i]);
		if (tmp == 'A') {
			store_book(book[i], group[0], &group_index[0]);
		}
		else if (tmp == 'B') {
			store_book(book[i], group[1], &group_index[1]);
		}
		else {
			printf("get problem...");
			exit(1);
		}
	}	
	
	printf("========================= for test 입력 완료 =========================\n\n");
	for (int i = 0; i < 2; i++) {

		printf("===========================\n");
		for (int j = 0; j < group_index[i]; j++) {
			printf("%s %s %d %d/%d\n", group[i][j].book, group[i][j].author, group[i][j].price, group[i][j].year, group[i][j].month);
		}
		printf("===========================\n");
	}

	int now[2] = { 0, };
	printf("========================= for test =========================\n\n");
	while(now[0] != group_index[0] || now[1] != group_index[1]) {
		book_type temp = find_next(group[0], group[1], group_index, &now[0], &now[1]);
		printf("%s %s %d %d/%d\n", temp.book, temp.author, temp.price, temp.year, temp.month);
	}

	/*
	printf("========================= for test =========================\n\n");
	for (int i = 0; i < BOOK_NUM; i++) {
		printf("%s %s %d %d/%d\n", book[i].book, book[i].author, book[i].price, book[i].year, book[i].month);
	}
	*/




	return 0;
}