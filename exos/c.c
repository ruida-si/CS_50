#include <unistd.h>

void putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    long max = nb;
    if (max < 0)
    {
        write(1, "-", 1);
        max = -max;
    }
    if (max < 10)
        putchar(max + '0');
    else
    {
        ft_putnbr(max / 10);
        ft_putnbr(max % 10);
    }
}

int main()
{
    ft_putnbr(-2);
}
