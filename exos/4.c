#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    int sum = 1;
    if (power < 0)
        return 0;
    if (power == 0)
        return 1;
    while (power > 0)
    {
        sum *= nb;
        power--;
    }
    return sum;
}

int main()
{
    printf("%i\n", ft_iterative_power(-5, 3));
}