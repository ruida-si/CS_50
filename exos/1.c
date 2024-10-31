#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int sum = 1;

    if (nb < 0)
        return 0;
    if (nb < 2)
        return 1;
    while (nb > 1)
    {
        sum *= nb;
        nb--;
    }
    return sum;
}

int main()
{
    printf("%i\n", ft_iterative_factorial(3));
}
