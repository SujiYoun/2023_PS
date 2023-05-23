#define _CRT_SECURE_NO_WARNINGS //조합의 수(recursion) memo없는 버전
#include <stdio.h>
#include <stdlib.h>
int comb(int n, int r)
{
	/*printf("comb(%d, %d) \n", n, r);
	4,2
	3,1
	2,0
	2,1
	1,0
	1,1
	3,2
	2,1
	1,0
	1,1
	2,2
	*/
	if (r == 0 || r == n)
		return 1;
	else
		return comb(n - 1, r - 1) + comb(n - 1, r);
}
int main(void)
{
	int C;
	
	C = comb(4, 2); //4C2

	printf("%d", C);
	
	return 0;
}