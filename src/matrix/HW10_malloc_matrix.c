#define _CRT_SECURE_NO_WARNINGS
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

void matrixTimes(int** a, int** b, int** m, int row, int col) //�̿�
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			m[i][j] += a[i][]
		}
	}
}
int main(void)
{
	int** A, ** B, ** C, ** D;
	int aRow, aCol, bRow, bCol, i, j;

	printf("Enter ��� A�� ��� ���� ����: ");
	scanf("%d %d", &aRow, &aCol);
	printf("Enter ��� B�� ��� ���� ����(B�� ���� %d�̾��): ", aCol);
	scanf("%d %d", &bRow, &bCol);

	//�Ҵ�
	A = (int**)malloc(sizeof(int *) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);

	B = (int**)malloc(sizeof(int*) * bRow);
	for (i = 0; i < bRow; i++)
		B[i] = (int*)malloc(sizeof(int) * bCol);

	C = (int**)malloc(sizeof(int*) * aRow); //A�� B�� ��İ�
	for (i = 0; i < aRow; i++)
		C[i] = (int*)malloc(sizeof(int) * bCol);

	D = (int**)malloc(sizeof(int*) * aCol); //A�� ��ġ���
	for (i = 0; i < aRow; i++)
		D[i] = (int*)malloc(sizeof(int) * aRow);

	//�Է�
	printf("%d x %d ��� A �Է�:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("%d x %d ��� B �Է�:\n", bRow, bCol);
	readMatrix(B, bRow, bCol);

	//��İ�
	for (i = 0; i < aRow; i++) //C �ʱ�ȭ
		for (j = 0; j < bCol; j++)
			C[i][j] = 0;

	printf("��İ�:\n");

	//��ȯ
	for (i = 0; i < aRow; i++)
		free(A[i]);
	free(A);

	for (i = 0; i < bRow; i++)
		free(B[i]);
	free(B);

	for (i = 0; i < bRow; i++)
		free(C[i]);
	free(C);

	for (i = 0; i < bRow; i++)
		free(D[i]);
	free(D);
}