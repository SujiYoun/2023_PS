#define _CRT_SECURE_NO_WARNINGS //행렬합_동적할당
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int** a, int row, int col) //**2차원 배열 포인터 넘기기
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

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);

	//동적으로 행렬 A(aRow x aCol), B(aRow x aCol), X(aRow x aCol) 생성
	A = (int**)malloc(sizeof(int*) * aRow);
	B = (int**)malloc(sizeof(int*) * aRow);
	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < 3; i++) {
		A[i] = (int*)malloc(sizeof(int) * aCol);
		B[i] = (int*)malloc(sizeof(int) * aCol);
		X[i] = (int*)malloc(sizeof(int) * aCol);
	}

	//A B 행렬값 입력
	printf("(3 x 3) 행렬 A 입력: \n");
	readMatrix(A, aRow, aCol);

	printf("(3 x 3) 행렬 B 입력: \n");
	readMatrix(B, aRow, aCol);

	//X 행렬 초기화
	for (i = 0; i < aRow; i++)
		for (j = 0; j < aCol; j++)
			X[i][j] = 0;

	//행렬합
	matrixAdd(A, B, X, aRow, aCol);
	printf("행렬합:\n");
	printMatrix(X, aRow, aCol);

	//반환
	for (i = 0; i < 3; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A);
	free(B);
	free(X);
}