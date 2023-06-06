#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //�� �� ���̿� �ɷ�ġ�� ���� �ּҷ� �ϵ��� ���� ����
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

		int diff;  //sum_team1�� sum_team2�� ��
		if (sum_team1 > sum_team2)
			diff = sum_team1 - sum_team2;
		else //sum_team1 <= sum_team2
			diff = sum_team2 - sum_team1;
		/*
		3�� ������
		diffMin = (sum_team1 > sum_team2) ? (sum_team1 - sum_team2) : (sum_team2 - sum_team1);
		*/

		if (diff < *diffMin || *diffMin == -1) //�� ���� �ɷ�ġ �� �ּ�
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

	//num ��
	scanf("%d", &num);
	capacity = (int*)malloc(sizeof(int) * num);
	team1 = (int*)malloc(sizeof(int) * (num / 2));
	if (!capacity || !team1)
		return;

	for (i = 0; i < num; i++) { //���� �ɷ�ġ �Է�
		scanf("%d", &capacity[i]);
		total += capacity[i]; //�ɷ�ġ ����
	}

	team1[0] = 0; //main���� ù��° ���ڷ� 1�� �̴´�
	//ù��° ��� ���� �̱� m = n - 1�� �Լ� ȣ��
	pick(capacity, num, team1, num / 2, num / 2 - 1, total, &diffMin);
	printf("%d", diffMin);

	free(capacity);
	free(team1);

	return;
}