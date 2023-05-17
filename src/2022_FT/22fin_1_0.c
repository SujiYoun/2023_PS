#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
	int num;

	scanf("%d", &num);

	printf("%d", calDigits(num)); //ÀÚ¸®¼ö Ãâ·Â
}
