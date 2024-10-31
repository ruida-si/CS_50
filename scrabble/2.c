#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int sum1 = compute(word1);
    int sum2 = compute(word2);

    if (sum1 > sum2)
        printf("Player 1 wins!\n");

    else if (sum1 < sum2)
        printf("Player 2 wins!\n");

    else
        printf("Tie!\n");
}

int compute(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
            score += Points[toupper(word[i]) - 'A'];
    }
    return score;
}
