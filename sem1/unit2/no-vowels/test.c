#include <stdio.h>
#include <cs50.h>
int main()
{
     string word = get_string("word: ");
     int num = 0;
     while (word[num] != '\0')
     {
      char x=word[num];
       switch (x)
       {
       case 'a':
         printf("6");
         break;
       case 'e':
         printf("3");
         break;
       case 'i':
         printf("1");
         break;
       case 'o':
         printf("0");
         break;
       default:
         printf("%c",x);
         break;
       }
       num++;
    }
    printf("\n");
}