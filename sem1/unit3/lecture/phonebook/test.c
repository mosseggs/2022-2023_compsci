#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[].name = {"Carter","David"};

    people[0].number = "1-619-495-1000";

    people[1].number = "+1-949-468-2750";
}