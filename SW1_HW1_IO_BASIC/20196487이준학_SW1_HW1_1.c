#include <stdio.h>

int getGCD(int n1, int n2) {
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	return n1;
}

int main() {
	//numerator - 분자
	int numer_a = 0;
	int numer_b = 0;
	//합 결과 분자
	int numer_c = 0;
	//평균 결과 분자
	int numer_d = 0;

	//denominator - 분모
	int deno_a = 0;
	int deno_b = 0;
	//합 결과 분모
	int deno_c = 0;
	//평균 결과 분모
	int deno_d = 0;

	//분수 입력받기
	if(!scanf("%d/%d", &numer_a, &deno_a)) exit(1); //scanf("%s", frac_a);
	if(!scanf("%d/%d", &numer_b, &deno_b)) exit(1);

	//분수 입력완료
	printf("\n입력분수 1 : %d/%d 입력분수 2 : %d/%d\n\n", numer_a, deno_a, numer_b, deno_b);

	//합계산
	deno_c = deno_a * deno_b;
	numer_c = numer_a * deno_b + numer_b * deno_a;

	//약분 전
	//printf("%d/%d", numer_c, deno_c);

	//최대공약수 구하기
	int GCD = getGCD(numer_c, deno_c);
	
	//약분
	numer_c /= GCD;
	deno_c /= GCD;

	//약분 후 합
	printf("합 : %d/%d\n", numer_c, deno_c);

	//평균
	numer_d = numer_c;
	deno_d = deno_c * 2;

	//최대 공약수 구하기
	GCD = getGCD(numer_d, deno_d);

	//약분
	numer_d /= GCD;
	deno_d /= GCD;

	//약분 후 평균
	printf("평균 : %d/%d\n", numer_d, deno_d);

	return 0;
}