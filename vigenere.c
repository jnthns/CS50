#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    // if two arguments
    if (argc == 2) 
    {
        // Store input 
        string key = argv[1];

        // initialize array with length of key
        int array[strlen(key)];

        // for character in Input string
        for (int i = 0; i < strlen(key); i++) 
        {
            // If input is char
            if (isalpha(key[i]))
            {
                array[i] = key[i];
            }
            else 
            {
                printf("Usage: ./vigenere keyword\n");
                return 0;
            }
        }

        // Prompt user
        string plaintext = get_string("plaintext: ");

        printf("ciphertext: ");

        int output[strlen(plaintext)];

        // iterate through length of plaintext
        for (int i = 0; i < strlen(plaintext); i++)
        {
            int loc = i % strlen(key);
            
            if (islower(plaintext[i]))
            {
                if (array[loc] < 97)
                {
                    array[loc] += 32;
                    output[i] = (((plaintext[i] + (array[loc]-'a')) - 'a') % 26) + 'a';
                }
                else
                {
                    output[i] = (((plaintext[i] + (array[loc]-'a')) - 'a') % 26) + 'a';
                }
            }
            else
            {
                if (array[loc] < 97)
                {
                    output[i] = (((plaintext[i] + (array[loc]-'A')) - 'A') % 26) + 'A';
                }
                else
                {
                    array[loc] -= 32;
                    output[i] = (((plaintext[i] + (array[loc]-'A')) - 'A') % 26) + 'A';
                }
            } 
        }

        for (int i = 0; i < strlen(plaintext); i++)
        {
            printf("%c", output[i]);
        }
        printf("\n");
    }

    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 0;
    }
}

