#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int size;
    do
    {
        size = get_int("Size:");
    }
    while (size >= 9 || size < 1);
    
    int blocks_to_print = 0;
    int spaces_to_print = size - 1;
    
    for (int floor = 0; floor < size; floor++)
    {
        blocks_to_print = 0;
        spaces_to_print = size - floor;
        
        // printing left spaces
        for (int a = 1; spaces_to_print  > a; a++)
        {
            printf(" ");
        }
        
        
        // left hashes
        while (blocks_to_print <= floor)
        {
            printf("#");
            blocks_to_print++;
        
        }
        
        // central spaces
        printf("  ");
        
        blocks_to_print = 0;
        
        // right blocks
        while (blocks_to_print <= floor)
        {
            printf("#");
            blocks_to_print++;
        
        }
        
        printf("\n");
    }
}