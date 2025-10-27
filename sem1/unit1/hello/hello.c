//includes codes
#include <stdio.h>
#include <cs50.h>
//start code
int main(void)
{
    //ask name
    string name = get_string("whats your name? ");
    //say hello to name
    printf("hello, %s\n", name);

}