#define _CRT_SECURE_NO_WARNINGS//... -> 10ok
#include <stdio.h>
#include <stdlib.h>
/*���ڿ� ����
* �빮�� ���ĺ� ������������ ����, �ҹ��� ����, ���� ����
* �빮�� / �ҹ��� / ����
* ���ڿ� �ִ� ���� 500000
ȿ����, ���� ����*/
void printword(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		printf("%c", s[i]);
	printf("\n");
}
int partitionDescending(char* arr, int p, int r) //�������� ����
{
	int i, j;
	char tmp;
	i = p - 1;
	for (j = p; j <= r; j++) {
		if (arr[j] > arr[r]) {
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
void quickSortDescending(char* arr, int p, int r)
{
	if (p < r) {
		int q = partitionDescending(arr, p, r);
		quickSortDescending(arr, p, q - 1); //���� �κй迭 ����
		quickSortDescending(arr, q + 1, r); //������ �κй迭 ����
	}
}

int partitionAscending(char* arr, int p, int r) //�������� ����
{
	int i, j;
	char tmp;
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
void quickSortAscending(char* arr, int p, int r)
{
	if (p < r) {
		int q = partitionAscending(arr, p, r);
		quickSortAscending(arr, p, q - 1); //���� �κй迭 ����
		quickSortAscending(arr, q + 1, r); //������ �κй迭 ����
	}
}

int main(void)
{
	char word[500000];
	int i,length;
	int numPartition;

	scanf("%s", word);
	for (i = 0; word[i] != '\0'; i++);
	length = i;
	
	//����ҹ���(65 ~ 90 / 97 ~ 122) // ���� (48 ~ 57)
	quickSortDescending(word, 0, length - 1);

	for (i = 0; word[i] > '9'; i++);
	numPartition = i; //word[i]���� ����
	quickSortAscending(word, 0, numPartition - 1); //���� ����

	quickSortAscending(word, numPartition, length - 1); //���� ����
	printword(word);
}