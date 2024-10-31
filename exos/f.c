#include <unistd.h>
#include <stdio.h>

void ft_ft(int *nbr)
{
    *nbr = 42;
}
int main()
{
    int nb = 100;
    ft_ft(&nb);
    printf("%i\n", nb);
}
