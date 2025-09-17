#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int all_digits(string argument);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2 || all_digits(argv[1]) != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Converting string to int
    int key = atoi(argv[1]);
    string input = get_string("plaintext:  ");
    //
    for (int j = 0, len = strlen(input); j < len; j++)
    {
        if (isalpha(input[j]) != 0)
        {
            input[j] = rotate(input[j], key);
        }
    }
    printf("ciphertext: %s\n", input);
}

int all_digits(string argument)
{
    for (int i = 0, lenght = strlen(argument); i < lenght; i++)
    {
        if (isdigit(argument[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
char rotate(char c, int n)
{
    char new = 0;
    if (isupper(c) != 0)
    {
        c = c - 65;
        new = (c + n) % 26;
        new = new + 65;
    }
    else if (isupper(c) == 0)
    {
        c = c - 97;
        new = (c + n) % 26;
        new = new + 97;
    }
    return new;
}
