#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //두 팀 사이에 능력치의 합을 최소로 하도록 팀을 구성
#include <stdlib.h> //10ok
void pick(int* capacity, int n, int* team1, int m, int toPick, int total, int *diffMin)
{
	int lastIndex, smallest, i;

	if (toPick == 0) {
		int sum_team1 = 0;
		for (i = 0; i < m; i++) {
			//printf("%d ", team1[i] + 1);
			sum_team1 += capacity[team1[i]];
		}
		int sum_team2 = total - sum_team1;

		int diff;  //sum_team1과 sum_team2의 차
		if (sum_team1 > sum_team2)
			diff = sum_team1 - sum_team2;
		else //sum_team1 <= sum_team2
			diff = sum_team2 - sum_team1;
		/*
		3항 연산자
		diffMin = (sum_team1 > sum_team2) ? (sum_team1 - sum_team2) : (sum_team2 - sum_team1);
		*/

		if (diff < *diffMin || *diffMin == -1) //두 팀의 능력치 차 최소
			*diffMin = diff;
		//printf(": %d / diffMin : %d\n", sum_team1, diff);

		return;
	}

	lastIndex = m - toPick - 1;
	if (toPick == m) {
		smallest = 0;
	}
	else
		smallest = team1[lastIndex] + 1;

	if (toPick > 0) {
		for (i = smallest; i < n; i++) {
			team1[lastIndex + 1] = i;
			pick(capacity, n, team1, m, toPick - 1,total, diffMin);
		}
	}
}
int main(void)
{
	int* capacity;
	int* team1; //0, 1, 2, 3, 4, 5
	int num, i;
	int diffMin = -1;
	int total = 0;

	//num 명
	scanf("%d", &num);
	capacity = (int*)malloc(sizeof(int) * num);
	team1 = (int*)malloc(sizeof(int) * (num / 2));
	if (!capacity || !team1)
		return;

	for (i = 0; i < num; i++) { //개별 능력치 입력
		scanf("%d", &capacity[i]);
		total += capacity[i]; //능력치 총합
	}

	team1[0] = 0; //main에서 첫번째 숫자로 1을 뽑는다
	//첫번째 사람 빼고 뽑기 m = n - 1로 함수 호출
	pick(capacity, num, team1, num / 2, num / 2 - 1, total, &diffMin);
	printf("%d", diffMin);

	free(capacity);
	free(team1);

	return;
}