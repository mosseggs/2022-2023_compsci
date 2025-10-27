#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    //if wrong number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string substitution;
    substitution = argv[1];
    int check = 0;
    int cipher = 0;
    int key = 0;
    int num = 0;
    // calulate cipher length + if the cipher is a number
    while (substitution[cipher] != '\0')
    {
        if (substitution[cipher] >= 'a' && substitution[cipher] <= 'z')
        {
            key = substitution[cipher] - 97;
            substitution[cipher] = substitution[cipher] - 97;
        }
        else if (substitution[cipher] >= 'A' && substitution[cipher] <= 'Z')
        {
            key = substitution[cipher] - 65;
            substitution[cipher] = substitution[cipher] - 65;
        }
        check += (key * key);
        cipher++;
    }
    //check if cipher is 26 letters long, and has only 1 of every letter of the alphabet
    if (cipher != 26 || check != 5525)
    {
        printf("Key must contain the 26 letters of the alphabet, each only once\n");
        return 1;
    }
    cipher = 0;
    //get plaintext, and grab it's length
    string plain = get_string("plaintext: ");
    while (plain[num] != '\0')
    {
        num++;
    }
    int length = num;
    cipher = 0;
    num = 0;
    // cipher the plaintext
    int convert = 0;
    printf("ciphertext: ");
    for (int i = 0, n = length; i < n; i++, num++)
    {
        cipher = 0;
        //if lowercase
        if (plain[num] >= 'a' && plain[num] <= 'z')
        {
            //turn the letter into a number, 0-25. if it doesnt already match to it's designated cipher placeholder, find the cipher placeholder.
            plain[num] = plain[num] - 97;
            if (cipher != plain[num])
            {
                while (cipher < 26 && (cipher != plain[num]))
                {
                    cipher++;
                }
            }
            else
            {
                convert = plain[num];
            }
            // print the ciphered text
            printf("%c", ((convert + (substitution[cipher])) % 26) + 97);
        }
        //if uppercase
        else if (plain[num] >= 'A' && plain[num] <= 'Z')
        {
            // turn the letter into a number, 0-25. if it doesnt already match to it's designated cipher placeholder, find the cipher placeholder.
            plain[num] = plain[num] - 65;
            if (cipher != plain[num])
            {
                while (cipher < 26 && (cipher != plain[num]))
                {
                    cipher++;
                }
            }
            else
            {
                convert = plain[num];
            }
            //print the ciphered text
            printf("%c", ((convert + (substitution[cipher])) % 26) + 65);
        }
        //if a symbol
        else
        {
            printf("%c", plain[num]);
        }
    }
    printf("\n");
    return 0;
}