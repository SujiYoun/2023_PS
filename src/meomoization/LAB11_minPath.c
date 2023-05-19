#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //memo 없는 코드
#include <stdlib.h>

int matrixPath(int** matrix, int i, int j) { //예시코드에서 r, c 인수... 왜?
	if (i == 0 && j == 0) //[0][0]
		return matrix[i][j];

	else if (i == 0) //위쪽 막힘. 
		return matrixPath(matrix, i, j - 1) + matrix[i][j];

	else if (j == 0) //왼쪽 막힘.
		return matrixPath(matrix, i - 1, j) + matrix[i][j];
	
	else {
		int upside = matrixPath(matrix, i - 1, j) + matrix[i][j];
		int leftside = matrixPath(matrix, i, j - 1) + matrix[i][j];

		if (upside < leftside) //점수가 더 적은 쪽을 return
			return upside;
		else
			return leftside;

		/* 3항 연산자
		return ((a < b) ? a : b) + m[i][j];*/
	}

}
int main(void)
{
	int r, c;
	int num1, num2;
	int** matrix;

	scanf("%d %d", &r, &c);

	//matrix 동적할당
	matrix = (int**)malloc(sizeof(int*) * r);
	for (int i = 0; i < r; i++)
		matrix[i] = (int*)malloc(sizeof(int) * c);
	if (matrix == NULL)
		return 0;

	scanf("%d %d", &num1, &num2);

	//matrix 값 입력
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			scanf("%d", &matrix[i][j]);
	}

	printf("%d\n", matrixPath(matrix, 3, 3));

	for (int i = 0; i < r; i++)
		free(matrix[i]); //열 반환
	free(matrix); //행 반환
}