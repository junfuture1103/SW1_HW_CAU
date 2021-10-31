#include <stdio.h>

int main() {
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

	printf("�ܾ��� ������ %d �� ���ĺ� ������ %d ��� �ܾ� ���̴� %.2f �Դϴ�.", count, avg_size, (count == 0 ? 0 : (float)avg_size / count));

	return 0;
}