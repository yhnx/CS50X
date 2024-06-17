// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 52;

// Hash table
node *table[N];

void intiate_hash()
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int num = hash(word);
    node *finder;
    finder = table[num];
    while (finder != NULL)
    {
        if (strcasecmp(finder->word, word) == 0)
        {
            return true;
        }
        else
        {
            finder = finder->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int num;
    num = (toupper(word[0]) - 'A') * 2;
    if (toupper(word[1]) > 79)
    {
        num++;
    }
    return num;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Unable to open desired file");
        return false;
    }
    intiate_hash();
    char *string = malloc(LENGTH + 1);
    while (fscanf(dict, "%s", string) != EOF)
    {
        node *new = malloc(sizeof(node));
        strcpy(new->word, string);
        int n = hash(string);
        new->next = table[n];
        table[n] = new;
    }
    free(string);
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *pointer = table[i];
        while (pointer != NULL)
        {
            node *temp = pointer;
            pointer = pointer->next;
            free(temp);
        }
    }

    return true;
}
