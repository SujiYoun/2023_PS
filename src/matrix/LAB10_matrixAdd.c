#define _CRT_SECURE_NO_WARNINGS //행렬합_정적할당
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int a[][3])
{
	int i, j;

	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	return;
}

void matrixAdd(int a[][3], int b[][3], int x[][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			x[i][j] = a[i][j] + b[i][j];
		}
	}
	return;
}

void printMatrix(int a[][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int main(void)
{
	int i, j;
	int** A, ** B, ** Sum;

	//동적할당
	A = (int**)malloc(sizeof(int*) * 3);
	B = (int**)malloc(sizeof(int*) * 3);
	Sum = (int**)malloc(sizeof(int*) * 3);
	for (i = 0; i < 3; i++) {
		A[i] = (int*)malloc(sizeof(int) * 3);
		B[i] = (int*)malloc(sizeof(int) * 3);
		Sum[i] = (int*)malloc(sizeof(int) * 3);
	}

	//A값 입력
	printf("(3 x 3) 행렬 A 입력: \n");
	readMatrix(A);
	//B값 입력
	printf("(3 x 3) 행렬 B 입력: \n");
	readMatrix(B);

	//행렬합
	matrixAdd(A, B, Sum);
	printf("행렬합: \n");
	printMatrix(Sum);

	//반환
	for (i = 0; i < 3; i++) {
		free(A[i]);
		free(B[i]);
		free(Sum[i]);
	}
	free(A);
	free(B);
	free(Sum);
}