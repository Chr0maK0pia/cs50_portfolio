from cs50 import get_string
import string

# L = average number of letters per 100 words
# S = average number of senteces per 100 words.
# readability formula =  0.0588 * L - 0.296 * S - 15.8


def main():
    text = get_string("Enter text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = sent_count(text)

    wordavg = words/100
    L = letters/wordavg
    S = sentences/wordavg

    final_grade = 0.0588 * L - 0.296 * S - 15.8


    Us_grade = int(round(final_grade))


    if (Us_grade < 1):
        print("Before Grade 1")
    elif (Us_grade > 15):
        print("Grade 16+")
    else:
        print(f"Grade {Us_grade}")


def count_letters(text):

    length = len(text)
    count = 0
    for i in range(length):
        if text[i].isalpha():
            count += 1
    return count


def count_words(text):

    length = len(text)
    count = 1
    for i in range(length):
        if text[i].isspace():
            count += 1
    return count


def sent_count(text):

    length = len(text)
    count = 0
    for i in range(length):
        if text[i] in ['.', '!', '?',]:
            count += 1
    print(count)
    return count



main()
