#define _CRT_SECURE_NO_WARNINGS //10
#include <stdio.h>
#include <stdlib.h>
/*�Ǻ���ġ ���� Ȯ��
3-bonacci ����
F(n) = 1 if n = 1 or 2 or 3
	 = F(n - 1) + F(n - 2) + F(n - 3) if n > 3
ȿ����*/
long fib(int num, long* F)
{ //ū �������� Ȯ��
	if (F[num] == 0) { //�޸� ����Ǿ� ���� ����
		if (num == 1 || num == 2 || num == 3)
			F[num] = 1;

		else
			F[num] = fib(num - 1, F) + fib(num - 2, F) + fib(num - 3, F); //�޸� ����
	}
	return F[num]; //����� �Ǻ���ġ �� return
}

int main(void)
{
	int num, i;
	long* F; 

	scanf("%d", &num);

	F = (long*)malloc(sizeof(long) * (num + 1)); //���ϰ� 1 ~ num (0�� ���¼�)
	if (!F)
		return;

	//F �ʱ�ȭ. ����Ǿ����� ����
	for (i = 0; i <= num; i++)
		F[i] = 0; //�Ǻ���ġ �������� ���� �� ���� ��

	printf("%ld", fib(num, F)); //��ȯ�� long����

	free(F);
}