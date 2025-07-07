#include <stdio.h>

int decomposition(int M)
{
    int N = M;

    while (M > 0)
    {
        N += M % 10;
        M /= 10;
    }

    return N;
}

int main(void)
{
	int N, M, found = 1;
	scanf("%d", &N);

    M = 0;

    while (decomposition(M) != N)
    {
        M++;
        if (M == N)
        {
            found = 0;
            break;
        }
    }

    if (found == 0)
        printf("0 \n");
    else
        printf("%d \n", M);

	return 0;
}