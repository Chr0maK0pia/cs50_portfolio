#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#define CAPACITY 25


typedef struct _stack
{

    int VALUE[CAPACITY];
    int top;


}
stack;


void push(stack* s, int VAL);
int pop(stack *s);


int main()
{

    stack s;
    s.top = 0;
    push(&s, 9);
    push(&s, 10);
    push(&s, 11);
    pop(&s);
    push(&s, 12);
    for(int i = 0; i < s.top; i++)
    {

        printf("%i\n", s.VALUE[i]);

    }



}


void push(stack* s, int VAL)
{

    if(s->top < 24)
    {
        s->VALUE[s->top] = VAL;
        s->top++;
    }
    else
    {

        printf("Not enough capacity for new element");

    }
}

int pop(stack *s)
{

    if(s->top > 0)
    {

        s->top--;
        return s->top + 1;

    }
    else
    {


        printf("No elements remaining to pop");
        return 0;
    }




}
