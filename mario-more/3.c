#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt the user for the pyramid's height within the expected values
    int h;
    do
    {
        h = get_int("Height ");
    }
    while (h < 1 || h > 8);

    // loop through each row
    for (int i = 0; i < h; i++)
    {
        // set "w" as width of the pyramid
        int w = 2 * h + 2;

        // loop through each column
        for (int j = 0; j < w; j++)
        {
            if (j < h)
            {
                if (i + j < h - 1)
                    printf(" ");

                else
                    printf("#");
            }

            else if (j < h + 2)
                printf(" ");

            else
            {
                if (j - i < h + 3)
                    printf("#");
            }
        }
        printf("\n");
    }
}
