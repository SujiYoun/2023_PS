#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insertion(int* array, int n)
{
	int i, j, k, tmp;

	for (i = 1; i < n; i++) { //i = 1부터 시작
		for (j = 0; j < i; j++) //i - 1까지 비교
			if (array[j] > array[i])
				break;

		//array[j]에 array[i]가 들어가야 함
		tmp = array[i];
		//movement
		for (k = i; k > j; k--) {
			array[k] = array[k - 1];
		}
		//insertion
		array[j] = tmp;
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

	insertion(array, num);
	display(array, num);

	free(array);
}