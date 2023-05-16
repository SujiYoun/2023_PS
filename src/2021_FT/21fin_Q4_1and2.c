#define _CRT_SECURE_NO_WARNINGS //8ok
#include <stdio.h>
#include <stdlib.h>

void pick(int item[], int n, int* picked, int m, int toPick, int* sum_num)
{
	int i, j, smallest, lastIndex;
	int sum;

	if (toPick == 0) {
		sum = 0;
		for (i = 0; i < m; i++) {
			//printf("%d", picked[i]);
			sum += item[picked[i]];
		}

		if (sum == m && sum != 0) { //뽑은 1, 2의 합이 num과 같으면 picked안에 0뿐이면 0출력
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
			picked[lastIndex + 1] = i;

			//여기서 sum_num에 들어있는 건 주소값
			pick(item, n, picked, m, toPick - 1, sum_num);
		}
	}
}
int main(void)
{
	int item[] = { 1, 2, 0 };
	int* picked;
	int num, sum_num = 0;

	scanf("%d", &num);
	picked = (int*)malloc(sizeof(int) * num);
	if (picked == NULL)
		return 0;

	//주소값 넘겨주기
	pick(item, 3, picked, num, num, &sum_num);
	printf("%d", sum_num);

	free(picked);
	return 0;
}