#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>

#define CAPACITY 10
int overwrite_index = 0;

//queues are like stacks but instead they are FIFO instead of LIFO.
//basically first come first serve
//enqueue is to add an element at the end of a list
//dequeue is to remove an element from the start of the list aka the oldest.
//linked list or array based in this version ima use an array just to get the idea of the structure across.
//works but not perfectly i don't wanna think hard enough about why

typedef struct _queue
{

    int array[CAPACITY];
    int front;
    int size;


}
queue;


void enqueue(queue *q, int VAL);
void print_queue(queue *q);
int dequeue(queue *q);


int main()
{


queue q;
q.front = 0;
q.size = 0;
enqueue(&q, 1);
enqueue(&q, 2);
enqueue(&q, 3);
enqueue(&q, 4);
enqueue(&q, 5);
enqueue(&q, 6);
enqueue(&q, 7);
enqueue(&q, 8);
enqueue(&q, 9);
print_queue(&q);
dequeue(&q);
print_queue(&q);
enqueue(&q, 10);
enqueue(&q, 11);
enqueue(&q, 12);
enqueue(&q, 13);
print_queue(&q);
dequeue(&q);
print_queue(&q);
enqueue(&q, 14);
print_queue(&q);





}

void enqueue(queue *q, int VAL)
{

    if(q->size < 10)
    {
        q->array[q->size + q->front] = VAL;
        q->size++;
    }
    else
    {
       q->array[overwrite_index] = VAL;
       overwrite_index++;
    }
}

int dequeue(queue *q)
{


    if(q->size > 1)
    {
        q->front++;
        q->size--;
        return q->array[q->front - 1];
    }
    else
    {
        printf("No elements left to dequeue");
        return 0;
    }
}

void print_queue(queue *q)
{
    printf("    [Queue]    \n");
    for(int i = 0; i < q->size; i++)
    {
        printf("element %i", i);
        printf(", Value: %i\n", q->array[i]);
    }
}
