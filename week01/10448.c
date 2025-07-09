#include <stdio.h>

int triangleN(int n)
{
    return n*(n+1)/2;
}

int main(void)
{
    int num, valid;
    scanf("%d", &num);

    int k, temp;

    for (int i = 0; i < num; i++)
    {
        valid = 0;
        scanf("%d", &k);

        for (int a = 1; a < 46; a++)
        {
            for (int b = 1; b < 46; b++)
            {
                for (int c = 1; c < 46; c++)
                {
                    if (triangleN(a) + triangleN(b) + triangleN(c) == k)
                    {
                        valid = 1;
                        break;
                    }
                }
            }
        }

        if (valid)
            printf("1 \n");
        else
            printf("0 \n");

    }

    return 0;
}