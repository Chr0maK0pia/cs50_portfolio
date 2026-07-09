#include <stdio.h>
#include <cs50.h>

int add(int a, int b);

int main(void)
{

  int x = get_int("What's X?");
  int y = get_int("What's Y?");


   printf("%i\n", add(x,y));


}

int add(int a, int b)
{



    return a + b;


}
