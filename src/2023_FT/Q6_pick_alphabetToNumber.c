#define _CRT_SECURE_NO_WARNINGS///... -> 10
#include <stdio.h>
#include <stdlib.h>
/*두 문자열의 최대 합
A, B, C, D, E에 숫자 1~5를 대입하여 문자열을 숫자로 변환한 후 그의 합 출력
문자열 길이 최대 8*/
void pick(char s1[], char s2[], int n, int* picked, int m, int toPick, int *max)
{
	int lastIndex, smallest, i, j;
	lastIndex = m - toPick - 1;

	smallest = 0; //순열

	if (toPick == 0) {
		int tmp1 = 0, tmp2 = 0;
		for (i = 0; s1[i] != '\0'; i++) {
			tmp1 *= 10;
			tmp1 += picked[s1[i] - 'A'] + 1;

		}

		for (i = 0; s2[i] != '\0'; i++) {
			tmp2 *= 10;
			tmp2 += picked[s2[i] - 'A'] + 1;
		}

		//printf("%d + %d = %d\n", tmp1, tmp2, tmp1 + tmp2);

		if (tmp1 + tmp2 > *max)
			*max = tmp1 + tmp2;

		return;
	}

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			int flag = 0;
			for (j = 0; j <= lastIndex; j++) //순열. 뽑았는지 확인
				if (i == picked[j])
					flag = 1;

			if (flag == 1)
				continue;

			picked[lastIndex + 1] = i;
			pick(s1, s2, n, picked, m, toPick - 1, max);
		}
	}
}
void main()
{
	char s1[8];
	char s2[8];
	int tmp1, tmp2;
	int code[5];
	int i, s1Len, s2Len;
	int max = -1;

	scanf("%s", s1);
	scanf("%s", s2);

	for (i = 0; s1[i] != '\0'; i++);
	s1Len = i;
	for (i = 0; s2[i] != '\0'; i++);
	s2Len = i;

	pick(s1, s2, 5, code, 5, 5, &max);	
	printf("%d", max);
}
