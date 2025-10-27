#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string c = argv[2];
    //checks for correct amount of command line arguments & only 1 math symbol
    if (argc != 4 || strlen(c) != 1)
    {
        printf("Usage: ./calc <number> <+, -, x, /, or %% > <number>\n");
        return 1;
    }
    //only numbers, ., or - for 1st and 3rd command line arguments
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0 && argv[1][i] != '.' && argv[1][i] != '-')
        {
            printf("Usage: ./calc <number> <+, -, x, /, or %% > <number>\n");
            return 1;
        }
    }
    for (int i = 0; i < strlen(argv[3]); i++)
    {
        if (isdigit(argv[3][i]) == 0 && argv[3][i] != '.' && argv[3][i] != '-')
        {
            printf("Usage: ./calc <number> <+, -, x, /, or %% > <number>\n");
            return 1;
        }
    }
    //setup variables, convert argv[1] and [3] into floats.
    float a = atof(argv[1]);
    float b = atof(argv[3]);
    float d = 0;
    int e = (int)(a / b);
    //switch case based on math symbol
    switch (argv[2][0])
    {
        case '+' :
            d = a + b;
            break;
        case '-' :
            d = a - b;
            break;
        case 'x' :
            d = a * b;
            break;
        case '/' :
            d = a / b;
            break;
        case '%' :
            d = a - (b * e);
            break;
        default :
            printf("Usage: ./calc <number> <+, -, x, /, or %% > <number>\n");
            return 1;
    }
    //print
    printf("%f\n", d);
}
