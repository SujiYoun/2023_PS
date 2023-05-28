#define _CRT_SECURE_NO_WARNINGS //Backpointer. 계산 결과를 구할 때 이전의 중간 결과 중에서 어떤 결과를 선택하였는지 기록
#include <stdio.h>
#include <stdlib.h>
#define UP 2
#define LEFT 1
#define ST 0
void readMatrix(int** mat, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &mat[i][j]);
	return;
}

int matrixPath(int** mat, int i, int j, int** m, int** BP)
{
	if (BP[i][j] != ST && BP[i][j] != UP && BP[i][j] != LEFT) { //BP[i][j] == -1 
		if (i == 0 && j == 0) {
			m[i][j] = mat[i][j];
			BP[i][j] = ST;
		}
		else if (i == 0) { //천장
			m[i][j] = matrixPath(mat, i, j - 1, m, BP) + mat[i][j];
			BP[i][j] = LEFT;
		}
		else if (j == 0) { //왼 벽
			m[i][j] = matrixPath(mat, i - 1, j, m, BP) + mat[i][j];
			BP[i][j] = UP;
		}
		else {
			int upside = matrixPath(mat, i - 1, j, m, BP);
			int leftside = matrixPath(mat, i, j - 1, m, BP);

			if (upside < leftside) {
				m[i][j] = upside + mat[i][j];
				BP[i][j] = UP;
			}
			else { //upside >= leftside
				m[i][j] = leftside + mat[i][j];
				BP[i][j] = LEFT;
			}
		}
	}

	return m[i][j];
}

void print_path(int i, int j, int** BP)
{
	if (BP[i][j] < ST)
		return;
	else if (BP[i][j] == UP) {
		print_path(i - 1, j, BP);
	}
	else { // (BP[i][j] = LEFT)
		print_path(i, j - 1, BP);
	}

	printf("<%d, %d> ", i, j);
}
int main(void)
{
	int** matrix;
	int** memo;
	int** BP;
	int row, col, i, j;
	int x, y;

	//할당
	scanf("%d %d", &row, &col);
	matrix = (int**)malloc(sizeof(int*) * row);
	memo = (int**)malloc(sizeof(int*) * row);
	BP = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * col);
		memo[i] = (int*)malloc(sizeof(int) * col);
		BP[i] = (int*)malloc(sizeof(int) * col);
	}
	if (!matrix || !memo || !BP)
		return 0;

	readMatrix(matrix, row, col);
	//BP 초기화.
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			BP[i][j] = -1;  //BP에 들어가는 값은 0, 1, 2

	printf("x, y : ");
	scanf("%d %d", &x, &y);
	printf("%d\n", matrixPath(matrix, x, y, memo, BP));

	print_path(x, y, BP);

	//반환
	for (i = 0; i < row; i++) {
		free(matrix[i]);
		free(memo[i]);
		free(BP[i]);
	}
	free(memo);
	free(matrix);
	free(BP);
}