#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void checkReadabilityGrade(int);

int main(void)
{
    string text = get_string("Insert text to test its readability grade:\n");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        if (isspace(text[i]))
        {
            words++;
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    int index = round((0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8);

    checkReadabilityGrade(index);
}

void checkReadabilityGrade(int grade)
{
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
