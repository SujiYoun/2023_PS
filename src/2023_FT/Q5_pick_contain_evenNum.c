#define _CRT_SECURE_NO_WARNINGS //10
#include <stdio.h>
#include <stdlib.h>
/*1부터 N까지의 숫자들로 이루어진 수열의 길이 M
이 수열은 최소 L개 이상의 짝수를 포함해야 함. 만들 수 있는 수열의 개수
같은 수 여러번 X, 오름차순
1 < N, M, L < 30*/
void pick(int n, int* picked, int m, int toPick, int l, int tmpCount, int* count)
{
	int lastIndex, smallest, i;
	lastIndex = m - toPick - 1;

	if (toPick == m)
		smallest = 0;
	else {
		smallest = picked[lastIndex] + 1; //조합
		if ((picked[lastIndex] + 1) % 2 == 0)
			tmpCount++;
	}

	if (tmpCount + toPick < l) //앞으로 짝수만 뽑아도 L개 이상의 짝수를 포함할 수 없을 때
		return;

	if (toPick == 0) {
		if (tmpCount < l) //L개 이상의 짝수를 포함하지 않음
			return;

		*count = *count + 1;
		return ;
	}

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			picked[lastIndex + 1] = i;
			pick(n, picked, m, toPick - 1, l, tmpCount, count);
		}
	}
}

void main()
{
	int* picked;
	int n, m, l;
	int count = 0;

	scanf("%d %d %d", &n, &m, &l); //N의 숫자 중에서 만드는 길이 M의 수열에 L개 이상의 짝수가 포함되어있을 경우의 수
	picked = (int*)malloc(sizeof(int) * m);
	if (!picked)
		return;

	pick(n, picked, m, m, l, 0, &count);
	printf("%d", count);

	free(picked);
}