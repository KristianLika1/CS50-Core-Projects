#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int all_letters(string argument);
int all_different(string argument);
char substitute(char input, string key);

int main(int argc, string argv[])
{
    if (argc != 2 || all_letters(argv[1]) != 0 || all_different(argv[1]) == 1 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\nKey must contain 26 characters\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int lenght = strlen(plaintext);
    char cyphertext[lenght];
    for (int i = 0; i <= lenght; i++)
    {
        cyphertext[i] = substitute(plaintext[i], argv[1]);
    }
    printf("ciphertext: %s\n", cyphertext);
    return 0;
}

int all_letters(string argument)
{
    for (int i = 0, lenght = strlen(argument); i < lenght; i++)
    {
        if (isalpha(argument[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int all_different(string argument)
{
    for (int i = 0, lenght = strlen(argument); i < lenght - 1; i++)
    {
        for (int j = i + 1; j < lenght; j++)
        {
            if (toupper(argument[i]) == toupper(argument[j]))
            {
                return 1;
            }
        }
    }
    return 0;
}

char substitute(char input, string key)
{
    int new = input;
    if (isupper(input) != 0 && isalpha(input) != 0)
    {
        new = input - 65;
        new = toupper(key[new]);
    }
    else if (isupper(input) == 0 && isalpha(input) != 0)
    {
        new = input - 97;
        new = tolower(key[new]);
    }
    return (char) new;
}
