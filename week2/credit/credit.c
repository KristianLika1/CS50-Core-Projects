#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n = get_long("Credit card number: ");

    int i = 0;
    long temp = n;

    do
    {
        temp = temp / 10;
        i++;
    }
    while (temp > 0);

    printf("%i\n", i);


}
