#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //get name, and prep initials to be listed
    string name = get_string("Name: ");
    printf("initials: ");
    //get string length(from "string" lecture tutorial)
    for (int num = 0; num < strlen(name); num++)
    {
        //mostly taken from "passwords" practice problem, which was obtained from "Uppercase" lecture tutorial
        if ((num == 0 && isalpha(name[0])) || (!isalpha(name[num - 1]) && isalpha(name[num])))
        {
            //wholeheartedly from "Uppercase" lecture tutorial
            if (islower(name[num]))
            {
                printf("%c", name[num] - 32);
            }
            else
            {
                printf("%c", name[num]);
            }
        }
    }
    //new line
    printf("\n");
}