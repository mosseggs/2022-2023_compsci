// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // check if they entered a word
    if (argc != 2)
    {
        return 1;
    }
    // convert the argv word into a disectable string
    string word;
    word = argv[1];
    // if the set of words isnt over yet
    int num = 0;
    while (word[num] != '\0')
    {
        char x = word[num];
        // checks for vowels-u
        switch (x)
        {
            case 'a':
                printf("6");
                break;
            case 'e':
                printf("3");
                break;
            case 'i':
                printf("1");
                break;
            case 'o':
                printf("0");
                break;
            // if not a vowel-u
            default:
                printf("%c", x);
                break;
        }
        // continue the loop
        num++;
    }
    printf("\n");
    return 0;
}