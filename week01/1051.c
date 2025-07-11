#include <stdio.h>

char map[50][50];

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int edgeValid(int x, int y, int spread)
{
    if (map[x][y] != map[x + spread][y])
        return 0;
    else if (map[x + spread][y] != map[x][y + spread])
        return 0;
    else if (map[x][y + spread] != map[x + spread][y + spread])
        return 0;

    return 1;
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
    getchar();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%c", &map[i][j]);
        }
        getchar();
    }
	
    // printf("\n");
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < M; j++)
	// 		printf("%c", map[i][j]);
	// 	printf("\n");
	// }

    int max_size = max(N, M);
    int ans_size = 0;

    for (int i = 1; i <= max_size; i++)
    {
        for (int j = 0; j < N - i + 1; j++)
        {
            for (int k = 0; k < M - i + 1; k++)
            {
                if (edgeValid(j, k, i - 1))
                    ans_size = i;
            }
        }
    }

    printf("%d \n", ans_size * ans_size);

    return 0;
}