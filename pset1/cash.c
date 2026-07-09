#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int CalcQuarters(int cents);
    int CalcDimes(int cents);
    int CalcNickels(int cents);
    int CalcPennies(int cents);
    int input;
    int change = 0;
    int cents;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    // predefines everything so when we define the amounts they are on point

    do
    {
        input = get_int("Cents: ");
        // get cents
    }
    while (input < 0);
    // check to make sure value is positve

    cents = input;
    // sets cents to input so it doesn't directly affect input just to avoid errors
    quarters = CalcQuarters(cents);
    // sets variable quarters to how many quarter you need for currents cents
    change += quarters;
    // adds it to final total
    cents -= quarters * 25;
    // subtracts from cents so we know when we hit our input amount
    // this does what we do with quarters but with different values, makes sure there ethier is
    // still cents left or the value was too  low for the last amt
    if (quarters == 0 || cents > 0)
    {
        dimes = CalcDimes(cents);
        change += dimes;
        cents -= dimes * 10;
    }
    if (dimes == 0 || cents > 0)
    {
        nickels = CalcNickels(cents);
        change += nickels;
        cents -= nickels * 5;
    }
   if (nickels == 0 || cents > 0)
    {

        pennies = CalcPennies(cents);
        change += pennies;
        cents -= pennies * 1;
    }

    // prints total
    printf("%i\n", change);
}

// for every time we are able to subtract from our total by the value of the coin it returns that
// amt, these all repeat except for the coin val
int CalcQuarters(int cents)
{
    int Quarters = 0;
    while (cents >= 25)
    {

        cents -= 25;
        Quarters++;
    }

    return Quarters;
}
int CalcDimes(int cents)
{

    int Dimes = 0;
    while (cents >= 10)
    {

        cents -= 10;
        Dimes++;
    }

    return Dimes;
}
int CalcNickels(int cents)
{

    int Nickels = 0;
    while (cents >= 5)
    {

        cents -= 5;
        Nickels++;
    }

    return Nickels;
}
int CalcPennies(int cents)
{

    int Pennies = 0;
    while (cents >= 1)
    {

        cents -= 1;
        Pennies++;
    }

    return Pennies;
}
