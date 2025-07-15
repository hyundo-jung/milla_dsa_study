#include <stdio.h>

int MachineDuck[14];
int cash;

int bnp(void)
{
    int asset = cash;
    int stock = 0;

    for (int i = 0; i < 14; i++)
    {
        int share = asset / MachineDuck[i];
        stock += share;
        asset -= share * MachineDuck[i];
    }

    return asset + (stock * MachineDuck[13]);
}

int timing(void)
{
    int asset = cash;
    int stock = 0;

    int up = 0, down = 0;

    for (int i = 1; i < 14; i++)
    {
        if (MachineDuck[i] > MachineDuck[i - 1]) // 전일대비 상승
        {
            up++;
            down = 0;
        }
        if (MachineDuck[i] < MachineDuck[i - 1]) // 전일대비 하락
        {
            down++;
            up = 0;
        }

        if (up == 3)
        {
            asset += stock * MachineDuck[i];
            stock = 0; // 전량 매도

            up--;
        }
        else if (down == 3)
        {
            int share = asset / MachineDuck[i];
            stock += share;
            asset -= share * MachineDuck[i]; //전량매수

            down--;
        }
    }
    return asset + (stock * MachineDuck[13]);
}

int main(void)
{
    scanf("%d", &cash);
    getchar();

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d", &MachineDuck[0], &MachineDuck[1], &MachineDuck[2], &MachineDuck[3], &MachineDuck[4], &MachineDuck[5], &MachineDuck[6], &MachineDuck[7], &MachineDuck[8], &MachineDuck[9], &MachineDuck[10], &MachineDuck[11], &MachineDuck[12], &MachineDuck[13]);

    int x = bnp();
    int y = timing();

    if (x > y)
        printf("BNP \n");
    else if (y > x)
        printf("TIMING \n");
    else
        printf("SAMESAME \n");

    return 0;
}