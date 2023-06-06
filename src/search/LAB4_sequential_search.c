#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sequential_search(int key, int arr[], int low, int high)
{
	int i;
	for (i = low; i <= high; i++)
		if (arr[i] == key)
			return i;
	return 0;
}

int main(void) {
	int array[] = { 2, 6,11,13,18,20,22,27,29,30,34,38,41,42,45,47 };
	int key;

	scanf("%d", &key);
	printf("%d\n", sequential_search(key, array, 0, sizeof(array) / sizeof(int) - 1));
	//high = sizeof(array) / sizeof(int) - 1

	return 0;
}