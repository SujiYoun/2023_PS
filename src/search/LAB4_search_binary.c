#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int binary_search(int key, int arr[], int low, int high) //loop
{
	int middle;

	while (low <= high) {
		middle = (low + high) / 2;
		if (arr[middle] == key)
			return middle;
		else if (arr[middle] > key)
			high = middle - 1;
		else //arr[middle] < key
			low = middle + 1;
	}
	return -1;
}

int main(void) {
	int array[] = { 2, 6,11,13,18,20,22,27,29,30,34,38,41,42,45,47 };
	int key;

	scanf("%d", &key);
	printf("%d\n", binary_search(key, array, 0, 16));
	return 0;
}