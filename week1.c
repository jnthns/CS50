#include <cs50.h>
#include <stdio.h>

// https://lab.cs50.io/cs50/labs/2019/x/mario/less/

int main(void)
{
		// initialize height variable
    int height = 0;
    
    // if height is outside range, prompt user for valid number
    do {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);
    

    // while i < height, print hash for each iteration of i
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
    
    // spaces will always be height - 1
    for (int i = 1; i <= height; i++) { // i = 1, while i is <= height, i + 1
    	for (int spaces = (height - i); spaces > 0; spaces--) { // while spaces > 0, print space
    		printf(" ");
    	}

        // there will always be at least 1 hash 
    	for (int hashes = 1; hashes <= i; hashes++) {  // print as many hashes as there are iterations 
    		printf("#");
    	}
    	printf("\n");
    }
}
