#define _CRT_SECURE_NO_WARNINGS //��İ�_�����Ҵ�
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int** m, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &m[i][j]);
	return;
}

void printMatrix(int** a, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void matrixTimes(int** a, int** b, int** c, int mRow, int mCol, int aRow)
{
	int i, j, k;
	for (i = 0; i < mRow; i++) {
		for (j = 0; j < mCol; j++) {
			for (k = 0; k < aRow; k++) //aRow == bCol
				c[i][j] += (a[i][k] * b[k][j]); //A�� i�� * B�� j���� ��
		}
	}
	return;
}
int main(void)
{
	int** A, ** B, ** C, ** D;
	int aRow, aCol, bRow, bCol, i, j;

	printf("Enter ��� A�� ��� ���� ����: "); //r�� c��
	scanf("%d %d", &aRow, &aCol);
	printf("Enter ��� B�� ��� ���� ����(B�� ���� %d�̾��): ", aCol); //A�� �� ���� == B�� ���� ����
	scanf("%d %d", &bRow, &bCol); //aCol == bRow

	//�Ҵ�
	A = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);

	B = (int**)malloc(sizeof(int*) * bRow);
	for (i = 0; i < bRow; i++)
		B[i] = (int*)malloc(sizeof(int) * bCol); //== aRow

	C = (int**)malloc(sizeof(int*) * aRow); //A�� B�� ��İ�. A�� ��� B�� ��
	for (i = 0; i < aRow; i++)
		C[i] = (int*)malloc(sizeof(int) * bCol);

	D = (int**)malloc(sizeof(int*) * aCol); //A�� ��ġ���
	for (i = 0; i < aCol; i++)
		D[i] = (int*)malloc(sizeof(int) * aRow);
	if (!A || !B || !C || !D)
		return;

	//�Է�
	printf("%d x %d ��� A �Է�:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("\n%d x %d ��� B �Է�:\n", aCol, bCol); //aCol == bRow
	readMatrix(B, aCol, bCol);

	//��İ�
	for (i = 0; i < aRow; i++) //C �ʱ�ȭ
		for (j = 0; j < bCol; j++)
			C[i][j] = 0;

	printf("\n��İ�:\n");
	matrixTimes(A, B, C, aRow, bCol, aCol); //aCol == bRow
	printMatrix(C, aRow, bCol);

	//��ġ���
	printf("\n��ġ���:\n");
	for (i = 0; i < aRow; i++)
		for (j = 0; j < aCol; j++)
			D[j][i] = A[i][j];
	printMatrix(D, aCol, aRow);

	//��ȯ
	for (i = 0; i < aRow; i++)
		free(A[i]);
	free(A);
	for (i = 0; i < aCol; i++) ////aCol == bRow
		free(B[i]);
	free(B);
	for (i = 0; i < aRow; i++)
		free(C[i]);
	free(C);
	for (i = 0; i < aCol; i++)
		free(D[i]);
	free(D);
}