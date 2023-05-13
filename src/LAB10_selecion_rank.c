#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int partition (int* arr, int p, int r)
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

	//arr[i+1] <-> arr[r]
	tmp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = tmp;

	//arr[r]ÀÇ ÀÚ¸®
	return i + 1;
}

int selection(int* arr, int p, int r, int searchIdx)
{
	if (p <= r) {
		int q = partition(arr, p, r);
		//printf("p = %d q = %d r = %d searchIdx = %d\n", p, q, r, searchIdx);

		if (q == searchIdx)
			return arr[q];

		if (q > searchIdx)
			selection(arr, p, q - 1, searchIdx); //¿ÞÂÊ Àç±Í
		else if (q < searchIdx)
			selection(arr, q + 1, r, searchIdx); //¿À¸¥ÂÊ Àç±Í
	
	}
}

int main(void)
{
	int arr[] = { 31,8,48,73,11,3,20,29,65,15 };
	int order_rank;

	scanf("%d", &order_rank);
	
	printf("%d", selection(arr, 0, 9, order_rank - 1));
}