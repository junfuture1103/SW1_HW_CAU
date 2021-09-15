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
	//numerator - ����
	int numer_a = 0;
	int numer_b = 0;
	//�� ��� ����
	int numer_c = 0;
	//��� ��� ����
	int numer_d = 0;

	//denominator - �и�
	int deno_a = 0;
	int deno_b = 0;
	//�� ��� �и�
	int deno_c = 0;
	//��� ��� �и�
	int deno_d = 0;

	//�м� �Է¹ޱ�
	if(!scanf("%d/%d", &numer_a, &deno_a)) exit(1); //scanf("%s", frac_a);
	if(!scanf("%d/%d", &numer_b, &deno_b)) exit(1);

	//�м� �Է¿Ϸ�
	printf("\n�Էºм� 1 : %d/%d �Էºм� 2 : %d/%d\n\n", numer_a, deno_a, numer_b, deno_b);

	//�հ��
	deno_c = deno_a * deno_b;
	numer_c = numer_a * deno_b + numer_b * deno_a;

	//��� ��
	//printf("%d/%d", numer_c, deno_c);

	//�ִ����� ���ϱ�
	int GCD = getGCD(numer_c, deno_c);
	
	//���
	numer_c /= GCD;
	deno_c /= GCD;

	//��� �� ��
	printf("�� : %d/%d\n", numer_c, deno_c);

	//���
	numer_d = numer_c;
	deno_d = deno_c * 2;

	//�ִ� ����� ���ϱ�
	GCD = getGCD(numer_d, deno_d);

	//���
	numer_d /= GCD;
	deno_d /= GCD;

	//��� �� ���
	printf("��� : %d/%d\n", numer_d, deno_d);

	return 0;
}