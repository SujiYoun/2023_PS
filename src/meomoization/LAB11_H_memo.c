#define _CRT_SECURE_NO_WARNINGS //�޸��ִ� ����
#include <stdio.h>
#include <stdlib.h>
int H(int n, int *m)
{ //H(n) = H(0) * H(n-1) + H(1) * H(n-2) +```+ H(n-1) * H(0)
	int total = 0, i;
	if (m[n] == 0) { //�޸� ����Ǿ� ���� ������
		if (n == 0 || n == 1)
			m[n] = 1;

		else { //n > 1
			for (i = 0; i < n; i++)
				total += H(i, m) * H(n - i - 1, m);

			m[n] = total;
		}
	}
	return m[n];
}

int main(void)
{
	int num, i;
	int* memo;

	printf("0���� ū ����: ");
	scanf("%d", &num);

	memo = (int*)malloc(sizeof(int) * (num + 1));
	for (i = 0; i <= num; i++)
		memo[i] = 0;
	printf("����� %d\n", H(num, memo));

	free(memo);
}