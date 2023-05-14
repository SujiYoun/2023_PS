#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printList(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void insertionSort2(int* A, int left, int right)
{
	int i, j, k, temp;

	for (i = left + 1; i <= right; i++) {
		for (j = left; j < i; j++)
			if (A[i] < A[j]) //A[i]���� ū ���� �߰��ϸ� break
				break;

		//A[i] -> A[j]
		temp = A[i];
		//�ڷ� �б�
		for (k = i; k > j; k--)
			A[k] = A[k - 1];
		A[j] = temp;
	}
	return 0;
}

int main(void)
{
	int list[10];
	int n, i, left, right;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	scanf("%d %d", &left, &right);

	insertionSort2(list, left, right);
	printList(list, 10);

	return 0;
}