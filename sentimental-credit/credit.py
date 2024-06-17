# import the cs50 library
import cs50

# get the credit card number
result = ""
credit_card = cs50.get_int("Number: ")
if credit_card > 9999999999999999 or credit_card < 1000000000000:
    result = "INVALID"
else:
    # calculate the checksum
    tot = 0
    num = 0
    for pw in range(16):
        x = 10**pw
        num = (credit_card // x) % 10
        if pw % 2 == 1:
            num = num * 2
        if num >= 10:
            num = (num % 10) + ((num // 10) % 10)
        tot += num
    if tot % 10 != 0:
        result = "INVALID"
    else:
        # checking for card length and starting digits
        m = (credit_card // 1000000000000) % 10
        n = (credit_card // 10000000000000) % 10
        o = (credit_card // 100000000000000) % 10
        p = (credit_card // 1000000000000000) % 10
        if p == 5 and (
            o == 1 or o == 2 or o == 3 or o == 4 or o == 5
        ):  # checking whether mastercard
            result = "MASTERCARD"
        elif p == 0 and o == 3 and (n == 4 or n == 7):  # checking whether amex
            result = "AMEX"
        elif p == 4 or (
            p == 0 and o == 0 and n == 0 and m == 4
        ):  # checking whether visa
            result = "VISA"
        else:  # agrees with luhn algorithm but doesnt go with the rest
            result = "INVALID"
# printing out the results
print(result)
