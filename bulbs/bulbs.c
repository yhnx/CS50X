#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string sentence = get_string("Message: ");
    int length = strlen(sentence);
    for (int i = 0; i < length; i++)
    {
        int dec_value = sentence[i];
        int dec[8];
        for (int j = 0; j < 8; j++)
        {
            dec[j] = dec_value % 2;
            dec_value = dec_value / 2;
        }
        for (int m = 7; m >= 0; m--)
        {
            int bit = dec[m];
            print_bulb(bit);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
