#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // gets phrase(duh)
    string phrase = get_string("Enter phrase: ");
    int length = strlen(phrase);

    for (int i = 0; i < length; i++)
    {

            // check if index is out of bounds, if so doesn't check.
            if (i + 1 < length)
            {
                // if the char of i is higher the the next char then its not alphabetical
                // ascii a = 65, b = 66, 65 > 66, ab is alphabetical
                if(phrase[i + 1] < phrase[i])
                {
                    //return zero ends the run
                    printf(" Is not alphabetical. \n");
                    return 0;

                }
            }



    }
        // if non-alphabetical order isn't detected the for loops ends and this prints.
        printf("is alphabetical \n");

}
