#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int calDigits(int num) //�ڸ��� ��ȯ
{
	int count;

	count = 0;
	while (num != 0) {
		num /= 10;
		count++;
	}

	return count;
}

int main(void)
{
	int num, digitN, i;

	scanf("%d", &num);

	digitN = 0;
	for (i = 1; i <= num; i++) { //1���� num���� �̾����� ���� �ڸ��� ���
		digitN += calDigits(i);
	}

	printf("%d", digitN);
}