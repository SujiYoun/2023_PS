#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* arr, int p, int r)
{
	int i, j;
	int tmp;

	i = p - 1;
	for (j = p; j <= r; j++) {
		if (arr[j] < arr[r]) {
			i++;
			//arr[i] <-> arr[j]
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	//arr[i + 1] <-> arr[r]
	tmp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = tmp;

	return i + 1;
}

int selection(int* arr, int p, int r, int searchIdx)
{
	if (p <= r) { //** '='
		int q = partition(arr, p, r);

		if (q == searchIdx)
			return arr[q]; //ã������ ���� ã���� �� �� ��ȯ

		else if (q > searchIdx) 
			selection(arr, p, q - 1, searchIdx); //ã������ �ε����� partition���� ������ ���� ���
		else // q < searchIdx
			selection(arr, q + 1, r, searchIdx); //ũ�� ������ ���
	}
}

int main(void)
{
	int num, rank;
	int* list;

	printf("Enter the number of numbers: ");
	scanf("%d", &num);
	if (num <= 0)
		return 0;

	list = (int*)malloc(sizeof(int) * num);
	if (list == NULL)
		return 0;

	printf("���°�� ���� ��: ");
	scanf("%d", &rank);

	//num���� ���� �߻�
	srand(time(NULL));
	for (int i = 0; i < num; i++)
		list[i] = rand() % 100;
	
	//���� ���
	for (int i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");

	printf("%d��° ���� ���� %d\n", rank, selection(list, 0, 9, rank - 1));

	free(list);
}