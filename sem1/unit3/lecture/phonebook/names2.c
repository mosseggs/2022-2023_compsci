#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    strings names[7] = {"Bill", "Charlie", "Fred", "George", "Percy", "Ginny", "Ron"};
     for (int i = 0; i < 7; i++)
    {
        if (names[i] == "Ron")
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}