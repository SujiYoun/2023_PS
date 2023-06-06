#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct F {
	int F1;
	int F0;
	int flag;
};

struct F fib(int n, struct F* memo) {
	struct F ret;

	if (memo[n].flag == 1)
		return memo[n];

	//memo[n].flag == 0
	if (n == 0) {
		ret.F0 = 0;
		ret.F1 = 1;
	}
	else if (n == 1) {
		ret.F0 = 1;
		ret.F1 = 0;
	}
	else {
		struct F fn_1;
		struct F fn_2;

		fn_1 = fib(n - 1, memo);
		fn_2 = fib(n - 2, memo);

		ret.F0 = fn_1.F0 + fn_2.F0;
		ret.F1 = fn_1.F1 + fn_2.F1;
	}
	ret.flag = 1;

	return ret;
}
int main(void)
{
	int n, i;
	struct F ret;
	struct F* memo;

	scanf("%d", &n);
	memo = (struct F*)malloc(sizeof(struct F) * (n + 1));
	if (!memo)
		return;

	for (i = 0; i <= n; i++)
		memo[i].flag = 0;

	ret = fib(n, memo);

	printf("%d %d", ret.F0, ret.F1);

	return 0;
}