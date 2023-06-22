#define _CRT_SECURE_NO_WARNINGS//... -> 10ok
#include <stdio.h>
#include <stdlib.h>
/*문자열 정렬
* 대문자 알파벳 오름차순으로 정렬, 소문자 정렬, 숫자 정렬
* 대문자 / 소문자 / 숫자
* 문자열 최대 길이 500000
효율성, 빠른 정렬*/
void printword(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		printf("%c", s[i]);
	printf("\n");
}
int partitionDescending(char* arr, int p, int r) //내림차순 정렬
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
		quickSortDescending(arr, p, q - 1); //왼쪽 부분배열 정렬
		quickSortDescending(arr, q + 1, r); //오른쪽 부분배열 정렬
	}
}

int partitionAscending(char* arr, int p, int r) //오름차순 정렬
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
		quickSortAscending(arr, p, q - 1); //왼쪽 부분배열 정렬
		quickSortAscending(arr, q + 1, r); //오른쪽 부분배열 정렬
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
	
	//영대소문자(65 ~ 90 / 97 ~ 122) // 숫자 (48 ~ 57)
	quickSortDescending(word, 0, length - 1);

	for (i = 0; word[i] > '9'; i++);
	numPartition = i; //word[i]부터 숫자
	quickSortAscending(word, 0, numPartition - 1); //영어 정렬

	quickSortAscending(word, numPartition, length - 1); //숫자 정렬
	printword(word);
}