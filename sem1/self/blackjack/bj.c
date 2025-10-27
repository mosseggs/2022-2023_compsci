#define __STDC_WANT_IEC_60559_BFP_EXT__
#define _DEFAULT_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

typedef struct
{
    string number;
    string house;
    int value;
    bool used;
}
card;

card deck[52];
card hand[4][11];
card dealer[10];
bool ace = false;
bool royal = false;
string surrender = NULL;
string play=NULL;

void new_deck(void);
void deal(void);

int main(void)
{
    //pre-emptive surrender
    surrender = get_string("Surrender? y/n\n");
    if(!strcasecmp(surrender, "y") || !strcasecmp(surrender, "yes"))
    {
        printf("You have quit. Have a nice day.\n");
        return 1;
    }
     //makes a new deck
    new_deck();
}
void deal(void)
{

}

void new_deck(void)
{
    for(int i = 0, counter = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            switch(j)
            {
                case 0:
                    deck[counter].number="Ace";
                    deck[counter].value=11;
                    break;
                case 1:
                    deck[counter].number="2";
                    deck[counter].value=2;
                    break;
                case 2:
                    deck[counter].number="3";
                    deck[counter].value=3;
                    break;
                case 3:
                    deck[counter].number="4";
                    deck[counter].value=4;
                    break;
                case 4:
                    deck[counter].number="5";
                    deck[counter].value=5;
                    break;
                case 5:
                    deck[counter].number="6";
                    deck[counter].value=6;
                    break;
                case 6:
                    deck[counter].number="7";
                    deck[counter].value=7;
                    break;
                case 7:
                    deck[counter].number="8";
                    deck[counter].value=8;
                    break;
                case 8:
                    deck[counter].number="9";
                    deck[counter].value=9;
                    break;
                case 9:
                    deck[counter].number="10";
                    deck[counter].value=10;
                    break;
                case 10:
                    deck[counter].number="Jack";
                    deck[counter].value=10;
                    break;
                case 11:
                    deck[counter].number="Queen";
                    deck[counter].value=10;
                    break;
                case 12:
                    deck[counter].number="King";
                    deck[counter].value=10;
                    break;
            }
            switch(i)
            {
                case 0:
                    deck[counter].house="Spades♠";
                    break;
                case 1:
                    deck[counter].house="Diamonds♦";
                    break;
                case 2:
                    deck[counter].house="Clubs♣";
                    break;
                case 3:
                    deck[counter].house="Hearts♥";
                    break;
            }
            counter++;
        }
    }
}
