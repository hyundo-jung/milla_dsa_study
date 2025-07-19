#include <stdio.h>
#include <stdlib.h>

int visited[20];
int map[20][20];
int n;
int minDiff = __INT_MAX__;

void calculateSkill()
{
    int teamOne = 0;
    int teamTwo = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i] && visited[j])
                teamOne += map[i][j];
            else if (!(visited[i]) &&!(visited[j]))
                teamTwo += map[i][j];
        }
    }

    int diff = abs(teamOne - teamTwo);
    if (diff < minDiff)
        minDiff = diff;
    return;
}

void selectTeam(int start, int cnt)
{
	if (cnt == n/2)
    {
        calculateSkill();
    }

	for (int i = start; i < n; i++)
	{
		if (!(visited[i]))
		{
			visited[i] = 1;
			selectTeam(i + 1, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main(void)
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    }

    selectTeam(0, 0);

    printf("%d \n", minDiff);
    return 0;

}