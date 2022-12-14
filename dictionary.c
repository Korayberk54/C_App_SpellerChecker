// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <ctype.h>
#include <string.h>
#include <strings.h>


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (45 + 1) * 'z';

// Hash table
int total_words = 0;
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    
    // Obtain the hash index
    int index = hash(word);
    
    // Access linked list at that index in the hash table
    node *cursor = table[index];
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    
    int sum = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    
    // Open the dictionary file
    FILE *file = fopen(dictionary,"r");
    if(file == NULL)
    {
        return false;
    }
    
    // Read 1 word at a time from the file
    char word[46];
    while(fscanf(file, "%s", word) != EOF)
    {
        //Create new node and read words
        node *new_node = malloc(sizeof(node));
        if(new_node == NULL)
        {
            return false;
        }
        
        // If it is not NULL, we can copy the word to node
        strcpy(new_node->word, word);
        new_node->next = NULL;
        
        //Obtain hashing index
        int index = hash(word);
        if(table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node; 
        }
        total_words++;
        
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // 
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    
    // Free the linked list
    
    for(int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;
        
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
