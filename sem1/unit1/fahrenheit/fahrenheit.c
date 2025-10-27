#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt
    float C = get_float("C ");
    //variable F
    float F = 0;
    //conversion
    F = ((C * 9) / 5) + 32;
    //response
    printf("F %.1f\n", F);
}
