#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int matrixPath(int** matrix, int i, int j)
{

}
int main(void)
{
	int i, j;
	int row, col, num1, num2;
	int** matrix;
	int** memo;

	scanf("%d %d", &row, &col);
	//matrix & memo 동적할당
	matrix = (int**)malloc(sizeof(int*) * row);
	memo = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * col);
		memo[i] = (int*)malloc(sizeof(int) * col);
	}
	if (!matrix || !memo)
		return 0;

	//matrix 입력, memo 초기화
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf("%d", &matrix[i][j]);
			memo[i][j] = 0;
		}
	}

	scanf("%d %d", &num1, &num2);
}