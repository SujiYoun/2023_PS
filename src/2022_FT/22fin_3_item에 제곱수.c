#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> //�ڿ��� N�� N���� �۰ų� ���� ���� ���������� ������. ���� ���� �ּڰ�
#include <stdlib.h> //10ok
void pick(int items[], int n, int* picked, int m, int toPick, int temp, int* min)
{
	int lastIndex, smallest, i;
	
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else {
		smallest = picked[lastIndex]; //�ߺ� ����
		temp += items[picked[lastIndex]]; //�߰����
	}
	
	//ȿ����
	if (temp > m)
		return;
	if (temp == m) { //���� ����
		for (i = 0; i <= lastIndex; i++)
			printf("%d ", items[picked[i]]);
		printf("\n");

		if (lastIndex + 1 < *min || *min == 0) //���� ������ min���� ������. ù ��° ���� ��
			*min = lastIndex + 1;
		return;
	}

	if (*min != 0 && lastIndex + 1 > *min) //ù��° �̴� �� �ƴ� �� ���� ������ min���� ũ��
		return;

	if (toPick == 0)
		return;

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			picked[lastIndex + 1] = i;
			pick(items, n, picked, m, toPick - 1, temp, min);
		}
	}
}

int main(void)
{
	int* items;
	int* picked;
	int num, i, size;
	int min = 0;

	scanf("%d", &num);
	//items ũ��
	size = 0;
	while ((size + 1) * (size + 1) < num) {
		size++;
	}

	items = (int*)malloc(sizeof(int) * size);
	picked = (int*)malloc(sizeof(int) * num);
	if (!items || !picked)
		return;

	//items �� �ֱ� - ū ������
	for (i = size - 1; i >= 0; i--)
		items[size - i - 1] = (i + 1) * (i + 1);

	pick(items, size, picked, num, num, 0, &min);
	printf("%d", min);

	free(items);
	free(picked);
}