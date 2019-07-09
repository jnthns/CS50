#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    int keyLength = strlen(argv[1]);
    
    // If two arguments
     if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else 
    {
        string key = argv[1];

        // Initialize empty array with length of key
        int array[keyLength];

        // For character in key
        for (int i = 0; i < keyLength; i++) 
        {
            // If input is char, store into empty array
            if (isalpha(key[i]))
            {    
                array[i] = key[i];  
            }
            else 
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }

        // Prompt user
        string plaintext = get_string("plaintext: ");
        int plaintextLength = strlen(plaintext);

        printf("ciphertext: ");

        // Initialize output array 
        int output[strlen(plaintext)];

        // Iterate through length of plaintext
        for (int i = 0, j = 0; i < plaintextLength; i++)
        {
            // Iterate over key
            int loc = j % keyLength;

            if (islower(plaintext[i]))
            {
                // If char in key is uppercase
                if (array[loc] < 'a')
                {
                    // Convert to lower
                    array[loc] = tolower(array[loc]);
                    output[i] = (((plaintext[i] + (array[loc] - 'a')) - 'a') % 26) + 'a';
                    // Increment j after plaintext[i] is encrypted
                    j++;
                }
                else
                {
                    output[i] = (((plaintext[i] + (array[loc] - 'a')) - 'a') % 26) + 'a';
                    j++;
                }
            }
            else if (isupper(plaintext[i]))
            {
                if (array[loc] < 'a')
                {
                    output[i] = (((plaintext[i] + (array[loc] - 'A')) - 'A') % 26) + 'A';
                    j++;
                } 
                else
                {
                    array[loc] = toupper(array[loc]);
                    output[i] = (((plaintext[i] + (array[loc] - 'A')) - 'A') % 26) + 'A';
                    j++;
                }
            }
            else 
            {
                // If !isalpha, leave as is
                output[i] = plaintext[i];
            }
 
            printf("%c", output[i]);
        }
    
        printf("\n");
    }
}

