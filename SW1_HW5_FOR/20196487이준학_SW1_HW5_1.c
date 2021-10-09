#include <stdio.h>

int main() {
	int up = 0, down = 0;
	int tmp_up=0, tmp_down=0;
	int index = 0;
	float tmp_result = .0;
	float result = .0;

	while (1) {
		printf("========== %d번째 입력입니다. ==========\n", index++);
		if (!scanf("%d/%d", &up, &down)) exit(1);
		tmp_result = (float)up / down;
		result += (float)up / down;

		tmp_up = up;
		tmp_down = down;

		//약분
		while (tmp_up != tmp_down)
		{
			if (tmp_up > tmp_down)
				tmp_up -= tmp_down;
			else
				tmp_down -= tmp_up;
		}
		
		up /= tmp_up;
		down /= tmp_up;

		printf("입력한 숫자의 약분 결과입니다 : %d/%d\n", up, down);
		printf("입력한 숫자의 소수표현입니다 : %.2f\n", tmp_result);

		//연산결과 정수 실수 판단
		if (result-(int)result > 0){
			printf("입력한 숫자들의 합입니다. : %.2f\n", result);
		}
		else {
			printf("입력한 숫자들의 합입니다. : %d\n", (int)result);
		}

		printf("\n");
	}
	return 0;
}