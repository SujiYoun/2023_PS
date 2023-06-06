#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* array, int n)
{
	int i, j, tmp;
	
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				//array[j] <-> array[j+1]
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
		}
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

	bubbleSort(array, num);
	display(array, num);

	free(array);
}