#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    
    int a = 69;
    int b = 420;

    swap(&a, &b);

}


void swap(int *a, int *b)
{
     
    int temp = *a;
    *a = *b;
    *b = temp; 



}