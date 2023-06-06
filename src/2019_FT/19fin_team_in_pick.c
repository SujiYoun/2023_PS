#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //두 팀 사이에 능력치의 합을 최소로 하도록 팀을 구성
#include <stdlib.h> //10ok
void pick(int* capacity, int n, int* team1, int m, int toPick, int total, int *diff)
{
	int lastIndex, smallest, i;

	if (toPick == 0) {
		int sum = 0;
		for (i = 0; i < m; i++) {
			//printf("%d ", team1[i] + 1);
			sum += capacity[team1[i]];
		}

		int tmpDiff;  //sum과 total - sum의 차
		if (total < sum * 2)
			tmpDiff = (sum * 2) - total;
		else
			tmpDiff = total - (sum * 2);

		if (tmpDiff < *diff || *diff == -1) //두 팀의 능력치 차 최소
			*diff = tmpDiff;
		//printf(": %d / diff : %d\n", sum, tmpDiff);

		return;
	}

	lastIndex = m - toPick - 1;
	if (toPick == m) {
		smallest = 0;
		team1[lastIndex + 1] = 0; //중복 호출 막기 위해 첫번째 값은 무조건 0(1)
		pick(capacity, n, team1, m, toPick - 1, total, diff);
	}
	else
		smallest = team1[lastIndex] + 1;

	if (toPick > 0 && toPick < m) {
		for (i = smallest; i < n; i++) {
			team1[lastIndex + 1] = i;
			pick(capacity, n, team1, m, toPick - 1,total, diff);
		}
	}
}
int main(void)
{
	int* capacity;
	int* team1; //0, 1, 2, 3, 4, 5
	int num, i;
	int diff = -1;
	int total = 0;

	//num 명
	scanf("%d", &num);
	capacity = (int*)malloc(sizeof(int) * num);
	team1 = (int*)malloc(sizeof(int) * (num / 2));
	if (!capacity || !team1)
		return;

	for (i = 0; i < num; i++) { //개별 능력치
		scanf("%d", &capacity[i]);
		total += capacity[i];
	}

	pick(capacity, num, team1, num / 2, num / 2, total, &diff);
	printf("%d", diff);

	free(capacity);
	free(team1);

	return;
}