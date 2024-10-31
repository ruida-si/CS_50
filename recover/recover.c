#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[MAX];
    char jpg[8];
    int count = 0;
    bool found = false;
    FILE *image = NULL;

    while (fread(buffer, 1, MAX, card) == MAX)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (found)
                fclose(image);

            sprintf(jpg, "%03i.jpg", count);
            image = fopen(jpg, "w");
            if (card == NULL)
            {
                printf("Could not open file.\n");
                fclose(card);
                return 1;
            }
            count++;
            found = true;
        }
        if (found)
            fwrite(buffer, MAX, 1, image);
    }
    fclose(image);
    fclose(card);
}
