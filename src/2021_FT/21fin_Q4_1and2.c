#define _CRT_SECURE_NO_WARNINGS //10ok
#include <stdio.h>
#include <stdlib.h>

void pick(int items[], int n, int* picked, int m, int toPick, int tmpSum, int* sum_num)
{
	int i, j, smallest, lastIndex;

	//�ߺ� ����
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	//**�߰� ��� - ��½ð� ���̱�
	//0���� �̱�!!***
	if (lastIndex > -1)
		tmpSum += items[picked[lastIndex]];

	if (tmpSum > m) //���ݱ��� ���� ���� ���� m�� ������ ��� ȣ�� �� �ʿ�x.
		return;
	
	if (tmpSum == m) { //�߰��� �� �̾���
		for (i = 0; i <= lastIndex ; i++)
			printf("%d ", items[picked[i]]);
		printf("\n");
		*sum_num = *sum_num + 1;
		return;
	}

	if (toPick == 0) //�� �ڿ�
		return;

	if (toPick > 0) {
		for (i = smallest; i < n; i++) { //�ݺ��� �ȿ��� �߰���� x
			picked[lastIndex + 1] = i;

			//���⼭ sum_num�� ����ִ� �� �ּҰ�
			pick(items, n, picked, m, toPick - 1, tmpSum, sum_num);
		}
	}
}
int main(void)
{
	int items[] = { 2, 1 };
	int* picked;
	int num, sum_num = 0; //�������� ���x

	scanf("%d", &num);
	if (num < 1 || num > 900)
		return 0;

	picked = (int*)malloc(sizeof(int) * num);
	if (picked == NULL)
		return 0;

	//�ּҰ� �Ѱ��ֱ�
	pick(items, 3, picked, num, num, 0, &sum_num);
	printf("%d", sum_num);

	free(picked);
	return 0;
}