#define _CRT_SECURE_NO_WARNINGS //피보나치 수열 F(1)과 F(0)의 계수 출력
#include <stdio.h> //10ok
#include <stdlib.h>
struct Fibo {
	int num;
	int zero;
	int one;
};

int fib(int n, struct Fibo *F) //return값을 어떻게
{
	if (F[n].num == 0) { //메모x
		if (n == 0){
			F[n].num = 1;
			F[n].zero = 1;
		}
		else if (n == 1) {
			F[n].num = 1;
			F[n].one = 1;
		}

		else {
			F[n].num = fib(n - 1, F) + fib(n - 2, F);
			F[n].zero = F[n - 1].zero + F[n - 2].zero;
			F[n].one = F[n - 1].one + F[n - 2].one;
			//printf("num:%d 1:%d 0:%d\n", F[n].num, F[n].one, F[n].zero); 호출 확인용
		}
	}
	return F[n].num;
}
int main(void)
{
	int n, i;
	struct Fibo* F;

	scanf("%d", &n);

	F = (struct Fibo*)malloc(sizeof(struct Fibo) * (n + 1)); //0~num
	if (!F)
		return;

	//초기화
	for (i = 0; i <= n; i++) {
		F[i].num = 0;
		F[i].zero = 0;
		F[i].one = 0;
	}
	F[n].num = fib(n, F); //쓸모없는 코드. 함수호출은 해야하나 F[n].num은 함수호출했을 때 이미 저장됨
	//상관 없음

	printf("%d %d", F[n].one, F[n].zero);

	free(F);
	return;
}