#define _CRT_SECURE_NO_WARNINGS //피보나치 수열 F(n) 출력
#include <stdio.h>
#include <stdlib.h>
int fib(int n, int* F) //최적화. 중복 계산을 피하기 위해 계산 전 메모 확인, 계산 후 메모.
{ //작은 문제부터 해결하는 방법
	if (n == 1 || n == 2)
		return 1;

	if (F[n - 1] == 0) //memo에서 fn-1확인, 계산된 결과를 저장
		F[n - 1] = fib(n - 1, F); //재귀 호출

	if (F[n - 2] == 0) //memo에서 fn-2확인, 계산된 결과를 저장
		F[n - 2] = fib(n - 2, F); //재귀 호출

	return F[n - 1] + F[n - 2]; //원하는 피보나치 수
}
int main(void)
{
	int num, i;
	int* F;

	scanf("%d", &num);
	
	F = (int*)malloc(sizeof(int) * (num + 1)); //index == n 읽기 편하게, 1~num 사용
	if (!F)
		return 0;

	//F 초기화
	for (i = 0; i <= num; i++)
		F[i] = 0; //계산이 한 번도 이루어지지 않았다. 0은 피보나치 수열에서 나올 수 없는 수

	printf("%d\n", fib(num, F));

	free(F);
	return 0;
}