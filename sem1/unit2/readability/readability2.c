#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int letters=0;
    float words=0;
    int sentences=0;
    string s=get_string("Text: ");
    //calc letters,words,and sentences respectivley;
    for (int num=0; num < strlen(s) + 1; num++)
    {
        if (isalpha(s[num]))
        {
            letters++;
        }
        else if(s[num] == ' ' || s[num] == '\0')
        {
            words++;
        }
        else if (s[num] == '!' || s[num] == '?' || s[num] == '.')
        {
            sentences++;
        }
    }


    //Grading
    //within range
    float grade = (0.0588 * ((letters / words) * 100) - 0.296 * (sentences / words * 100) - 15.8);
    printf("%i, %f, %i, %f\n", letters,words,sentences,grade);
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %d\n", (int)round(grade));
    }
    //below
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    //above
    else
    {
        printf("Grade 16+\n");
    }
}