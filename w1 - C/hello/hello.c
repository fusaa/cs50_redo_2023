#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name;  // string variable
    name = get_string("What's your name? ");  // get input
    printf("hello, %s\n", name);
}