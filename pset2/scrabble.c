#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int wordValue(string word);
//here so ^ can acsess it (if declared in main would be out of scope)
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    //gets players words
    string playerOne = get_string("Player One: ");
    string playerTwo = get_string("Player Two: ");

    //uses our function to get value of word
    int pointsOne = wordValue(playerOne);
    int pointsTwo = wordValue(playerTwo);

    if (pointsOne > pointsTwo)
    {

        printf("Player 1 wins!\n");
        return 0;
    }

     if (pointsTwo > pointsOne)
    {


        printf("Player 2 Wins!\n");
        return 0;
    }
    if(pointsTwo == pointsOne)
    {

        printf("Tie!\n");
        return 0;
    }
}

int wordValue(string word)
{
    // gets length of parameter
    int length = strlen(word);
    //the number we return, it's the value of the word
    int total = 0;

    for (int i = 0; i < length; i++)
    {

        if(isupper(word[i])){


                total += points[word[i] - 'A'];


        }
        else if(islower(word[i]))
        {

            total += points[word[i] - 'a'];

        }


    }

    //final amount of word
    return total;
}
