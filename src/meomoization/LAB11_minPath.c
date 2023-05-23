#define _CRT_SECURE_NO_WARNINGS //Matrix Path Sum의 최소값 출력. memo 없는 버전
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
int matrixPath(int** m, int i, int j)
{
	if (i == 0 && j == 0) //m[0][0]
		return m[i][j];
	else if (i == 0) //위쪽 막힘
		return matrixPath(m, i, j - 1) + m[i][j];
	else if (j == 0) //왼쪽 막힘
		return matrixPath(m, i - 1, j) + m[i][j];
	else {
		int upside = matrixPath(m, i, j - 1); //위쪽으로 오는 경우
		int leftside = matrixPath(m, i - 1, j); //왼쪽으로 오는 경우

		if (upside < leftside)
			return upside + m[i][j];
		else
			return leftside + m[i][j];

		/* 3항 연산자
		return ((a < b) ? a : b) + m[i][j];*/
	}
}
int main(void)
{
	int** m;
	int row, col, i, x, y;

	scanf("%d %d", &row, &col);
	m = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++)
		m[i] = (int*)malloc(sizeof(int) * col);
	if (!m)
		return;

	readMatrix(m, row, col);

	printf("(x, y): ");
	scanf("%d %d", &x, &y);
	
	printf("%d\n", matrixPath(m, x, y));

	for (i = 0; i < row; i++)
		free(m[i]);
	free(m);
}