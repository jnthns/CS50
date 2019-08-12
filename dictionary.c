// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// node pointer to head of linked list
node *head = NULL;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // init index
    int index = 0;

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // create a new empty node for each word we load in from dictionary
        node *new_node = malloc(sizeof(node));

        // check that malloc succeeded
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        // copy word to node
        strcpy(new_node->word, word);

        // hash function to return index for each node
        index = hash(new_node->word);

        // use index to sort nodes into linked list/hashtable
        new_node->next = hashtable[index];

        // point head to new_node
        hashtable[index] = new_node;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // keep count of how many words in dictionary
    int counter = 0;

    // for linked list in hashtable
    for (int i = 0; i < N; i++)
    {
        // pointer to word
        node *word = hashtable[i];

        while (word != NULL)
        {
            counter++;
            word = word->next;
        }
    }

    return counter;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // initialize new array with length of word + 1 for null terminator
    char wordcheck[strlen(word)+1];

    // add null terminator to end of wordcheck
    wordcheck[strlen(word)] = '\0';

    // get index for hashed word
    int index = hash(word);

    // point cursor to location in linked list while cursor is not null, then advance to next node
    for (node *cursor = hashtable[index]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];

        // while words are loaded
        while (cursor != NULL)
        {
            // point to cursor
            node *temp = cursor;

            // advance to next linked list
            cursor = cursor->next;

            // free node
            free(temp);
        }
    }

    return true;
}
