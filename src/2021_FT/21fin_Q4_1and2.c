#define _CRT_SECURE_NO_WARNINGS //9ok
#include <stdio.h>
#include <stdlib.h>

void pick(int items[], int n, int* picked, int m, int toPick, int tmpSum, int* sum_num)
{
	int i, j, smallest, lastIndex;

	if (toPick == 0) {
		/*sum = 0;
		for (i = 0; i < m; i++) {
			//printf("%d", picked[i]);
			sum += items[picked[i]];
		}*/

		tmpSum += items[picked[m - 1]]; //마지막으로 뽑은 수

		if (tmpSum == m) { //뽑은 1, 2의 합이 num과 같으면
			*sum_num = *sum_num + 1; //* 붙여야 sum_num 값에 접근 가능
		}
	}


	//중복 조합
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	//**중간 계산 - 출력시간 줄이기
	if (lastIndex > -1)
		tmpSum += items[picked[lastIndex]];

	if (tmpSum > m) //지금까지 뽑힌 수의 합이 m을 넘으면 재귀 호출 할 필요x.
		return;


	if (toPick > 0) {
		for (i = smallest; i < n; i++) { //반복문 안에서 중간계산 x
			picked[lastIndex + 1] = i;

			//여기서 sum_num에 들어있는 건 주소값
			pick(items, n, picked, m, toPick - 1, tmpSum, sum_num);
		}
	}
}
int main(void)
{
	int items[] = { 2, 1, 0 };
	int* picked;
	int num, sum_num = 0; //전역변수 사용x

	scanf("%d", &num);
	if (num < 1 || num > 900)
		return 0;

	picked = (int*)malloc(sizeof(int) * num);
	if (picked == NULL)
		return 0;

	//주소값 넘겨주기
	pick(items, 3, picked, num, num, 0, &sum_num);
	printf("%d", sum_num);

	free(picked);
	return 0;
}