#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{

    char *s = get_string("Enter string: ");
    //get_string auto handles mem.

    char *t = malloc(strlen(s) + 1);

    

    for(int i = 0, n = strlen(s); i < n; i++)
    {

        t[i] = s[i];

    }

    s[0] = toupper(s[0]);


    printf("String one:%p\n", s);

    printf("String two:%p\n", t);

    printf("String one: %s\n", s);

    printf("String two: %s\n", t);

    free(t);


}
    
    