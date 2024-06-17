#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // get the credit card number
    string result;
    long credit_card = get_long("Number: ");
    if (credit_card > 9999999999999999 || credit_card < 1000000000000)
    {
        result = "INVALID";

    }
    else
    {
        // calculate the checksum

        int tot = 0;
        int num;
        for (int pw = 0; pw < 16; pw++)
        {
            long x = pow(10, pw);
            num = (credit_card / x) % 10;
            if (pw % 2 == 1)
            {
                num = num * 2;
            }
            if (num >= 10)
            {
                num = (num % 10) + ((num / 10) % 10);

            }
            tot += num;
        }
        if (tot % 10 != 0)
        {
            result = "INVALID";
        }
        else
        {
            //checking for card length and starting digits

            int m, n, o, p;
            m = (credit_card / 1000000000000) % 10;
            n = (credit_card / 10000000000000) % 10;
            o = (credit_card / 100000000000000) % 10;
            p = (credit_card / 1000000000000000) % 10;

            if (p == 5 && (o == 1 || o == 2 || o == 3 || o == 4 || o == 5)) //checking whether mastercard
            {
                result = "MASTERCARD";
            }
            else if (p == 0 && o == 3 && (n == 4 || n == 7))  //checking whether amex
            {
                result = "AMEX";
            }
            else if (p == 4 || (p == 0 && o == 0 && n == 0 && m == 4)) //checking whether visa
            {
                result = "VISA";
            }
            else // agrees with lung algorithm but doesnt go with the rest
            {
                result = "INVALID";
            }
        }
    }
    //printing out the results
    printf("%s\n", result);
}