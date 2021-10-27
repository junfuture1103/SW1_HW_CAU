#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_NUM 50

void sort(int list[], int index) {
	int min_index, temp;
	char name_tmp;

	for (int i = 0; i < index-1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min_index] > list[j]) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;
	}
}

int main()
{
	int even[RAND_NUM] = { 0, };
	int odd[RAND_NUM] = { 0, };
	int even_index = 0; 
	int odd_index = 0;

	srand(time(NULL));
	for (int i = 0; i < RAND_NUM; i++)
	{
		int random = rand() % 100 + 1;
		//printf("========== 생성된 자연수 : %d ==========\n", random);

		if (random % 2 == 0) {
			even[even_index]=random;
			even_index++;
		}
		else {
			odd[odd_index] = random;
			odd_index++;
		}

	}

	sort(even, even_index);
	sort(odd, odd_index);


	printf("정렬된 짝수 리스트 입니다. : ");
	for (int i = 0; i < even_index; i++) {
		printf("%d ", even[i]);
	}

	printf("\n");

	printf("정렬된 홀수 리스트 입니다. : ");
	for (int i = 0; i < odd_index; i++) {
		printf("%d ", odd[i]);
	}
	
	int tmp_odd = 0;
	int tmp_even = 0;
	int result_list[RAND_NUM] = { 0, };

	for (int i = 0; i < RAND_NUM; i++) {
		if (tmp_odd >= odd_index) {
			result_list[i] = even[tmp_even];
			tmp_even++;
		}
		else if (tmp_even >= even_index) {
			result_list[i] = odd[tmp_odd];
			tmp_odd++;
		}
		else {
			if (odd[tmp_odd] >= even[tmp_even]) {
				result_list[i] = even[tmp_even];
				tmp_even++;
			}
			else {
				result_list[i] = odd[tmp_odd];
				tmp_odd++;
			}
		}
	}

	printf("\n\n");

	printf("정렬된 결과 리스트 입니다. : ");
	for (int i = 0; i < RAND_NUM; i++) {
		printf("%d ", result_list[i]);
	}

	return 0;
}