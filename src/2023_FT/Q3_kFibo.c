#define _CRT_SECURE_NO_WARNINGS//...
#include <stdio.h>	
#include <stdlib.h>
/*피보나치 수열 확장
k-bonacci
F(n) = 1 if n <= k
	 = F(n - 1) + F(n - 2) + ... + F[n - k + 1) + F(n - k) if n > k
효율성*/
long kFib(int num, int k, long* F)
{
	int i;
	if (F[num] == 0) { //메모에 저장되어 있지 않음
		if (num <= k)
			F[num] = 1;

		else {
			for (i = 1; i <= k; i++)
				F[num] += kFib(num - i, k, F);
		}
	}
	return F[num]; //저장된 피보나치 수 return
}
int main(void)
{
	int n, k, i;
	long* F;

	scanf("%d %d", &n, &k);

	F = (long*)malloc(sizeof(long) * (n + 1)); //편하게 1 ~ num (0은 없는셈)
	if (!F)
		return;

	//F 초기화. 저장되어있지 않음
	for (i = 0; i <= n; i++)
		F[i] = 0; //피보나치 수열에서 나올 수 없는 수

	printf("%ld", kFib(n, k, F)); //반환값 long으로
	free(F);
}