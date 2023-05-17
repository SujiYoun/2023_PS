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
	int num, digitN, i, reminder;

	scanf("%d", &num);

	reminder = 1;
	while (num > 0) {
		digitN = calDigits(reminder);

		if (num <= digitN) { 
			for (i = 0; i < (digitN - num); i++) //num번째의 숫자를 얻기 위해서 digitN - num만큼 /10후 %10 출력
				reminder /= 10;
			break;
		}
		num -= digitN;
		reminder++;
	}

	printf("%d", reminder % 10);
	return 0;
}