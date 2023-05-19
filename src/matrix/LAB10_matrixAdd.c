#define _CRT_SECURE_NO_WARNINGS //�����_�����Ҵ�
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

	//�����Ҵ�
	A = (int**)malloc(sizeof(int*) * 3);
	B = (int**)malloc(sizeof(int*) * 3);
	Sum = (int**)malloc(sizeof(int*) * 3);
	for (i = 0; i < 3; i++) {
		A[i] = (int*)malloc(sizeof(int) * 3);
		B[i] = (int*)malloc(sizeof(int) * 3);
		Sum[i] = (int*)malloc(sizeof(int) * 3);
	}

	//A�� �Է�
	printf("(3 x 3) ��� A �Է�: \n");
	readMatrix(A);
	//B�� �Է�
	printf("(3 x 3) ��� B �Է�: \n");
	readMatrix(B);

	//�����
	matrixAdd(A, B, Sum);
	printf("�����: \n");
	printMatrix(Sum);

	//��ȯ
	for (i = 0; i < 3; i++) {
		free(A[i]);
		free(B[i]);
		free(Sum[i]);
	}
	free(A);
	free(B);
	free(Sum);
}