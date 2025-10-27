#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

char a[6]={'\0','\0','\0','\0','\0','\0'};
char b[52]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
string c="";
string d="50";
string e = NULL;
int f = 5;
int g = 5;
void recursion(string plaintext, string alphabet, string crypt, string salt, string argv, int placement);
int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./test5 <ciphered password>");
        return 1;
    }
    if(argv[1][1]=='1')
    {
        d="51";
    }
    e = argv[1];
    recursion(a, b, c, d, e, f);
    printf("%s\n", a);
}
int h = 0;
void recursion(string plaintext, string alphabet, string crypts, string salt, string argv, int placement)
{
    printf("%i\n", placement);
    printf("%s, %s, %s, %s, %i, %i, %i\n", plaintext,crypts, salt, argv, placement, g, h);
    if (placement < 1)
    {
        return;
    }
    recursion(plaintext, alphabet, crypts, salt, argv, placement - 1);
    h++;
    for (int m = 0; m < 52; m++)
    {
        printf("3");
        plaintext[placement-1] = alphabet[m];
        printf("4 %c, %i \n", plaintext[placement], placement);
        crypts = crypt(plaintext, salt);
        printf("%s, %s, %s, %s, %i, %i, %i\n", plaintext, crypts, salt, argv, placement, g, h);
        if (strcmp(crypts, argv) == false || strcmp(crypts, "zzzzz") == false)
        {
            printf("1 %s\n", plaintext);
            return;
        }
    }
    printf("2\n");
}