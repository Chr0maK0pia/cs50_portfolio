#include <stdio.h>
#include <cs50.h>
#include<string.h>

int main(void)
{

string word = get_string("Convert to ASCII: ");
int length = strlen(word);

for(int i = 0; i < length; i++)
{

    printf(" %i", word[i]);


}

printf("\n");



}
