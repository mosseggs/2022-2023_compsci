#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    //TODO
    //declare m
    int m = 0;
    //multiply m by 10, and then grab the i'th digit of input and convert it to a number, then add it to m.
    //repeat for as long as input lasts
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        m = m * 10;
        m += (input[i] - 48);
    }
    return m;
}