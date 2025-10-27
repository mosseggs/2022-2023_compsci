#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

string crack;
int main(int argc, string argv[])
{
    string a = crypt(argv[1],"50");
    printf("%s\n",a);
}