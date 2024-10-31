#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count(long card);
int count2(long card);
int count3(long card);

int main(void)
{
    long card =  get_long("Number: ");

    int number = count3(card);
    int sum1 = count(card);
    int sum2 = count2(card);

    int dig = card / pow(10, number - 1);
    int dig2 = card / pow(10, number - 2);

    if ((sum1 + sum2) % 10 != 0)
        printf("INVALID\n");

    else if (number == 15 && (dig2 == 34 || dig2 == 37))
        printf("AMEX\n");

    else if (number == 16 && dig2 > 50 && dig2 < 56)
        printf("MASTERCARD\n");

    else if (dig == 4 && (number == 13 || number == 16))
        printf("VISA\n");

    else
        printf("INVALID\n");
}

int count(long card)
{
    int sum1 = 0;

    while (card > 0)
    {
        int a = card % 100 / 10;
        card = card / 100;
        sum1+= a * 2 / 10 + a * 2 % 10;
    }
    return sum1;
}

int count2(long card)
{
    int sum2 = 0;

    while (card > 0)
    {
        int a = card % 10;
        card = card / 100;
        sum2+= a;
    }
    return sum2;
}

int count3(long card)
{
    int count = 0;

    while (card > 0)
    {
        card = card / 10;
        count++;
    }
    return count;
}
