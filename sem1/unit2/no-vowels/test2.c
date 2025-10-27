#include <stdio.h>
#include <cs50.h>
int main()
{

    /* local variable definition */
    int grade;
    string grader[grade];
    grader[grade] = get_string("Hi ");

    switch (grader[grade])
    {
    case 'A':
        printf("Excellent!\n");
        break;
    case 'B':
    case 'C':
        printf("Well done\n");
        break;
    case 'D':
        printf("You passed\n");
        break;
    case 'F':
        printf("Better try again\n");
        break;
    default:
        printf("Invalid grade\n");
    }

    printf("Your grade is  %c\n", grade);

    return 0;
}