#include <stdio.h>

int main() {
	//�ߺ��Ǵ� �� ���� ����
	int test[10] = { 1,2,2,2,3,3,4,4,4,5 };
	int temp = 0; //temp�� ó�� ������ �迭�ȿ� ���°�. ó���� ������ �޶����

	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (i != 0) {
			if (test[i - 1] == test[i]) {
				if (temp != test[i]) {
					count++;
					temp = test[i];
				}
			}
		}
	}

	int dup[10] = { 0, };
	int index_count[10] = { 0, };
	//������ ���� ����
	int dup_index = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			index_count[0]++;
			dup[dup_index++] = test[0];
		}
		else {
			for (int j = 0; j < dup_index; j++) {
				if (dup[j] == test[i]) {
					index_count[j]++;
					break;
				}
				if (j == dup_index - 1) {
					dup[dup_index++] = test[i];
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", test[i]);
	}
	printf("\n\n�ߺ��Ǵ� ���� : %d\n", count);

	for (int i = 0; i < dup_index; i++) {
		printf("%d ", dup[i]);
	}
	printf("\n\n�׸� ����\n");
	for (int i = 0; i < dup_index; i++) {
		printf("%d ", index_count[i]);
	}
	return 0;
}