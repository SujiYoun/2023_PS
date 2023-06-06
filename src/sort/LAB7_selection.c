#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* array, int n)
{
	int i, j;
	int max, maxIndex, tmp;

	for (i = 0; i < n - 1; i++) {
		max = array[0];
		maxIndex = 0;

		for (j = 1; j < n - i; j++) {
			if (array[j] > max) {
				max = array[j];
				maxIndex = j;
			}
		}

		//array[maxIndex] <-> array[n - 1 - i]
		tmp = array[n - i - 1];
		array[n - i - 1] = array[maxIndex];
		array[maxIndex] = tmp;

		/*
		array[maxIndex] = array[n - 1 - i];
		array[n - 1 - i] = max;
		*/
	}
}

void display(int* array, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void input(int* array, int size)
{
	int i;
	for (i = 0; i < size; i++)
		scanf("%d", &array[i]);
}

int main(void)
{
	int* array;
	int num;

	scanf("%d", &num);
	array = (int*)malloc(sizeof(int) * num);
	if (!array) {
		printf("error\n");
		return 0;
	}

	input(array, num);

	selectionSort(array, num);
	display(array, num);

	free(array);
}