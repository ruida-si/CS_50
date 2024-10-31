#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 2;
    int b = 3;
    ft_swap(&a, &b);
    printf("%i %i\n", a, b);
}
