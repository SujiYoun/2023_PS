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

void matrixTimes(int** a, int** b, int** m, int row, int col) //미완
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

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);
	printf("Enter 행렬 B의 행과 열의 개수(B의 행은 %d이어야): ", aCol);
	scanf("%d %d", &bRow, &bCol);

	//할당
	A = (int**)malloc(sizeof(int *) * aRow);
	for (i = 0; i < aRow; i++)
		A[i] = (int*)malloc(sizeof(int) * aCol);

	B = (int**)malloc(sizeof(int*) * bRow);
	for (i = 0; i < bRow; i++)
		B[i] = (int*)malloc(sizeof(int) * bCol);

	C = (int**)malloc(sizeof(int*) * aRow); //A와 B의 행렬곱
	for (i = 0; i < aRow; i++)
		C[i] = (int*)malloc(sizeof(int) * bCol);

	D = (int**)malloc(sizeof(int*) * aCol); //A의 전치행렬
	for (i = 0; i < aRow; i++)
		D[i] = (int*)malloc(sizeof(int) * aRow);

	//입력
	printf("%d x %d 행렬 A 입력:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("%d x %d 행렬 B 입력:\n", bRow, bCol);
	readMatrix(B, bRow, bCol);

	//행렬곱
	for (i = 0; i < aRow; i++) //C 초기화
		for (j = 0; j < bCol; j++)
			C[i][j] = 0;

	printf("행렬곱:\n");

	//반환
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