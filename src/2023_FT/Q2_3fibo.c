#define _CRT_SECURE_NO_WARNINGS //10
#include <stdio.h>
#include <stdlib.h>
/*피보나치 수열 확장
3-bonacci 수열
F(n) = 1 if n = 1 or 2 or 3
	 = F(n - 1) + F(n - 2) + F(n - 3) if n > 3
효율성*/
long fib(int num, long* F)
{ //큰 문제부터 확인
	if (F[num] == 0) { //메모에 저장되어 있지 않음
		if (num == 1 || num == 2 || num == 3)
			F[num] = 1;

		else
			F[num] = fib(num - 1, F) + fib(num - 2, F) + fib(num - 3, F); //메모에 저장
	}
	return F[num]; //저장된 피보나치 수 return
}

int main(void)
{
	int num, i;
	long* F; 

	scanf("%d", &num);

	F = (long*)malloc(sizeof(long) * (num + 1)); //편하게 1 ~ num (0은 없는셈)
	if (!F)
		return;

	//F 초기화. 저장되어있지 않음
	for (i = 0; i <= num; i++)
		F[i] = 0; //피보나치 수열에서 나올 수 없는 수

	printf("%ld", fib(num, F)); //반환값 long으로

	free(F);
}