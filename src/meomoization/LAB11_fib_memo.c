#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int num, int *F)
{
	if (num == 1 || num == 2)
		F[num] = 1;

	if (F[num] == 0) //�޸� ����Ǿ� ���� ����
		F[num] = fib(num - 1, F) + fib(num - 2, F);

	return F[num];
}

int main(void)
{
	int num, i;
	int* F;

	printf("�� ��°������ �Ǻ���ġ ����: ");
	scanf("%d", &num);

	F = (int*)malloc(sizeof(int) * (num + 1)); //���ϰ� 1 ~ num (0�� ���¼�)
	if (!F)
		return;

	//F �ʱ�ȭ. ����Ǿ����� ����
	for (i = 0; i <= num; i++)
		F[i] = 0; //�Ǻ���ġ �������� ���� �� ���� ��

	for (i = 1; i <= num; i++)
		printf("%3d", fib(i, F));

	free(F);
}