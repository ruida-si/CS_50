#include <cs50.h>
#include <stdio.h>

int main()
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    int count = 0;
    if (change >= 25)
    {
        count += change / 25;
        change = change % 25;
    }

    if (change >= 10)
    {
        count += change / 10;
        change = change % 10;
    }

    if (change >= 5)
    {
        count += change / 5;
        change = change % 5;
    }
    count += change;
    printf("%i\n", count);
}
