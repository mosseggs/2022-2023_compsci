#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // if more than 1 command line
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string caesar = argv[1];
    int cipher=0;
    int key = 0;
    // calulate cipher length + if the cipher is a number
    while (caesar[cipher] != '\0')
    {
        if (!isdigit(atoi(caesar)))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        key *= 10;
        key += caesar[cipher] - 48;
        cipher++;
    }
    int num = 0;
    // length of the plaintext
    string plain = get_string("plaintext: ");
    int length = strlen(plain);
    // cipher the plaintext
    printf("ciphertext: ");
    for (int num = 0; num < length; num++)
    {
        // lowercase
        if (islower(plain[num]))
        {
            // converts the Lowercase (as ascii) into lowercase (as numbers)
            int convert = plain[num] - 97;
            // print
            printf("%c", ((convert + key) % 26) + 97);
        }
        // uppercase
        else if (isupper(plain[num]))
        {
            // converts the uppercase (as ascii) into uppercase (as numbers)
            convert = plain[num] - 65;
            // print
            printf("%c", ((convert + key) % 26) + 65);
        }
        //symbols etc.
        else
        {
            printf("%c", plain[num]);
        }
        num++;
    }
    printf("\n");
    return 0;
}