#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 different alphabetical characters\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain 26 different alphabetical characters\n");
            return 1;
        }
    }

    for (int i = 0; i < strlen(argv[1]) - 1; i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("Key must contain 26 different alphabetical characters\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("Plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
            printf("%c", toupper(argv[1][plaintext[i] - 'A']));

        else if (islower(plaintext[i]))
            printf("%c", tolower(argv[1][plaintext[i] - 'a']));

        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
}
