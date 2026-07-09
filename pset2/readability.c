#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//L = average number of letters per 100 words
//S = average number of senteces per 100 words.
// readability formula =  0.0588 * L - 0.296 * S - 15.8

int count_letters(string text);
int count_words(string text);
int sent_count(string text);

int main(void)
{
    //TODO: Get text X
    string text = get_string("Enter text: \n");


    //TODO: Count sentences(periods) X
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = sent_count(text);


    //TODO: get averages x
    double wordavg = words/100.00;

    double L = letters/wordavg;
    double S = sentences/wordavg;

    //TODO: put numbers into werid ass equation x
    double final_grade = 0.0588 * L - 0.296 * S - 15.8;


    int US_grade = round(final_grade);




    //TODO: Convert equation result into grade level x
    if(US_grade < 1)
    {

        printf("Before Grade 1\n");

    }
    else if(US_grade > 15)
    {

        printf("Grade 16+\n");

    }
    else
    {

        printf("Grade %i\n", US_grade);

    }


}


int count_letters(string text)
{

    int length = strlen(text);
    int count = 0;

    for(int i = 0; i < length; i++)
    {

        if(isalpha(text[i]))
        {

            count++;

        }

    }

    return count;


}

int count_words(string text){

    int length = strlen(text);
    int count = 1;

    for(int i = 0; i < length; i++)
    {

        if(text[i] == 32)
        {

            count++;

        }

    }

    return count;





}
int sent_count(string text)
{

    int length = strlen(text);
    int count = 0;

    for(int i = 0; i < length; i++)
    {

        if(text[i] == 46 || text[i] == 63 || text[i] == 33)
        {

            count++;

        }

    }

    return count;





}


