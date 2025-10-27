#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // if more than 1 command line
    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    //its easier to write vigenere[i] rather than argv[1][i]
    string vigenere = argv[1];
    //convert argv[1] into uppercase, and check to make sure its only the alphabet
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        vigenere[i] = toupper(vigenere[i]);
        if (!isalpha(vigenere[i]))
        {
            printf("Usage: ./vigenere key\n");
            return 1;
        }
    }
    string plain = get_string("plaintext: ");
    // cipher the plaintext
    printf("ciphertext: ");
    int casing = 0;
    for (int i = 0, j = 0; i < strlen(plain); i++)
    {
        //check if its a letter, if not, ignore it.
        if (isalpha(plain[i]))
        {
            //if the end of vigenere is reached, cycle to the start
            if (j >= strlen(vigenere))
            {
                j = 0;
            }
            //makes the computation easier, adding 65 turns it uppercase and if its lowercase it adds 32.
            casing = 65 + ((islower(plain[i]) / 512) * 32);
            //change plain's i'th character to be 0-25, add a 0-25 scale version of the j'th character of the vigenere,
            //mod it by 26 to cycle it around if needed, and lastly turn it back to its orginal casing.
            plain[i] = (((plain[i] - casing) + (vigenere[j] - 65)) % 26) + casing;
            //we only increase j if its been used
            j++;
        }
    }
    //print
    printf("%s\n", plain);
    return 0;
}