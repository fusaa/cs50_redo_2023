#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_pop;
    do
    {
        start_pop = get_int("Starting Population: ");
    }
    while (start_pop < 9);
    
    // TODO: Prompt for end size
    int end_pop;
    do
    {
        end_pop = get_int("Final Population: ");
    }
    while (end_pop < start_pop);

    // TODO: Calculate number of years until we reach threshold
    // Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
    
    int years = 0;
    int born_llamas_this_year;
    int dead_llamas_this_year;
    int movement_this_year;
    
    while (start_pop < end_pop)
    {
    
        born_llamas_this_year = start_pop + (start_pop / 3);
        dead_llamas_this_year = start_pop + (start_pop / 4);
        movement_this_year = born_llamas_this_year - dead_llamas_this_year;
        start_pop = start_pop + movement_this_year;
        years += 1;
    }
        

    // TODO: Print number of years
    printf("Years: %i\n", years);

}