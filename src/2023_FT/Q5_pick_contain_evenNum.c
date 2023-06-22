#define _CRT_SECURE_NO_WARNINGS //10
#include <stdio.h>
#include <stdlib.h>
/*1���� N������ ���ڵ�� �̷���� ������ ���� M
�� ������ �ּ� L�� �̻��� ¦���� �����ؾ� ��. ���� �� �ִ� ������ ����
���� �� ������ X, ��������
1 < N, M, L < 30*/
void pick(int n, int* picked, int m, int toPick, int l, int tmpCount, int* count)
{
	int lastIndex, smallest, i;
	lastIndex = m - toPick - 1;

	if (toPick == m)
		smallest = 0;
	else {
		smallest = picked[lastIndex] + 1; //����
		if ((picked[lastIndex] + 1) % 2 == 0)
			tmpCount++;
	}

	if (tmpCount + toPick < l) //������ ¦���� �̾Ƶ� L�� �̻��� ¦���� ������ �� ���� ��
		return;

	if (toPick == 0) {
		if (tmpCount < l) //L�� �̻��� ¦���� �������� ����
			return;

		*count = *count + 1;
		return ;
	}

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			picked[lastIndex + 1] = i;
			pick(n, picked, m, toPick - 1, l, tmpCount, count);
		}
	}
}

void main()
{
	int* picked;
	int n, m, l;
	int count = 0;

	scanf("%d %d %d", &n, &m, &l); //N�� ���� �߿��� ����� ���� M�� ������ L�� �̻��� ¦���� ���ԵǾ����� ����� ��
	picked = (int*)malloc(sizeof(int) * m);
	if (!picked)
		return;

	pick(n, picked, m, m, l, 0, &count);
	printf("%d", count);

	free(picked);
}