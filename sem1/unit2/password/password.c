// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    //beginning integers
    int num = 0;
    bool lower = false;
    bool upper = false;
    bool symbol = false;
    bool number = false;
    //count the length
    while (password[num] != '\0')
    {
        num++;
    }
    int length = num;
    //reset num to 0, so it starts at 0 instead of the length
    num = 0;
    //set the run time
    for (int i = 0, n = length; i < n; i++)
    {
        //if it has a lowercase letter
        if (password[num] >= 'a' && password[num] <= 'z')
        {
            lower = true;
        }
        //if it has an uppercase letter
        if (password[num] >= 'A' && password[num] <= 'Z')
        {
            upper = true;
        }
        //if it has a symbol
        if (password[num] >= '!' && password[num] <= '/')
        {
            symbol = true;
        }
        //if it has a number
        if (password[num] >= '0' && password[num] <= '9')
        {
            number = true;
        }
        num++;
    }
    //check that all conditions are met
    if (lower == true && upper == true && symbol == true && number == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
