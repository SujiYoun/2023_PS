#define _CRT_SECURE_NO_WARNINGS //9ok
#include <stdio.h>
#include <stdlib.h>

void pick(int items[], int n, int* picked, int m, int toPick, int tmpSum, int* sum_num)
{
	int i, j, smallest, lastIndex;

	if (toPick == 0) {
		/*sum = 0;
		for (i = 0; i < m; i++) {
			//printf("%d", picked[i]);
			sum += items[picked[i]];
		}*/

		tmpSum += items[picked[m - 1]]; //���������� ���� ��

		if (tmpSum == m) { //���� 1, 2�� ���� num�� ������
			*sum_num = *sum_num + 1; //* �ٿ��� sum_num ���� ���� ����
		}
	}


	//�ߺ� ����
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	//**�߰� ��� - ��½ð� ���̱�
	if (lastIndex > -1)
		tmpSum += items[picked[lastIndex]];

	if (tmpSum > m) //���ݱ��� ���� ���� ���� m�� ������ ��� ȣ�� �� �ʿ�x.
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
	int items[] = { 2, 1, 0 };
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