
#include <stdio.h>
#include <cs50.h>


int main(void)
{

        int array_length = 24;


        int dbu[array_length];

        dbu[0] = 1;
        printf("\n");
        printf("Value: %i", dbu[0]);
        printf("\n");


      for(int i = 1; i < array_length; i++)
      {


        dbu[i] = dbu[i - 1] * 2;
        printf("\n");
        printf("Value: %i", dbu[i]);
        printf("\n");



      }

}
