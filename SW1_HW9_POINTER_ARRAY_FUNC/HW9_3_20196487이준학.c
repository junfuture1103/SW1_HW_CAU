#include <stdio.h>
#define STU_NUM 5

void recu_search(char find_num, char list[], int left, int right, int* count, int* index) {
	if (left > right) {
		printf("\n����");
		return;
	}

	int mid = (left + right) / 2;

	printf("[%d]��° ��ȯ %d\n", (*count) + 1, mid);
	(*count)++;

	if (list[mid] == find_num) {
		//mid�� ��ġ
		*index = mid;
	}
	else if (list[mid] < find_num) {
		recu_search(find_num, list, mid+1, right, count, index);
	}
	else if (list[mid] > find_num) {
		recu_search(find_num, list, left, mid-1, count, index);
	}
	return;
}

int iter_search(char find_num, char list[], int size, int* index) {
	int left = 0;
	int right = size;

	int iter_count = 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		printf("[%d]��° �ݺ��� %d\n", iter_count, mid);
		if (list[mid] == find_num) {
			//mid�� ��ġ
			*index = mid;
			return iter_count;
		}
		//ū ��� ������
		else if (list[mid] < find_num) {
			left = mid+1;
		}
		//������� �������� 
		else if (list[mid] > find_num) {
			right = mid - 1;
		}
		iter_count++;
	}
	return iter_count;
}

void sort(int list[], char name[], int index) {
	int min_index, temp;
	char name_tmp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (name[min_index] > name[j]) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;

		name_tmp = name[i];
		name[i] = name[min_index];
		name[min_index] = name_tmp;
	}
	return;
}

void score_sort(int list[], char name[], int index) {
	int min_index, temp;
	char name_tmp;

	for (int i = 0; i < index - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < index; j++) {
			if (list[min_index] < list[j]) {
				min_index = j;
			}
		}
		temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;

		name_tmp = name[i];
		name[i] = name[min_index];
		name[min_index] = name_tmp;
	}
	return;
}
int main() {
	int score[STU_NUM] = { 0, };
	char name[STU_NUM] = { 0, };
	char find = '0';

	for (int i = 0; i < STU_NUM; i++) {
		printf("%d��°\n �̸� �Է� ���ּ��� : ", i + 1);
		if (!scanf("%c", &name[i])) exit(1);
		if (!getchar()) exit(1);

		printf("���� �Է� ���ּ��� : ");
		if (!scanf("%d", &score[i])) exit(1);
		if (!getchar()) exit(1);
	}

	int rank_score[STU_NUM] = { 0, };
	char rank_name[STU_NUM] = { 0, };

	//�̸����� ����
	sort(score, name, STU_NUM);
	
	//������ ����
	for (int i = 0; i < STU_NUM; i++) {
		rank_name[i] = name[i];
		rank_score[i] = score[i];
	}
	score_sort(rank_score, rank_name, STU_NUM);

	//���� �� ���
	printf("\n============= �̸� �� ���� =============\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%2c ", name[i]);
	}
	printf("\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%2d ", score[i]);
	}
	printf("\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%2d ", i);
	}

	//���� �� ���
	printf("\n============= ���� �� ���� =============\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%2c ", rank_name[i]);
	}
	printf("\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%2d ", rank_score[i]);
	}
	printf("\n");
	for (int i = 0; i < STU_NUM; i++) {
		printf("%2d ", i);
	}

	//Ž���� ��� ã��
	printf("\n\nã�� ����� �Է����ּ��� : ");
	if (!scanf("%c", &find)) exit(1);

	//�ݺ��� ����Ž��
	int index = -1;
	int count = iter_search(find, name, STU_NUM-1, &index);

	if (index != -1) {
		int rank_index = 0;
		for (int i = 0; i < STU_NUM; i++) {
			if (name[index] == rank_name[i]) {
				rank_index = i;
			}
		}
		printf("%d�� ����. Ž�� Ƚ�� %d \n�̸� : %c ��� : %d ���� : %d", index, count, name[index], rank_index+1, score[index]);
	}
	else {
		printf("����.");
	}
	
	printf("\n\n");

	//��ȯ�� ����Ž��
	count = 0;
	index = -1;
	recu_search(find, name, 0, STU_NUM-1, &count, &index);

	if (index != -1) {
		int rank_index = 0;
		for (int i = 0; i < STU_NUM; i++) {
			if (name[index] == rank_name[i]) {
				rank_index = i;
			}
		}
		printf("%d�� ����. Ž�� Ƚ�� %d \n�̸� : %c ��� : %d ���� : %d", index, count, name[index], rank_index+1 ,score[index]);
	}
	else {
		printf("����.");
	}

	return 0;
}