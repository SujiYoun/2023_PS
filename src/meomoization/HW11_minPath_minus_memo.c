#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NOT 0
#define REC 1
void readMatrix(int** mat, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &mat[i][j]);
}
int minPath(int** mat, int i, int j, int** m, int** m1)
{
	if (m1[i][j] != REC) {//== NOT
		if (i == 0 && j == 0)
			m[i][j] = mat[i][j];
		else if (i == 0) //천장이 있다
			m[i][j] = minPath(mat, i, j - 1, m, m1) + mat[i][j];
		else if (j == 0) //왼 벽이 있다
			m[i][j] = minPath(mat, i - 1, j, m, m1) + mat[i][j];
		else {
			int upside = minPath(mat, i - 1, j, m, m1);
			int leftside = minPath(mat, i, j - 1, m, m1);

			if (upside < leftside)
				m[i][j] = upside + mat[i][j];
			else //upside >= leftside
				m[i][j] = leftside + mat[i][j];
		}
		m1[i][j] = REC;
	}

	return m[i][j];
}
int main(void)
{
	int** matrix;
	int** memo;
	int** memo1;
	int row, col, i, j;
	int x, y;

	//할당
	scanf("%d %d", &row, &col);
	matrix = (int**)malloc(sizeof(int*) * row);
	memo = (int**)malloc(sizeof(int*) * row);
	memo1 = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * col);
		memo[i] = (int*)malloc(sizeof(int) * col);
		memo1[i] = (int*)malloc(sizeof(int) * col);
	}
	if (!matrix || !memo || !memo1)
		return;

	//입력 및 초기화
	readMatrix(matrix, row, col);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			memo[i][j] = NOT;

	printf("(x, y): ");
	scanf("%d %d", &x, &y);

	printf("%d", minPath(matrix, x, y, memo, memo1));

	//반환
	for (i = 0; i < row; i++) {
		free(matrix[i]);
		free(memo[i]);
		free(memo1[i]);
	}
	free(matrix);
	free(memo);
	free(memo1);

	return 0;
}