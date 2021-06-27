#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long number, ketasu;
    int count, keta, i, l, sum1, sum2, mc, mc1, mc2;

    count = 0;
    keta = 0;
    sum1 = 0;
    sum2 = 0;

    while (1)
    {
        number = get_long("Number:");
        if (0 < number)
        {
            break;
        }
    }

    ketasu = number;

    // 桁数を計算
    while (ketasu != 0)
    {
        ketasu = ketasu / 10;
        count++;
    }

    // 偶数桁の時
    if (count % 2 == 0)
    {
        for (i = count; i > 0; i--)
        {
            // 一桁ずつ計算していく
            keta = number / (long)pow(10, i - 1);
            if (i == count)
            {
                // 最上位桁の数字を格納
                mc1 = keta;
            }
            else if (i == count - 1)
            {
                // 上から二桁目の数字を格納
                mc2 = keta;
            }
            number = number % (long)pow(10, i - 1);
            // 偶数桁目の数字
            if (i % 2 == 0)
            {
                if (keta * 2 < 10)
                {
                    sum1 += keta * 2;
                }
                else
                {
                    sum1 += (keta * 2 / 10 + keta * 2 % 10);
                }
            }
            // 奇数桁目の数字
            if (i % 2 == 1)
            {
                sum2 += keta;
            }
        }
    }
    // 奇数桁の時
    else
    {
        for (i = count; i > 0; i--)
        {
            keta = number / (long)pow(10, i - 1);
            if (i == count)
            {s
                mc1 = keta;
            }
            else if (i == count - 1)
            {
                mc2 = keta;

            }
            number = number % (long)pow(10, i - 1);
            if (i % 2 == 1)
            {
                sum1 += keta;
            }
            if (i % 2 == 0)
            {
                if (keta * 2 < 10)
                {
                    sum2 += keta * 2;
                }
                else
                {
                    sum2 += (keta * 2 / 10 + keta * 2 % 10);
                }
            }
        }
    }

    mc = mc1 * 10 + mc2;

    // Luhnのアルゴリズムによって種類を判定
    if ((sum1 + sum2) % 10 == 0)
    {
        if (count == 15 && (mc == 34 || mc == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && (mc == 51 || mc == 52 || mc == 53 || mc == 54 || mc == 55))
        {
            printf("MASTERCARD\n");

        }
        else if (mc1 == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}