#define _CRT_SECURE_NO_WARNINGS//...
#include <stdio.h>	
#include <stdlib.h>
/*�Ǻ���ġ ���� Ȯ��
k-bonacci
F(n) = 1 if n <= k
	 = F(n - 1) + F(n - 2) + ... + F[n - k + 1) + F(n - k) if n > k
ȿ����*/
long kFib(int num, int k, long* F)
{
	int i;
	if (F[num] == 0) { //�޸� ����Ǿ� ���� ����
		if (num <= k)
			F[num] = 1;

		else {
			for (i = 1; i <= k; i++)
				F[num] += kFib(num - i, k, F);
		}
	}
	return F[num]; //����� �Ǻ���ġ �� return
}
int main(void)
{
	int n, k, i;
	long* F;

	scanf("%d %d", &n, &k);

	F = (long*)malloc(sizeof(long) * (n + 1)); //���ϰ� 1 ~ num (0�� ���¼�)
	if (!F)
		return;

	//F �ʱ�ȭ. ����Ǿ����� ����
	for (i = 0; i <= n; i++)
		F[i] = 0; //�Ǻ���ġ �������� ���� �� ���� ��

	printf("%ld", kFib(n, k, F)); //��ȯ�� long����
	free(F);
}