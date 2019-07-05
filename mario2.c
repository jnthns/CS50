#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    
    do {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);
    
    for (int i = 1; i <= height; i++) { // i = 1, while i is <= height, i + 1
    	for (int spaces = (height - i); spaces > 0; spaces--) { // while spaces > 0, print space
    		printf(" ");
    	}

        // there will always be at least 1 hash
    	for (int hashes = 1; hashes <= i; hashes++) { 
    		printf("#");
    	}
    	printf("\n");
    }
}
