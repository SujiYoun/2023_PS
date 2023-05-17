#define _CRT_SECURE_NO_WARNINGS //8ok why?????????????????????
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int* picked, int m, int toPick, int* sum_num)
{
	int i, j, smallest, lastIndex;
	int sum;

	if (toPick == 0) {
		sum = 0;
		for (i = 0; i < m; i++) {
			//printf("%d", picked[i]);
			sum += picked[i];
		}

		if (sum == m) { //뽑은 1, 2의 합이 num과 같으면
			/*for (i = 0; i < m; i++)
				printf("%d", item[picked[i]]);
			printf("\n");*/

			//* 붙여야 sum_num 값에 접근 가능
			*sum_num = *sum_num + 1;
		}
	}

	//중복 조합
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			sum = 0;
			for (j = 0; j <= lastIndex; j++)
				sum += picked[j];

			if (sum + i > m)
				continue;

			picked[lastIndex + 1] = i;

			//여기서 sum_num에 들어있는 건 주소값
			pick(n, picked, m, toPick - 1, sum_num);
		}
	}
}
int main(void)
{
	int* picked;
	int num, sum_num = 0;

	scanf("%d", &num);
	if (num < 1 || num > 900)
		return 0;

	picked = (int*)malloc(sizeof(int) * num);
	if (picked == NULL)
		return 0;

	//주소값 넘겨주기
	pick(3, picked, num, num, &sum_num);
	printf("%d", sum_num);

	free(picked);
	return 0;
}