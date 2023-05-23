#define _CRT_SECURE_NO_WARNINGS //�Ǻ���ġ ���� F(n) ���
#include <stdio.h>
#include <stdlib.h>
int fib(int n, int* F) //����ȭ. �ߺ� ����� ���ϱ� ���� ��� �� �޸� Ȯ��, ��� �� �޸�.
{ //���� �������� �ذ��ϴ� ���
	if (n == 1 || n == 2)
		return 1;

	if (F[n - 1] == 0) //memo���� fn-1Ȯ��, ���� ����� ����
		F[n - 1] = fib(n - 1, F); //��� ȣ��

	if (F[n - 2] == 0) //memo���� fn-2Ȯ��, ���� ����� ����
		F[n - 2] = fib(n - 2, F); //��� ȣ��

	return F[n - 1] + F[n - 2]; //���ϴ� �Ǻ���ġ ��
}
int main(void)
{
	int num, i;
	int* F;

	scanf("%d", &num);
	
	F = (int*)malloc(sizeof(int) * (num + 1)); //index == n �б� ���ϰ�, 1~num ���
	if (!F)
		return 0;

	//F �ʱ�ȭ
	for (i = 0; i <= num; i++)
		F[i] = 0; //����� �� ���� �̷������ �ʾҴ�. 0�� �Ǻ���ġ �������� ���� �� ���� ��

	printf("%d\n", fib(num, F));

	free(F);
	return 0;
}