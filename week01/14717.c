#include <stdio.h>

int deck[18];
int a, b, pair = 0;

int win = 0;

int comp(int x, int y)
{
    if (pair == 1 && x == y)
        return a > x;
    else if (pair == 1 && x != y)
        return 1;
    else if (pair == 0 && x != y)
        return ((a + b) % 10 > (x + y) % 10);
    return 0;
}


int main(void)
{
	scanf("%d %d", &a, &b);
	
	if (a == b)
		pair = 1;

    int cnt = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (j != a && j != b)
            {
                deck[cnt] = j;
                cnt++;
            }
        }
    }

    if (pair != 1)
    {
        deck[cnt++] = a;
        deck[cnt] = b;
    }

	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
            if (i != j) // 같은 카드를 두번 뽑을 수 없기에
            {
                win += comp(deck[i], deck[j]);
            }
        }
	}

	printf("%.3f \n", (double)win / (18 * 17));
	return 0;
}