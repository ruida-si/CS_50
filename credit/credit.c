#include <cs50.h>
#include <stdio.h>
#include <math.h>

int checksum(long card)
{
    int sum = 0;
    while (card > 0)
    {
        sum += card % 10;
        card = card / 100;
    }
    return sum;
}
int checksum2(long card)
{
    int sum = 0;
    int a = 0;
    card = card / 10;
    while (card > 0)
    {
        a = (card % 10) * 2;
        sum += a / 10 + a % 10;
        card = card / 100;
    }
    return sum;
}

int count(long card)
{
    int count = 0;
    while (card > 0)
    {
        card = card / 10;
        count++;
    }
    return count;
}

int main()
{
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    if ((checksum(card) + checksum2(card)) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int number = count(card);
    int last2dig = card / pow(10, number - 2);
    int lastdig = card / pow(10, number - 1);

    if (number == 15 && (last2dig == 34 || last2dig == 37))
    {
        printf("AMEX\n");
        return 0;
    }

    if (number == 16 && last2dig > 50 && last2dig < 56)
    {
        printf("MASTERCARD\n");
        return 0;
    }

    if ((number == 13 || number == 16) && lastdig == 4)
    {
        printf("VISA\n");
        return 0;
    }

    else
    {
        printf("INVALID\n");
        return 0;
    }
}
