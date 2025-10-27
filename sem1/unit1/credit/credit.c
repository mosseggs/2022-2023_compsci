#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num = 0;
    //ask for the credit card number
    long credit = get_long("Number: ");
    //resetter
    long creditfile = credit;
    //find length of credit
    while (credit != 0)
    {
        credit = credit / 10;
        num++;
    }
    int length = num;
    num = 0;
    credit = creditfile;
    //find the sum of every other value, starting from the back
    int sum = 0;
    credit = credit / 10;
    for (int place = length / 2; place > 0; place--)
    {
        int value = 0;
        int extra = 0;
        value = 2 * (credit % 10);
        //if the value is 10 or over, split the number into their digits and add them together
        if (value >= 10)
        {
            while (value != 0)
            {
                extra += (value % 10);
                value = value / 10;
            }
        }
        credit = credit / 100;
        sum += value + extra;
    }
    credit = creditfile;
    //add the other digits
    int first = 0;
    for (int place = (length + 1) / 2; place > 0; place--)
    {
        int value = 0;
        value = credit % 10;
        //if an even length, just go as is, and if odd, go to the next digit to the left
        if (place == 1 && length % 2 == 0)
        {
            first = credit;
        }
        if (place == 2 && length % 2 != 0)
        {
            first = credit / 10;
        }
        credit = credit / 100;
        sum += value;
    }
    //check if valid
    if ((length >= 13 && length <= 16) && sum % 10 == 0)
    {
        //go through cards, and if not one listed, say invalid
        if (length == 15 && (first == 34 || first == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && first >= 51 && first <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && (first / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}