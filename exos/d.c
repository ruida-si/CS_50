#include <unistd.h>

void ft_print_comb(void)
{
    char c = '0';
    while (c < '8')
    {
        char b = c + 1;
        while (b < '9')
        {
            char a = b + 1;
            while (a <= '9')
            {
                write(1, &c, 1);
                write(1, &b, 1);
                write(1, &a, 1);
                if (c != '7')
                    write(1, ", ", 2);
                a++;
            }
            b++;
        }
        c++;
    }

}

int main()
{
    ft_print_comb();
}
