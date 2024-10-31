// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const int N = 45;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int a = strlen(word) - 1;
    if (table[a]->next = NULL)
    {
        table[a]->word = word;
        table[a]->next = NULL;
    }

    return a;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Read each word in the file

        // Add each word to the hash table

    // Close the dictionary file
    // TODO
    // Open the dictionary file
    FILE *dictionary = fopen(dictionary, "r");
    if (dictionary == NULL)
    {
        printf("Dictionary could not be open."\n)
        return false;
    }
    int size = 0;

    while (fscanf(dictionary, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        strcpy(n->word, "word");
        n->next = NULL;
        hash(word);
        size++;
    }

    fclose(dictionary);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
