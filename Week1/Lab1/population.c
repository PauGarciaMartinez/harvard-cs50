#include <cs50.h>
#include <stdio.h>

int get_population_int (string prompt, int condition);

int main(void)
{
    int startingPopulationSize = get_population_int("Please set an initial population number: ", 9);

    int endingPopulationSize = get_population_int("Now define a final population number: ", startingPopulationSize);
    
    int years = 0;
    
    while (startingPopulationSize < endingPopulationSize)
    {
        int llamasBornt = startingPopulationSize / 3;
        int llamasDead = startingPopulationSize / 4;
        
        startingPopulationSize = startingPopulationSize + llamasBornt - llamasDead;
        
        years++;
    }
    
    printf("Years: %i", years);
}

int get_population_int (string prompt, int condition)
{
    int n;
    
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < condition);
    
    return n;
}
