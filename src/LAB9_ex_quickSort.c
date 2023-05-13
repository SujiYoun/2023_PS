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
int partition(int* arr, int p, int r)
{
	int i, j, tmp;
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
void quickSort(int* arr, int p, int r)
{
	if (p < r) {
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1); //왼쪽 부분배열 정렬
		quickSort(arr, q + 1, r); //오른쪽 부분배열 정렬
	}
}

int main(void)
{
	int array[] = { 31, 8, 48, 73, 11, 3, 20, 29, 65, 15 };
	int* tmp;

	tmp = (int*)malloc(sizeof(int) * (9 - 0 + 1));
	if (!tmp)
		return;

	printArray(array, 10);
	quickSort(array, 0, 9, tmp);
	printArray(array, 10);
	
	free(tmp);
}