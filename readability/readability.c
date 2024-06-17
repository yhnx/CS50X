#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string sen = get_string("Text: "); //getting the input

    // counting letters, words and sentences
    int letters = count_letters(sen);
    int words = count_words(sen);
    int sentences = count_sentences(sen);

    //calculating Coleman-Liau index
    float S = ((float) sentences / (float) words) * 100.0;
    float L = ((float) letters / (float) words) * 100.0;
    float X = (0.0588 * L) - (0.296 * S) - 15.8;

    //printing the output
    if (X < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (X >= 15.5)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int n = round(X);
        printf("Grade %i\n", n);
    }
}


int count_letters(string text) //function to count letters
{
    int x = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isupper(text[i]))
        {
            x++;
        }
        if (islower(text[i]))
        {
            x++;
        }
    }
    return x;
}

int count_words(string text) //function to count words
{
    int x = 1;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == 32)
        {
            x++;
        }

    }
    return x;
}

int count_sentences(string text) //function to count sentences
{
    int x = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            x++;
        }

    }
    return x;
}