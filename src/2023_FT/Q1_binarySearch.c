#define _CRT_SECURE_NO_WARNINGS //5 -> 10ok
#include <stdio.h>
#include <stdlib.h>
/*M���� ������ �Ȱ� �ִ� ������ �����ϰ��� �ϴ� N���� ���� �� �� ���� �ִ��� ���
ȿ����. ����Ž��*/
void input(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
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
		quickSort(arr, p, q - 1); //���� �κй迭 ����
		quickSort(arr, q + 1, r); //������ �κй迭 ����
	}
}

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

int main(void)
{
	int* items;
	int* bucket;
	int n, m, i, keyIdx;
	int count = 0;

	//��Ʈ���� �Ȱ� �ִ� ����
	scanf("%d", &m); 
	items = (int*)malloc(sizeof(int) * m);
	if (!items)
		return 0;
	input(items, m);

	//�����ϰ��� �ϴ� ����
	scanf("%d", &n); 
	bucket = (int*)malloc(sizeof(int) * n);
	if (!bucket)
		return 0;
	input(bucket, n);

	//����Ž�� : ���ĵ� �迭�� Ž��
	quickSort(items, 0, m - 1);
	for (i = 0; i < n; i++) {
		keyIdx = binary_search(bucket[i], items, 0, m - 1); //����Ž��

		if (keyIdx != -1) { count++; } //�Ȱ������� ī��Ʈ
	}
	printf("%d", count);
	
	free(items);
	free(bucket);
	return 0;
}