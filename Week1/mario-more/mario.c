#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int spaces;
    do
    {
        height = get_int("A number between 1 and 8: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (spaces = height - 1; i < spaces; spaces--)
        {
            printf(" ");
        }

        for (int hashes = height - spaces; hashes <= height; hashes++)
        {
            printf("#");
        }
        printf("  ");

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}