#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //memo ���� �ڵ�
#include <stdlib.h>

int matrixPath(int** matrix, int i, int j) { //�����ڵ忡�� r, c �μ�... ��?
	if (i == 0 && j == 0) //[0][0]
		return matrix[i][j];

	else if (i == 0) //���� ����. 
		return matrixPath(matrix, i, j - 1) + matrix[i][j];

	else if (j == 0) //���� ����.
		return matrixPath(matrix, i - 1, j) + matrix[i][j];
	
	else {
		int upside = matrixPath(matrix, i - 1, j) + matrix[i][j];
		int leftside = matrixPath(matrix, i, j - 1) + matrix[i][j];

		if (upside < leftside) //������ �� ���� ���� return
			return upside;
		else
			return leftside;

		/* 3�� ������
		return ((a < b) ? a : b) + m[i][j];*/
	}

}
int main(void)
{
	int r, c;
	int num1, num2;
	int** matrix;

	scanf("%d %d", &r, &c);

	//matrix �����Ҵ�
	matrix = (int**)malloc(sizeof(int*) * r);
	for (int i = 0; i < r; i++)
		matrix[i] = (int*)malloc(sizeof(int) * c);
	if (matrix == NULL)
		return 0;

	scanf("%d %d", &num1, &num2);

	//matrix �� �Է�
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			scanf("%d", &matrix[i][j]);
	}

	printf("%d\n", matrixPath(matrix, 3, 3));

	for (int i = 0; i < r; i++)
		free(matrix[i]); //�� ��ȯ
	free(matrix); //�� ��ȯ
}