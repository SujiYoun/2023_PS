#define _CRT_SECURE_NO_WARNINGS //행렬곱_동적할당
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
				c[i][j] += (a[i][k] * b[k][j]); //A의 i행 * B의 j열의 합
		}
	}
	return;
}
int main(void)
{
	int** A, ** B, ** C, ** D;
	int aRow, aCol, bRow, bCol, i, j;

	printf("Enter 행렬 A의 행과 열의 개수: "); //r행 c열
	scanf("%d %d", &aRow, &aCol);
	printf("Enter 행렬 B의 행과 열의 개수(B의 행은 %d이어야): ", aCol); //A의 열 개수 == B의 행의 개수
	scanf("%d %d", &bRow, &bCol); //aCol == bRow

	//할당
	A = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);

	B = (int**)malloc(sizeof(int*) * bRow);
	for (i = 0; i < bRow; i++)
		B[i] = (int*)malloc(sizeof(int) * bCol); //== aRow

	C = (int**)malloc(sizeof(int*) * aRow); //A와 B의 행렬곱. A의 행과 B의 열
	for (i = 0; i < aRow; i++)
		C[i] = (int*)malloc(sizeof(int) * bCol);

	D = (int**)malloc(sizeof(int*) * aCol); //A의 전치행렬
	for (i = 0; i < aCol; i++)
		D[i] = (int*)malloc(sizeof(int) * aRow);
	if (!A || !B || !C || !D)
		return;

	//입력
	printf("%d x %d 행렬 A 입력:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("\n%d x %d 행렬 B 입력:\n", aCol, bCol); //aCol == bRow
	readMatrix(B, aCol, bCol);

	//행렬곱
	for (i = 0; i < aRow; i++) //C 초기화
		for (j = 0; j < bCol; j++)
			C[i][j] = 0;

	printf("\n행렬곱:\n");
	matrixTimes(A, B, C, aRow, bCol, aCol); //aCol == bRow
	printMatrix(C, aRow, bCol);

	//전치행렬
	printf("\n전치행렬:\n");
	for (i = 0; i < aRow; i++)
		for (j = 0; j < aCol; j++)
			D[j][i] = A[i][j];
	printMatrix(D, aCol, aRow);

	//반환
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