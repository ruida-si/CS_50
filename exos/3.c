#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return 0;
    if (power == 0)
        return 1;
    int sum = nb * ft_recursive_power(nb, power - 1);
    return sum;
}

int main()
{
    printf("%i\n", ft_recursive_power(2, 3));
}
