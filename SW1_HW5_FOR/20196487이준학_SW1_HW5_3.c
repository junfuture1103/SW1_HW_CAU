#include <stdio.h>

int main() {
	char tmp;
	int count = 0;
	int tmp_size = 0;
	int avg_size = 0;
	int end_flag = 1;

	while (end_flag) {
		if (!scanf("%c", &tmp)) exit(1);

		switch (tmp) {
			case ' ':
				count++;
				avg_size += tmp_size;
				tmp_size = 0;
				break;
			case '\t':
				count++;
				avg_size += tmp_size;
				tmp_size = 0;
				break;
			case '\n':
				count++;
				avg_size += tmp_size;
				end_flag = 0;
				break;
			default:
				tmp_size++;
		}
	}

	printf("�ܾ��� ������ %d �� ���ĺ� ������ %d ��� �ܾ� ���̴� %.2f �Դϴ�.", count, avg_size, (float)avg_size / count);

	return 0;
}