#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> //자연수 N을 N보다 작거나 같은 수의 제곱수들의 합으로. 항의 개수 최솟값
#include <stdlib.h> //10ok
void pick(int items[], int n, int* picked, int m, int toPick, int temp, int* min)
{
	int lastIndex, smallest, i;
	
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else {
		smallest = picked[lastIndex]; //중복 조합
		temp += items[picked[lastIndex]] * items[picked[lastIndex]]; //중간계산
	}
	
	//효율성
	if (temp > m)
		return;
	if (temp == m) { //조건 충족
		for (i = 0; i <= lastIndex; i++)
			printf("%d ", items[picked[i]]);
		printf("\n");

		if (lastIndex + 1 < *min || *min == -1) //뽑은 갯수가 min보다 작으면, 첫 번째 뽑을 때
			*min = lastIndex + 1;
		return;
	}

	if (*min != -1 && lastIndex + 1 > *min) //첫번째 뽑는 게 아닐 때 뽑은 갯수가 min보다 크면
		return;

	if (toPick == 0) //조건 충족x 다 뽑음
		return;

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			picked[lastIndex + 1] = i;
			pick(items, n, picked, m, toPick - 1, temp, min);
		}
	}
}

int main(void)
{
	int* items;
	int* picked;
	int num, i, size;
	int min = -1;

	scanf("%d", &num);

	items = (int*)malloc(sizeof(int) * (num - 1));
	picked = (int*)malloc(sizeof(int) * num);
	if (!items || !picked)
		return;

	//items 값 넣기 - 큰 값부터
	for (i = num - 1; i >= 1; i--)
		items[num - i - 1] = i;

	pick(items, num, picked, num, num, 0, &min);
	printf("%d", min);

	free(items);
	free(picked);
}