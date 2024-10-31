void ft_sort_int_tab(int *tab, int size)
{
    int i = 0;
    while (i < size / 2)
    {
        int temp = tab[i];
        tab[i] = tab[size -1 - i];
        tab[size -1 - i] = temp;
        i++;
    }
}

#include <stdio.h>

int main()
{
    int size = 4;
    int tab[] = {1, 4, 5, 6};
    ft_sort_int_tab(tab, size);
    int i = 0;
    while (i < size)
    {
        printf("%i ", tab[i]);
        i++;
    }
}
