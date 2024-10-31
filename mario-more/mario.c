#include <cs50.h>
#include <stdio.h>

int main()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height * 2 + 2; j++)
        {
            if ( j < height)
            {
                if (i + j < height - 1)
                    printf(" ");
                else
                    printf("#");
            }
            else if ( j < height + 2)
                printf(" ");
            else
            {
                if (j - i < height + 3)
                   printf("#");
            }
        }
        printf("\n");
    }
}
