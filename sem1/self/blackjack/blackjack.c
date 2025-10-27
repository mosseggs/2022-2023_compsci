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
card hand[11];
card hand2[11];
card dealer[10];
bool ace = false;
bool royal = false;
bool win = false;
bool split = false;
bool splitmode = false;
bool down = false;
string surrender = NULL;
string play=NULL;
int cards;
int dcards=2;
int hvalue=0;
int h2value=0;
int dvalue=0;


void new_deck(void);
void deal(void);
void options(void);
bool bust(int sum, card* part);

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
    //hand out cards to dealer and player
    deal();
    if(ace == true && royal == true)
    {
        printf("Dealer: %s of %s, %s of %s\n", dealer[0].number, dealer[0].house, dealer[1].number, dealer[1].house);
        printf("Congrats! You've achieved a Blackjack!\n");
        return 0;
    }
    for(int i = 2; i < 16; i++)
    {
        options();
        if(strcmp(play, "hit") == 0)
        {
            srandom(time(NULL));
            int e = random()%52;
            while(deck[e].used == true)
            {
                e = random()%52;
            }
            deck[e].used=true;
            printf("card number %i\n", e);
            hand[i] = deck[e];
            cards++;
            hvalue+=hand[i].value;
            printf("Hand: ");
            for(int j = 0; j < cards-1; j++)
            {
                printf("%s of %s ", hand[j].number, hand[j].house);
            }
            printf("and %s of %s\n", hand[cards-1].number, hand[cards-1].house);
        }
        if(strcmp(play, "hit") == 0 && splitmode == false)
        {

        }
        if(strcmp(play, "double down") == 0)
        {
            down = true;
            srandom(time(NULL));
            int e = random()%52;
            while(deck[e].used == true)
            {
                e = random()%52;
            }
            deck[e].used=true;
            hand[i] = deck[e];
            cards++;
            hvalue+=hand[i].value;
            printf("Hand: ");
            for(int j = 0; j < cards-1; j++)
            {
                printf("%s of %s, ", hand[j].number, hand[j].house);
            }
            printf("and %s of %s\n", hand[cards-1].number, hand[cards-1].house);
            if(bust(hvalue, hand) == true)
            {
                printf("Bust!\n");
                return 2;
            }
            break;
        }
        //if(strcmp(play, "split") == 0)
        //{
            //printf("Hand 1: %s of %s\n", hand[0].number, hand[0].house);
            //printf("Hand 2: %s of %s\n", hand[1].number, hand[1].house);
            //hand2[0]=hand[1];
            //hvalue-=hand[1].value;
            //h2value=hand2[0].value;
            //hand[1].number = "\0";
            //hand[1].house = "\0";
            //hand[1].value = 0;
            //splitmode=true;
        //}
        if(strcmp(play, "stand") == 0)
        {
            break;
        }
        if(bust(hvalue, hand) == true)
        {
            printf("Bust!\n");
            return 2;
        }
    }
    for(int i = 2; i < 10; i++)
    {
        srandom(time(NULL));
        int e = random()%52;
        while(deck[e].used == true)
        {
            e = random()%52;
        }
        dealer[i]=deck[e];
        dvalue+=dealer[i].value;
        dcards++;
        deck[e].used = true;
        if(dvalue >= 17)
        {
            break;
        }
    }
    printf("Dealer: ");
    for(int i = 0; i < dcards-1; i++)
    {
        printf("%s of %s, ", dealer[i].number, dealer[i].house);
    }
    printf("and %s of %s\n", dealer[dcards-1].number, dealer[dcards-1].house);
    if(bust(dvalue, dealer) == true)
    {
        printf("%i\n", dvalue);
        printf("%i\n", hvalue);
        printf("Congrats! The Dealer has Busted!\n");
        return 0;
    }
    else if(dvalue < hvalue)
    {
        printf("%i\n", dvalue);
        printf("%i\n", hvalue);
        printf("Congrats! You've Won!\n");
        return 0;
    }
    else
    {
        printf("%i\n", dvalue);
        printf("%i\n", hvalue);
        printf("You've Lost!\n");
        return 4;
    }
}

bool bust(int sum, card* part)
{
    if(sum>21)
    {
        for(int j = 0; j < cards; j++)
        {
            if(part[j].value == 11)
            {
                part[j].value=1;
                sum-=10;
            }
            if(sum<=21)
            {
                return false;
            }
        }
        if(sum>21)
        {
            return true;
        }
    }
    return false;
}

void options(void)
{
    printf("Hit, ");
    if(cards == 2)
    {
        printf("Double down, ");
    }
    /*if(strcmp(hand[0].number,hand[1].number) == 0 && cards == 2)
    {
        split = true;
        printf("Split, ");
    }*/
    play = get_string("or Stand: ");
    for(int i = 0; i < strlen(play); i++)
    {
        play[i]=tolower(play[i]);
    }
    while((strcmp(play, "hit") != 0 && strcmp(play, "double down") != 0 && strcmp(play, "stand") != 0 && strcmp(play, "split") != 0) || /*(strcmp(play, "split") == 0 && split != true && cards != 2) ||*/ (strcmp(play, "double down") == 0 && cards != 2) || (strcmp(play, "hit") == 0 && down == true))
    {
        options();
    }
    return;
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

void deal(void)
{
    printf("Dealer: ");
    for(int i = 0; i < 2; i++)
    {
        srandom(time(NULL));
        int e = random()%52;
        while(deck[e].used == true)
        {
            e = random()%52;
        }
        dealer[i]=deck[e];
        dvalue+=dealer[i].value;
        deck[e].used = true;
    }
    printf("%s of %s, ???\n", dealer[0].number, dealer[0].house);
    for(int i = 0; i < 2; i++)
    {
        srandom(time(NULL));
        int e = random()%52;
        while(deck[e].used == true)
        {
            e = random()%52;
        }
        hand[i]=deck[e];
        hvalue+=hand[i].value;
        deck[e].used = true;
        if(strcmp("Ace", hand[i].number)==false)
        {
            ace=true;
        }
        if(strcmp("Jack", hand[i].number)==false || strcmp("Queen", hand[i].number)==false || strcmp("King", hand[i].number)==false)
        {
            royal=true;
        }
    }
    printf("Hand: %s of %s, %s of %s\n", hand[0].number, hand[0].house, hand[1].number, hand[1].house);
    cards=2;
}