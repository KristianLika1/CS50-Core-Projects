#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;
    do
    {
        input = get_int("Write a number between 1 and 8: ");
    }
    while (input < 1 || input > 8);

    for (int i = 0; i < input; i++)
    {
        for (int s = 1; s < input - i; s++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}