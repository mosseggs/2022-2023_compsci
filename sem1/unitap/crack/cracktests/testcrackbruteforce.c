#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>
string g;
string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string b;
string c;
int main(int argc, string argv[])
{
    for (int m = 0; m < 52; m++)
    {
        b = "a";
        printf("%i\n",m);
        printf("%c\n", a[m]);
        b[0] = a[m];
        printf("1");
        c = crypt(b, "50");
        if (strcmp(argv[1], c) == true)
        {
            printf("%s\n", b);
            return 0;
        }
    }
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            b[0] = a[j];
            b[1] = a[i];
        }
    }
    c = crypt(b, "50");
    if (strcmp(argv[1], c) == true)
    {
        printf("%s\n", b);
        return 0;
    }
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                b[0] = a[k];
                b[1] = a[j];
                b[2] = a[i];
            }
        }
    }
    c = crypt(b, "50");
    if (strcmp(argv[1], c) == true)
    {
        printf("%s\n", b);
        return 0;
    }
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                for (int l = 0; l < 52; l++)
                {
                        b[0] = a[l];
                        b[1] = a[k];
                        b[2] = a[j];
                        b[3] = a[i];
                }
            }
        }
    }
    c = crypt(b, "50");
    if (strcmp(argv[1], c) == true)
    {
        printf("%s\n", b);
        return 0;
    }
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
                        b[0] = a[m];
                        b[1] = a[l];
                        b[2] = a[k];
                        b[3] = a[j];
                        b[4] = a[i];
                    }
                }
            }
        }
    }
    c = crypt(b, "50");
    if(strcmp(argv[1], c)==true)
    {
        printf("%s\n", b);
        return 0;
    }
}