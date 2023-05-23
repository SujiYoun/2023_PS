#define _CRT_SECURE_NO_WARNINGS //������ �� memo�ִ� ����
#include <stdio.h>
#include <stdlib.h>
int comb(int n, int r, int **m)
{
	if (m[n][r] == 0) { //�޸� ����Ǿ� ���� ������
		if (r == 0 || r == n)
			m[n][r] = 1;
		else
			m[n][r] = comb(n - 1, r - 1, m) + comb(n - 1, r, m);
	}
	return m[n][r];
}
int main(void)
{
	int C;
	int** memo;
	int n, r, i, j;

	scanf("%d %d", &n, &r);

	memo = (int**)malloc(sizeof(int*) * (n + 1)); //1~n
	for (i = 0; i <= n; i++)
		memo[i] = (int*)malloc(sizeof(int) * (r + 1)); // 1~r

	//memo �ʱ�ȭ
	for (i = 0; i <= n; i++)
		for (j = 0; j <= r; j++)
			memo[i][j] = 0;

	C = comb(n, r, memo); //nCr

	printf("%d", C);

	for (i = 0; i <= n; i++)
		free(memo[i]);
	free(memo);
	return 0;
}