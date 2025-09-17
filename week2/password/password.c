// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int lenght = strlen(password);
    bool lowerc = false;
    bool upperc = false;
    bool simb = false;
    bool numb = false;
    for (int i = 0; i < lenght; i++)
    {
        if (islower(password[i]) != '0')
        {
            lowerc = true;
        }
        if (isupper(password[i])  != '0')
        {
            upperc = true;
        }
        if (isdigit(password[i])  != '0')
        {
            numb = true;
        }
        if(password[i] == '!' || password[i] == '$' || password[i] == '#')
        {
            simb = true;
        }
    }
    if(lowerc == true && upperc == true && simb == true && numb == true)
    {
        return true;
    }
    else
    {
         return false;
    }

}
