#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("key must contain 26 different alphabetical characters\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("key must contain 26 different alphabetical characters\n");
            return 1;
        }
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("key must contain 26 different alphabetical characters\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
            printf("%c", tolower(argv[1][plaintext[i] - 'a']));
        else if (isupper(plaintext[i]))
            printf("%c", toupper(argv[1][plaintext[i] - 'A']));
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
}
