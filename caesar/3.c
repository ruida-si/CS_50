#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])

{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)

        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    int k = atoi(argv[1]);

    string plaintext = get_string("Plaintext: ");

    printf("Ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", (plaintext[i]));
        }

        if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 'a' + k) % 26 + 'a');
        }

        if (isupper((plaintext[i])))
        {
            printf("%c", (plaintext[i] - 'A' + k) % 26 + 'A');
        }
    }
    printf("\n");
}
