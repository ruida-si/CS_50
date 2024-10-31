#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
            letters++;
        if (text[i] == ' ')
            words++;
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }

    int index = round(0.0588 * ((float) letters / words * 100) -
                      0.296 * ((float) sentences / words * 100) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    else
    {
        printf("Grade %i\n", index);
        return 0;
    }
}
