#include <cs50.h>
#include <stdio.h>


int main (void)
{
    int pyramidHeight;

    do
    {
        pyramidHeight = get_int("Set a height between 1 and 8, inclusive: ");
    }
    while (pyramidHeight < 1 | pyramidHeight > 8);

    for (int i = 0; i < pyramidHeight; i++)
    {
        for (int k = pyramidHeight - 1; k > i; k--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
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
