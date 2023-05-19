#define _CRT_SECURE_NO_WARNINGS //�����_�����Ҵ�
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int** a, int row, int col) //**2���� �迭 ������ �ѱ��
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			scanf("%d", &a[i][j]);
	return;
}

void printMatrix(int** a, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void matrixAdd(int **a, int **b, int **x, int row, int col)
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			x[i][j] = a[i][j] + b[i][j];
		}
	}
	return;
}

int main(void)
{
	int** A, ** B;
	int** X; //A + B
	int aRow, aCol;
	int i, j;

	printf("Enter ��� A�� ��� ���� ����: ");
	scanf("%d %d", &aRow, &aCol);

	//�������� ��� A(aRow x aCol), B(aRow x aCol), X(aRow x aCol) ����
	A = (int**)malloc(sizeof(int*) * aRow);
	B = (int**)malloc(sizeof(int*) * aRow);
	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < 3; i++) {
		A[i] = (int*)malloc(sizeof(int) * aCol);
		B[i] = (int*)malloc(sizeof(int) * aCol);
		X[i] = (int*)malloc(sizeof(int) * aCol);
	}

	//A B ��İ� �Է�
	printf("(3 x 3) ��� A �Է�: \n");
	readMatrix(A, aRow, aCol);

	printf("(3 x 3) ��� B �Է�: \n");
	readMatrix(B, aRow, aCol);

	//X ��� �ʱ�ȭ
	for (i = 0; i < aRow; i++)
		for (j = 0; j < aCol; j++)
			X[i][j] = 0;

	//�����
	matrixAdd(A, B, X, aRow, aCol);
	printf("�����:\n");
	printMatrix(X, aRow, aCol);

	//��ȯ
	for (i = 0; i < 3; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A);
	free(B);
	free(X);
}