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
	int num, digitN, i, reminder;

	scanf("%d", &num);

	reminder = 1;
	while (num > 0) {
		digitN = calDigits(reminder);

		if (num <= digitN) { 
			for (i = 0; i < (digitN - num); i++) //num��°�� ���ڸ� ��� ���ؼ� digitN - num��ŭ /10�� %10 ���
				reminder /= 10;
			break;
		}
		num -= digitN;
		reminder++;
	}

	printf("%d", reminder % 10);
	return 0;
}