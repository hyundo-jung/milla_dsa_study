#include <stdio.h>

int data[2][16];
int days;
int pay = 0;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void powerSet(int today, int benefit)
{
    pay = max(pay, benefit);

    if (today == days + 1)
        return;

    // 오늘 상담을 하기로 결정
    if (today + data[0][today] <= days + 1)
    {
        powerSet(today + data[0][today], benefit + data[1][today]);
    }

    // 오늘 상담을 안할때
    powerSet(today + 1, benefit);
}

int main(void)
{
    scanf("%d", &days);
    for (int i = 1; i <= days; i++)
    {
        scanf("%d %d", &data[0][i], &data[1][i]); // T, P
    }

    powerSet(1, 0);

    printf("%d \n", pay);
    return 0;
}