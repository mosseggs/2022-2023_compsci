#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

char password[6]={'\0','\0','\0','\0','\0','\0'};
char alphabet[52]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
string crypted="";
char salt[2];
int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./crack <ciphered password>\n");
        return 1;
    }
    salt[0]=argv[1][0];
    salt[1]=argv[1][1];
    for(int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                for (int l = 0; l < 52; l++)
                {
                    for (int m = 0; m < 52; m++)
                    {
                        password[0] = alphabet[m];
                        crypted = crypt(password, salt);
                        printf("%s\n", password);
                        if (strcmp(argv[1], crypted) == false)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                    password[1] = alphabet[l];
                }
                password[2] = alphabet[k];
            }
            password[3] = alphabet[j];
        }
        password[4] = alphabet[i];
    }
}