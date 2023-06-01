#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int* item, int n, int* picked, int m, int toPick)
{
	int lastIndex, smallest, i;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			printf("%d ", picked[i]);
		}
		printf(": ");

		for (i = 0; i < m; i++) {
			printf("%d ", item[picked[i]]);
		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			picked[lastIndex + 1] = i;
			pick(item, n, picked, m, toPick);
		}
	}
}
int main(void)
{
	int* members;
	int* team1;
	int* team2;
	int num, i;

	//num 명
	scanf("%d", &num);
	members = (int*)malloc(sizeof(int) * num);
	team1 = (int*)malloc(sizeof(int) * (num / 2));
	team2 = (int*)malloc(sizeof(int) * (num / 2));
	if (!members || !team1 || !team2)
		return;

	for (i = 0; i < num; i++) { //개별 능력치
		scanf("%d", &members[i]);
	}

	pick(members, 6, team1, num / 2, num / 2);

	free(members);
	free(team1);
	free(team2);

	return;
}