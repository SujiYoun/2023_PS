#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //1부터 n까지의 수를 이어서 쓴 수의 자릿수 구하기
int calDigits(int num) //자리수 반환
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
	for (i = 1; i <= num; i++) { //1부터 num까지 이어지는 수의 자리수 계산
		digitN += calDigits(i);
	}

	printf("%d", digitN);
}