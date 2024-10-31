#include <unistd.h>

void putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_comb2(void)
{
    int a = 0;
    while (a < 99)
    {
        int b = a + 1;
        while (b < 100)
        {
            putchar(a / 10 + '0');
            putchar(a % 10 + '0');
            putchar(' ');
            putchar(b / 10 + '0');
            putchar(b % 10 + '0');
            if (a != 98)
                write(1, ", ", 2);
            b++;
        }
        a++;
    }
}

int main()
{
    ft_print_comb2();
}
