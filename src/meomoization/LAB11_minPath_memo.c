#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int matrixPath(int** m, int i, int j, int ** minPath)
{
	if (minPath[i][j] == 0) { //�޸� ����Ǿ� ���� �ʴٸ�
		if (i == 0 && j == 0)
			minPath[i][j] = m[i][j];
		else if (i == 0) //���� ����
			minPath[i][j] = matrixPath(m, i, j - 1, minPath) + m[i][j];

		else if (j == 0) //���� ����
			minPath[i][j] = matrixPath(m, i - 1, j, minPath) + m[i][j];

		else {
			int upside = matrixPath(m, i, j - 1, minPath);
			int leftside = matrixPath(m, i - 1, j, minPath);

			if (upside < leftside)
				minPath[i][j] = upside + m[i][j];
			else
				minPath[i][j] = leftside + m[i][j];
		}
	}
	
	return minPath[i][j];
}
int main(void)
{
	int i, j;
	int row, col, x, y;
	int** matrix;
	int** minPath;

	scanf("%d %d", &row, &col);

	//matrix & minPath �����Ҵ�
	matrix = (int**)malloc(sizeof(int*) * row);
	minPath = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * col);
		minPath[i] = (int*)malloc(sizeof(int) * col);
	}
	if (!matrix || !minPath)
		return 0;

	//matrix �Է�, minPath �ʱ�ȭ
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf("%d", &matrix[i][j]);
			minPath[i][j] = 0;
		}
	}
	printf("(x, y): ");
	scanf("%d %d", &x, &y);

	printf("%d\n", matrixPath(matrix, x, y, minPath));

	for (i = 0; i < row; i++) {
		free(matrix[i]);
		free(minPath[i]);
	}
	free(matrix);
	free(minPath);

	return;
}