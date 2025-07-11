#include <stdio.h>

char boardW[8][8], boardB[8][8];
int cnt = 64;

void fillBoard(void)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				boardW[i][j] = 'W';
				boardB[i][j] = 'B';
			}
			else
			{
				boardW[i][j] = 'B';
				boardB[i][j] = 'W';
			}
		}
	}
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main(void)
{
	int M, N;
	scanf("%d %d", &M, &N);
    getchar();

    fillBoard();
	
	char board[M][N];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &board[i][j]);
		}
        getchar();
	}

    // printf("\n");
    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //         printf("%c", board[i][j]);
    //     printf("\n");
    // }

	for (int i = 0; i < M - 8 + 1; i++)
	{
		for (int j = 0; j < N - 8 + 1; j++)
		{
			int tempW = 0, tempB = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (boardW[k][l] != board[k + i][l + j])
					{
						tempW++;
					}
					if (boardB[k][l] != board[k + i][l + j])
					{
						tempB++;
					}
				}
			}

            int temp = min(tempW, tempB);
            if (temp < cnt)
            {
                cnt = temp;
            }
			// if (tempW < cnt)
            // {
			// 	cnt = tempW;
            // }
			// else if (tempB < cnt)
			// 	cnt = tempB;
		}
	}

	printf("%d \n", cnt);
	return 0;
}