#include <stdio.h>

int main() {
	int up = 0, down = 0;
	int tmp_up = 0, tmp_down = 0;
	int result_up = 0, result_down = 1; // 0/1
	int index = 0;
	float tmp_result = .0;
	float result = .0;

	while (1) {
		printf("========== %d번째 입력입니다. ==========\n", index++);
		if (!scanf("%d/%d", &up, &down)) exit(1);

		//합계산
		result_up = result_up * down + up * result_down;
		result_down *= down;

		tmp_up = result_up;
		tmp_down = result_down;

		//약분
		while (tmp_up != tmp_down)
		{
			if (tmp_up > tmp_down)
				tmp_up -= tmp_down;
			else
				tmp_down -= tmp_up;
		}

		result_up /= tmp_up;
		result_down /= tmp_up;

		//연산결과 정수 실수 판단
		if (result_up % result_down == 0) {
			printf("입력한 숫자들의 합입니다. : %d/%d, %d\n", result_up, result_down, result_up / result_down);
		}
		else {
			printf("입력한 숫자들의 합입니다. : %d/%d, %.2f\n", result_up, result_down, (float)result_up / result_down);
		}

		printf("\n");
	}
	return 0;
}