#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int num, int *F)
{ //ū �������� Ȯ��
	if (F[num] == 0) { //�޸� ����Ǿ� ���� ����
		if (num == 1 || num == 2)
			F[num] = 1;

		else
			F[num] = fib(num - 1, F) + fib(num - 2, F); //�޸� ����
	}
	return F[num]; //����� �Ǻ���ġ �� return

	/* ���� �������� Ȯ��
	* if (F[num - 1] == 0)
	*	F[num - 1] = fib(num - 1, F);
	*
	* if (F[num - 2] == 0)
	*	F[num - 2] = fib(num - 2, F);
	*
	* return F[n - 1] + F[n - 2];
	*/
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
		printf("%3d", fib(i, F)); //?? 
	printf("\n");

	free(F);
}