#include <stdio.h>

int board[5][5];

void findAndReplace(int x)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == x)
            {
                board[i][j] = 0;
                return;
            }
        }
    }
}

void printBoard()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkLines()
{
    int cnt = 0; // number of lines with all five numbers crossed out
    int consec;

    // horizontal check
    for (int i = 0; i < 5; i++)
    {
        consec = 0;
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 0)
                consec++;
        }

        if (consec == 5)
            cnt++;
    }

    // vertical check
    for (int j = 0; j < 5; j++)
    {
        consec = 0;
        for (int i = 0; i < 5; i++)
        {
            if (board[i][j] == 0)
            {
                consec++;
            }
        }

        if (consec == 5)
            cnt++;
    }

    // digaonal check

    consec = 0;
    int consecB = 0;
    \
    for (int i = 0; i < 5; i++)
    {
        if (board[i][i] == 0)
            consec++;

        if (board[i][4 - i] == 0)
            consecB++;

        if (consec == 5)
            cnt++;

        if (consecB == 5)
            cnt++;

    }

    return cnt;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    int num; // 사회자가 부르는 숫자
    int flag = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &num);

            if (flag == 0)
            {
                findAndReplace(num);

                if (checkLines() >= 3)
                {
                    flag = (i*5 + j) + 1;
                }
            }
        }
    }

    printf("%d \n", flag);
    return 0;
}