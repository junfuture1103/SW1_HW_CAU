#include <stdio.h>

int main() {
	int up = 0, down = 0;
	int tmp_up=0, tmp_down=0;
	int index = 0;
	float tmp_result = .0;
	float result = .0;

	while (1) {
		printf("========== %d��° �Է��Դϴ�. ==========\n", index++);
		if (!scanf("%d/%d", &up, &down)) exit(1);
		tmp_result = (float)up / down;
		result += (float)up / down;

		tmp_up = up;
		tmp_down = down;

		//���
		while (tmp_up != tmp_down)
		{
			if (tmp_up > tmp_down)
				tmp_up -= tmp_down;
			else
				tmp_down -= tmp_up;
		}
		
		up /= tmp_up;
		down /= tmp_up;

		printf("�Է��� ������ ��� ����Դϴ� : %d/%d\n", up, down);
		printf("�Է��� ������ �Ҽ�ǥ���Դϴ� : %.2f\n", tmp_result);

		//������ ���� �Ǽ� �Ǵ�
		if (result-(int)result > 0){
			printf("�Է��� ���ڵ��� ���Դϴ�. : %.2f\n", result);
		}
		else {
			printf("�Է��� ���ڵ��� ���Դϴ�. : %d\n", (int)result);
		}

		printf("\n");
	}
	return 0;
}