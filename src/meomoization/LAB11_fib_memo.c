#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int num, int *F)
{ //큰 문제부터 확인
	if (F[num] == 0) { //메모에 저장되어 있지 않음
		if (num == 1 || num == 2)
			F[num] = 1;

		else
			F[num] = fib(num - 1, F) + fib(num - 2, F); //메모에 저장
	}
	return F[num]; //저장된 피보나치 수 return

	/* 작은 문제부터 확인
	* if (F[num - 1] == 0)
	*	F[num - 1] = fib(num - 1, F);
	*
	* if (F[num - 2] == 0)
	*	F[num - 2] = fib(num - 2, F);
	*
	* return F[n - 1] + F[n - 2];
	*/
}

int main(void)
{
	int num, i;
	int* F;

	printf("몇 번째까지의 피보나치 수열: ");
	scanf("%d", &num);

	F = (int*)malloc(sizeof(int) * (num + 1)); //편하게 1 ~ num (0은 없는셈)
	if (!F)
		return;

	//F 초기화. 저장되어있지 않음
	for (i = 0; i <= num; i++)
		F[i] = 0; //피보나치 수열에서 나올 수 없는 수

	for (i = 1; i <= num; i++)
		printf("%3d", fib(i, F)); //?? 
	printf("\n");

	free(F);
}