#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

string crack;
string recursion(string a, string b, string c[], int i);
int main(int argc, string argv[])
{
    char a[6]={'a','b','\0','\0','\0','\0'};
    string b = NULL;
    for(int i=0; i<5;i++)
    {
        recursion(a,b,argv[1],i);
    printf("%s\n",b);
    printf("%s\n", a);
    }

}
int k=-1;
string recursion(string a, string b,string c[], int i)
{
    for(int j=0; j<52; j++)
    {
        if(j<26)
        {
            a[i]=j+65;
            b = crypt(a, "50");
            if(strcmp(argv[1],b))
            {
                return;
            }
        }
        else
        {
            a[i]=j+71;
            b = crypt(a, "50");
            if(strcmp(argv[1],b))
            {
                return;
            }
        }
        if(i>0)
        {
            recursion(a, b, argv[1], i-1);
        }
    }
    return;
}