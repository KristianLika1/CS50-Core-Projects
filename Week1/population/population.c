#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int isize;
    do
    {
       isize = get_int("How many individuals at the start?");
    }
    while (isize < 9);

    int fsize;
    do
    {
        fsize = get_int("Final population is? ");
    }
    while (fsize < isize);

    int size = isize;
    int growth;
    int death;
    int years = 0;

    for (size = isize; size < fsize; years++)
    {
        growth = size / 3;
        death = size / 4;
        size = size + growth - death;
    }

    printf("Years: %i \n", years);
}
