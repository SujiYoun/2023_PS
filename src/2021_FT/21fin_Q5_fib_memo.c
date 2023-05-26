#define _CRT_SECURE_NO_WARNINGS //�Ǻ���ġ ���� F(1)�� F(0)�� ��� ���
#include <stdio.h> //10ok
#include <stdlib.h>
struct Fibo {
	int num;
	int zero;
	int one;
};

int fib(int n, struct Fibo *F) //return���� ���
{
	if (F[n].num == 0) { //�޸�x
		if (n == 0){
			F[n].num = 1;
			F[n].zero = 1;
		}
		else if (n == 1) {
			F[n].num = 1;
			F[n].one = 1;
		}

		else {
			F[n].num = fib(n - 1, F) + fib(n - 2, F);
			F[n].zero = F[n - 1].zero + F[n - 2].zero;
			F[n].one = F[n - 1].one + F[n - 2].one;
			//printf("num:%d 1:%d 0:%d\n", F[n].num, F[n].one, F[n].zero); ȣ�� Ȯ�ο�
		}
	}
	return F[n].num;
}
int main(void)
{
	int n, i;
	struct Fibo* F;

	scanf("%d", &n);

	F = (struct Fibo*)malloc(sizeof(struct Fibo) * (n + 1)); //0~num
	if (!F)
		return;

	//�ʱ�ȭ
	for (i = 0; i <= n; i++) {
		F[i].num = 0;
		F[i].zero = 0;
		F[i].one = 0;
	}
	F[n].num = fib(n, F); //������� �ڵ�. �Լ�ȣ���� �ؾ��ϳ� F[n].num�� �Լ�ȣ������ �� �̹� �����
	//��� ����

	printf("%d %d", F[n].one, F[n].zero);

	free(F);
	return;
}