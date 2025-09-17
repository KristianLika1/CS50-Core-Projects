// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input, int lenght);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("NO\n");
        return 1;
    }

    else
    {
        string novow = replace(argv[1], strlen(argv[1]));
        printf("%s\n", novow);
    }
}

string replace(string input, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        if (input[i] == 'A' || input[i] == 'a')
        {
            input[i] = '6';
        }
        if (input[i] == 'E' || input[i] == 'e')
        {
            input[i] = '3';
        }
        if (input[i] == 'I' || input[i] == 'i')
        {
            input[i] = '1';
        }
        if (input[i] == 'O' || input[i] == 'o')
        {
            input[i] = '0';
        }
    }
    return input;
}
