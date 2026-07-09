#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{

    node *list = NULL;
    int size = 10;

    for (int i = 0; i < size; i++)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            temp = list;
            for (int j = 0; j < i; j++)
            {
                node *next = temp->next;
                free(temp);
                temp = next;
            }
            return 1;
        }
        temp->number = get_int("Number: ");
        temp->next = NULL;

        if (list == NULL)
        {

            list = temp;
        }
        else if (temp->number < list->number)
        {
            temp->next = list;
            list = temp;
        }
        else
        {

            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {

                if (ptr->next == NULL)
                {

                    ptr->next = temp;
                    break;
                }

                if (temp->number < ptr->next->number)
                {

                    temp->next = ptr->next;
                    ptr->next = temp;
                    break;
                }
            }
        }
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}