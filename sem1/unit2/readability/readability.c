#include <cs50.h>
#include <stdio.h>
#include <math.h>
int count_letters(string text, int length);
float count_words(string text, int length);
int count_sentence(string text, int length);
int num = 0;
int main(void)
{
    string text = get_string("Text: ");
    while (text[num] != '\0')
    {
        num++;
    }
    int length = num;
    num = 0;
    // index = 0.0588 * L - 0.296 * S - 15.8
    float sum = (0.0588 * ((count_letters(text, length) / count_words(text, length)) * 100) - 0.296 * ((count_sentence(text,
                 length) / count_words(text, length)) * 100) - 15.8);
    printf("%i, %f, %i \n", count_letters(text, length), count_words(text,length), count_sentence(text,length));
    //Grading
    //within range
    if (sum >= 1 && sum <= 16)
    {
        printf("Grade %d\n", (int)round(sum));
    }
    //below
    else if (sum < 1)
    {
        printf("Before Grade 1\n");
    }
    //above
    else if (sum > 16)
    {
        printf("Grade 16+\n");
    }
}
//functions
//Letters
int count_letters(string text, int length)
{
    int letters = 0;
    for (int i = 0, n = length + 1; i < n; i++)
    {
        if ((text[num] >= 'a' && text[num] <= 'z') || (text[num] >= 'A' && text[num] <= 'Z'))
        {
            letters++;
        }
        num++;
    }
    num = 0;
    return letters;
}
//words
float count_words(string text, int length)
{
    int words = 0;
    for (int i = 0, n = length + 1; i < n; i++)
    {
        if (text[num] == ' ' || text[num] == '\0')
        {
            words++;
        }
        num++;
    }
    num = 0;
    return words;
}
//sentences
int count_sentence(string text, int length)
{
    int sentence = 0;
    for (int i = 0, n = length + 1; i < n; i++)
    {
        if (text[num] == '!' || text[num] == '?' || text[num] == '.')
        {
            sentence++;
        }
        num++;
    }
    num = 0;
    return sentence;
}
//this would be so much easier without a function