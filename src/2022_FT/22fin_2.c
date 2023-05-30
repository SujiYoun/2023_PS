#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //자연수 6을 1, 2, 3의 합으로 나타냄
#include <stdlib.h> //10ok
void pick(int items[], int n, int* picked, int m, int toPick, int temp, int *total)
{
	int lastIndex, smallest, i;
	lastIndex = m - toPick - 1;

	if (toPick == m)
		smallest = 0;
	else {
		smallest = picked[lastIndex]; //중복 조합
		temp += items[picked[lastIndex]]; //중간 계산
	}	

	//효율성
	if (temp > m)
		return;
	else if (temp == m) { //다 뽑으면
		*total = *total + 1;
		/*for (i = 0; i <= lastIndex; i++)
			printf("%d ", items[picked[i]]);
		printf("\n");*/
	}

	if (toPick == 0)
		return;

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			picked[lastIndex + 1] = i;
			pick(items, n, picked, m, toPick - 1, temp, total);
		}
	}
}
int main(void)
{
	int items[] = { 1, 2, 3 }; //중복조합
	int* picked;
	int num, total = 0;

	scanf("%d", &num);
	picked = (int*)malloc(sizeof(int) * num);
	if (picked == NULL)
		return;

	pick(items, 3, picked, num, num, 0, &total);
	printf("%d", total);

	free(picked);
	return 0;
}