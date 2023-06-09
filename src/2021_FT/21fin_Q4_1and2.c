#define _CRT_SECURE_NO_WARNINGS //10ok
#include <stdio.h>
#include <stdlib.h>

void pick(int items[], int n, int* picked, int m, int toPick, int* count)
{
	int i, j, smallest, lastIndex;

	//중복 조합
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	//**중간 계산 - 출력시간 줄이기
	//0빼고 뽑기!!***
	int tmpSum = 0; //인수로 넣어도 됨
	if (lastIndex > -1)
		for (i = 0; i <= lastIndex; i++)
			tmpSum += items[picked[i]];

	if (tmpSum > m) //지금까지 뽑힌 수의 합이 m을 넘으면 재귀 호출 할 필요x.
		return;
	
	if (tmpSum == m) { //중간에 다 뽑았음
		/*for (i = 0; i <= lastIndex; i++)
			printf("%d ", items[picked[i]]);
		printf("\n");*/
		*count = *count + 1;
		return;
	}

	if (toPick == 0) //다 뽑았는데 조건 충족 x
		return;

	if (toPick > 0) {
		for (i = smallest; i < n; i++) { //반복문 안에서 중간계산 x
			picked[lastIndex + 1] = i;

			//여기서 count에 들어있는 건 주소값
			pick(items, n, picked, m, toPick - 1, count);
		}
	}
}
int main(void)
{
	int items[] = { 1,2 };
	int* picked;
	int num, count = 0; //전역변수 사용x

	scanf("%d", &num);
	if (num < 1 || num > 900)
		return 0;

	picked = (int*)malloc(sizeof(int) * num);
	if (picked == NULL)
		return 0;

	//주소값 넘겨주기
	pick(items, 3, picked, num, num, &count);
	printf("%d", count);

	free(picked);
	return 0;
}