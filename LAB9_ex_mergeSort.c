#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void merge(int* arr, int p, int q, int r, int *tmp)
{
	int i, j, t;

	i = p, j = q + 1, t = p;
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j])
			tmp[t++] = arr[i++];
		else
			tmp[t++] = arr[j++];
	}

	while (i <= q) //j > r
		tmp[t++] = arr[i++];

	while (j <= r) //i > q
		tmp[t++] = arr[j++];

	//บนป็
	for (i = p; i <= r; i++)
		arr[i] = tmp[i];
}

void mergeSort(int* arr, int p, int r, int *tmp)
{
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(arr, p, q, tmp);
		mergeSort(arr, q + 1, r, tmp);
		merge(arr, p, q, r, tmp);
	}
}
int main(void)
{
	int array[] = { 31,3,65,73,8,11,20,29,48,15 };
	int* tmp;

	tmp = (int*)malloc(sizeof(int) * (9 - 0 + 1));
	if (!tmp)
		return;

	printArray(array, 10);
	mergeSort(array, 0, 9, tmp);
	printArray(array, 10);
	
	free(tmp);
}