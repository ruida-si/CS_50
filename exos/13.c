#include <stdio.h>

int ft_atoi(char *str)
{
    int number = 0;
    int min = 1;
    int i = 0;
    while (str[i] < 33)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            min = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return (number * min);
}

int main()
{
    char str[] = "214748";
    printf("%i\n", ft_atoi(str));
}
