#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change = get_int("Change owed: ");

    if (change < 0)
    {
        change = get_int("Change owed: ");
    }

    int sum = 0;

    if (change > 24)
    {
        int a = change / 25;
        change = change % 25;
        sum += a;
    }

    if (change > 9)
    {
        int b = change / 10;
        change = change % 10;
        sum += b;
    }

    if (change > 4)
    {
        int c = change / 5;
        change = change % 5;
        sum += c;
    }

    if (change < 5)
    {
        sum += change;
    }

    printf("%i\n", sum);
}
