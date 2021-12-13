#include <stdio.h>

int merge(int test[], int test2[], int test_result[], int test_index, int test_index2) {
	int now[2] = { 0, };
	//now[0] for test
	//now[1] for test2
	int result_index = 0;

	while (now[0] != test_index || now[1] != test_index2) {
		if (now[0] == test_index) {
			test_result[result_index] = test2[now[1]];
			result_index++;
			now[1]++;
		}
		else if (now[1] == test_index2) {
			test_result[result_index] = test[now[0]];
			result_index++;
			now[0]++;
		}
		else {
			if (test[now[0]] < test2[now[1]]) {
				test_result[result_index] = test[now[0]];
				result_index++;
				now[0]++;
			}
			else {
				test_result[result_index] = test2[now[1]];
				result_index++;
				now[1]++;
			}
		}
	}

	return result_index;
}

int main() {
	int test[5] = { 1, 3, 5, 7, 9 };
	int test2[5] = { 2, 4, 6, 8, 10 };
	int test_result[10] = { 0, };

	int result_index = merge(test, test2, test_result, 5, 5);

	for (int i = 0; i < result_index; i++) {
			printf("%d ", test_result[i]);
	}

	return 0;
}