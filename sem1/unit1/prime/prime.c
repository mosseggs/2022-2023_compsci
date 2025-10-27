#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    //ask for minimum
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);
    //ask for maximum
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);
    //say prime numbers
    for (int i = min; i <= max; i++)
    {
        if (prime(i) == true)
        {
            printf("%i\n", i);
        }
    }

}

bool prime(int number)
{
    //TODO
    //non-prime finder counter
    int g;
    g = 1;
    //find non-primes
    for (int f = 2; f < number; f++)
    {
        if (number % f == 0 || number==1)
        {
                g++;
        }
    }
    //look for perfect score
    if (g == 1 && number != 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
