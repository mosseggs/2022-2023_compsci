#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

int main(void)
{
    string a = "b";
    string b = "a";
    printf("%c, %i", b[0], a[0]);
    char c = b[0];
    printf("%c, %i", c, a[0]);
    a[0] = c;
    return 0;
}