#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height;
    int Space_amt;
    bool hasRun = false;
    do
    {

        Height = get_int("height: ");
        Space_amt = Height * 2;

    }
    while (Height < 1 || Height > 8);

    for (int i = 1; i < Height + 1; i++)
    {
        // row count is equal to i
        // your row count is HALF of what you need print.
        //  use \n at end of every row loop
        for (int y = Space_amt - 2; y > 0; y -= 2)
        {

            printf(" ");
        }

        hasRun = false;

        for (int j = 0; j < 2; j++)
        {

            for (int a = 0; a < i; a++)
            {

                printf("#");
            }

            if (hasRun == false)
            {
                printf("  ");
                hasRun = true;
            }

        }

        printf("\n");
        Space_amt -= 2;
    }
}
