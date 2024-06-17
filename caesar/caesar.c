#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string s);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    bool h = only_digits(argv[1]);
    if (!h)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int shift = atoi(argv[1]);
    if (shift > 26)
    {
        shift = shift % 26;
    }
    string sentence = get_string("plaintext: ");
    int length = strlen(sentence);
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        char cipher;
        if (isupper(sentence[i])) // checking and implementing for capital letters
        {
            int num = (int) sentence[i] + shift;
            if (num > 90)
            {
                num -= 26;
            }
            cipher = (char) num;

        }
        else if (islower(sentence[i])) // checking and implementing for lowercase letters
        {
            int num = (int) sentence[i] + shift;
            if (num > 122)
            {
                num -= 26;
            }
            cipher = (char) num;
        }
        else
        {
            cipher = sentence[i]; // letting other characters reprint
        }
        printf("%c", cipher); // reprinting the ciphered code
    }
    printf("\n");
}

bool only_digits(string s) // function to see if the key is numeric
{
    int len = strlen(s);
    bool x;
    for (int i = 0; i < len; i++)
    {
        if isdigit(s[i])
        {
            x = true;
        }
        else
        {
            x = false;
            break;
        }
    }
    return x;
}