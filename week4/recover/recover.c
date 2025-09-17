#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Only one command-line argument\n");
        return 1;
    }

    int block_size = 512, file_count = -1;
    uint8_t buffer[block_size];
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File not opened\n");
        return 1;
    }

    FILE *current_file = NULL;
    while (fread(buffer, block_size, 1, input))
    {
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0)
        {
            file_count++;
            // if there is already an open file close it
            if (current_file != NULL)
            {
                fclose(current_file);
            }
            char filename[8]; // Enough space for filenames like "999.jpg\0"
            sprintf(filename, "%03i.jpg", file_count);
            current_file = fopen(filename, "w");
            if (current_file == NULL)
            {
                printf("Could not open %s.\n", filename);
                return 1;
            }
        }
        if (current_file != NULL)
        {
            fwrite(buffer, block_size, 1, current_file);
        }
    }
    if (current_file != NULL)
    {
        fclose(current_file);
    }
    fclose(input);
}
