#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>
#include <stdlib.h>

char a[1];
char b[2];
char c[3];
char d[4];
char e[5];
char f[1];
char g[2];
char h[3];
char i[4];
char j[5];
bool win = false;
int main(int argc, string argv[])
{
    while(win != true)
    {
        a[0] = (rand()/((double) RAND_MAX + 1)*28)+64;
        if(strcmp(crypt(a,"50"), argv[1]))
        {
            printf("a");
            win = true;
        }
        b[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        b[1] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        if (strcmp(crypt(b, "50"), argv[1]))
        {
            printf("2");
            win = true;
        }
        c[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        c[1] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        c[2] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        if (strcmp(crypt(c, "50"), argv[1]))
        {
            printf("3");
            win = true;
        }
        d[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        d[1] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        d[2] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        d[3] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        if (strcmp(crypt(d, "50"), argv[1]))
        {
            printf("4");
            win = true;
        }
        e[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        e[1] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        e[2] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        e[3] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        e[4] = (rand() / ((double)RAND_MAX + 1) * 28) + 64;
        if (strcmp(crypt(e, "50"), argv[1]))
        {
            printf("5");
            win = true;
        }
        f[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        if (strcmp(crypt(f, "50"), argv[1]))
        {
            printf("1");
            win = true;
        }
        g[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        g[1] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        if (strcmp(crypt(g, "50"), argv[1]))
        {
            printf("2");
            win = true;
        }
        h[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        h[1] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        h[2] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        if (strcmp(crypt(h, "50"), argv[1]))
        {
            printf("3");
            win = true;
        }
        i[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        i[1] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        i[2] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        i[3] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        if (strcmp(crypt(i, "50"), argv[1]))
        {
            printf("4");
            win = true;
        }
        j[0] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        j[1] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        j[2] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        j[3] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        j[4] = (rand() / ((double)RAND_MAX + 1) * 28) + 96;
        if (strcmp(crypt(j, "50"), argv[1]))
        {
            printf("5");
            win = true;
        }
    }
}