#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
    int j = 0;
    while (j < size)
    {
        int i = 0;
        while (i < size -1)
        {
            if (tab[i] > tab[i +1])
            {
                int temp = tab[i];
                tab[i] = tab[i +1];
                tab[i +1] = temp;
            }
            i++;
        }
        j++;
    }
}

int main()
{
    int size = 5;
    int tab[] = {12, 2, 9, 3, 5};
    ft_sort_int_tab(tab, size);
    int i = 0;
    while (i < size)
    {
        printf("%i, ", tab[i]);
        i++;
    }
}
