#include <cs50.h>
#include <stdio.h>
int main(void)
{
    //get isbn #
    long isbn = get_long("ISBN: ");
    int sum = 0;
    //find place #
    for (int place = 10; place > 0; place--)
    {
        int value = 0;
        value = place * (isbn % 10);
        isbn = isbn / 10;
        //find sum of all values
        sum += value;
    }
    //check if valid
    if (sum % 11 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}