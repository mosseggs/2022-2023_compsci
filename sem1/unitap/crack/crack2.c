#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

char password[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
char alphabet[53] = {'\0','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
string salt="50";
void recursion(string argv, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack2 <ciphered password>\n");
        return 1;
    }
    if(argv[1][1] == '1')
    {
        salt = "51";
    }
    int length = get_int("Password Max length: ");
    recursion(argv[1], length);
    printf("%s\n", password);
}
void recursion(string argv, int n)
{
    for (int i = 0; i < 53; i++)
    {
        if (strcmp(argv, crypt(password, salt)) == false)
        {
            return;
        }
        password[n] = alphabet[i];
        printf("%s, %c, %c, %s, %s\n",password, password[n], alphabet[i], salt, argv);
        if (n < 0)
        {
            return;
        }
        recursion(argv, n-1);
    }
}