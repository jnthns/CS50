#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage recover, 1 argument.\n");
        return 1;
    }

    // declare infile
    char *infile = argv[1];

    // char array to store the resultant string
    char filename[10];

    // open memory card file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // make buffer of 512 bytes
    // initialize all variables with 0; seg fault occurs if assigned to NULL
    uint8_t buffer[512] = {0};

    // pointer to FILE
    FILE *img = 0;

    // keep count of files
    int index = 0;

    // repeat until end of jpegs in card
    while (fread(&buffer, sizeof(buffer), 1, inptr) == 1)
    {
        // if start of JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if currently reading
            if (index > 0)
            {
                // save buffer to file, close file
                fclose(img);
            }

            // if not currently reading
            // name file, write to file, increment index
            sprintf(filename, "%03i.jpg", index);
            img = fopen(filename, "w");
            fwrite(&buffer, sizeof(buffer), 1, img);
            index ++;
        }
        // if not start of JPG
        else
        {
        	// if past start of JPG
            if (index > 0)
            {
                // write buffer to file
                fwrite(&buffer, sizeof(buffer), 1, img);
            }
        }
    }

    fclose(inptr);

    // success
    return 0;
}


