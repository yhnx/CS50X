# import the cs50 library
import cs50


# define the functions to count letters, words and sentences
def count_letters(text):
    # initialize the counter
    x = 0
    # loop through each character in the text
    for char in text:
        # check if the character is upper or lower case
        if char.isupper() or char.islower():
            # increment the counter
            x += 1
    # return the counter
    return x


def count_words(text):
    # initialize the counter
    x = 1
    # loop through each character in the text
    for char in text:
        # check if the character is a space
        if char == " ":
            # increment the counter
            x += 1
    # return the counter
    return x


def count_sentences(text):
    # initialize the counter
    x = 0
    # loop through each character in the text
    for char in text:
        # check if the character is a period, exclamation mark or question mark
        if char == "." or char == "!" or char == "?":
            # increment the counter
            x += 1
    # return the counter
    return x


# get the input text
sen = cs50.get_string("Text: ")

# count the letters, words and sentences
letters = count_letters(sen)
words = count_words(sen)
sentences = count_sentences(sen)

# calculate the Coleman-Liau index
S = (sentences / words) * 100.0
L = (letters / words) * 100.0
X = (0.0588 * L) - (0.296 * S) - 15.8

# print the output
if X < 1:
    print("Before Grade 1")
elif X >= 15.5:
    print("Grade 16+")
else:
    n = round(X)
    print(f"Grade {n}")
