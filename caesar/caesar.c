#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int i = 0;
    while (argv[1][i])
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        i++;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
            printf("%c", (plaintext[i] - 'A' + key) % 26 + 'A');
        else if (islower(plaintext[i]))
            printf("%c", (plaintext[i] - 'a' + key) % 26 + 'a');
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
}
