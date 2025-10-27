#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //checks to make sure its only 1 word long
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //checks to make sure if it's 26 characters long, no repeats, and that its only letters
    //also sets the whole key to uppercase, and locks off the cipherletter to prevent repeats
    bool thing[26] = {false};
    for (int i = 0; i <= 25; i++)
    {
        argv[1][i] = toupper(argv[1][i]);
        if (thing[argv[1][i] - 65] == true || strlen(argv[1]) >= 27 || !isalpha(argv[1][i]))
        {
            printf("Key must only contain the 26 letters in the alphabet, each only once\n");
            return 1;
        }
        else if (isalpha(argv[1][i]))
        {
            thing[argv[1][i] - 65] = true;
        }
    }
    //ask for the plaintext, and sets up ciphertext
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = 0; i < strlen(plain); i++)
    {
        //if letter
        if (isalpha(plain[i]))
        {
            n = 0;
            //increases n until the its equal to the letter at place i's place in the alphabet-1
            while (plain[i] - 65 != n && plain[i] - 97 != n)
            {
                n++;
            }
            //adds the ciphered letter to either 0 or 32, depending on if the plaintext letter is upper or lowercase
            //islower will give a value of 512 if true. isupper will give a value of 256 if true. both give 0 if not
            printf("%c", argv[1][n] + ((islower(plain[i]) / 512) * 32));
        }
        //if symbol
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}