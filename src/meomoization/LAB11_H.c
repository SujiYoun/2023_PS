#define _CRT_SECURE_NO_WARNINGS //�޸����
#include <stdio.h>
#include <stdlib.h>
int H(int n)
{ //H(n) = H(0) * H(n-1) + H(1) * H(n-2) +```+ H(n-1) * H(0)
	int total = 0, i;

	if (n == 0 || n == 1)
		return 1;
	
	else { //n > 1
		for (i = 0; i < n; i++)
			total += H(i) * H(n - i - 1);

		return total;
	}
}

int main(void)
{
	int num;

	printf("0���� ū ����: ");
	scanf("%d", &num);

	printf("����� %d\n", H(num));
}