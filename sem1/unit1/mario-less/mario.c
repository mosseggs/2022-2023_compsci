#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask for heights
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //reverse it
    for (int i = 1; i <= height; i++)
    {
        //print the spaces beforehand
        for (int k = 1; k <= height - i; k++)
        {
            printf(" ");
        }
        //print the hashtags
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
