#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dlnode
{
    struct dlnode *prev;
    struct dlnode *next;
    int val;
} node;

node *create_list(int VAL);
bool search(node *head, int value);
void delete(node *head);
node *insert(node *head, int value);
void print_list(node *head);
void delete_node(node *target);
node *delete_head(node *head);

int main()
{

    node *new_dllist = create_list(7);
    search(new_dllist, 7);
    new_dllist = insert(new_dllist, 8);
    new_dllist = insert(new_dllist, 9);
    node *new_list = new_dllist->next;
    delete_node(new_dllist);
    print_list(new_list);
    delete(new_list);
}

// create new list
node *create_list(int VAL)
{

    node *new_node = malloc(sizeof(new_node));
    if (new_node == NULL)
    {

        return false;
    }

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->val = VAL;

    return new_node;
}

// search list, returns if the number was found.
bool search(node *head, int value)
{

    int find_index = 0;

    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {

        if (ptr->val == value)
        {

            printf("Value was found at index %i \n", find_index);
            return true;
        }
    }

    printf("Value was not found\n");
    return false;
}

// delete list, returns nothing.
void delete(node *head)
{

    node *ptr = head;

    if (ptr == NULL)
    {
        return;
    }

    delete(ptr->next);

    free(ptr);
}

node *insert(node *head, int value)
{

    node *new_head = malloc(sizeof(node));
    if (new_head == NULL)
    {

        return false;
    }

    new_head->val = value;
    new_head->prev = NULL;
    new_head->next = head;
    head->prev = new_head;
    head = new_head;

    return head;
}

void print_list(node *head)
{

    int index = 0;

    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {

        printf("node %i \n", index);
        printf("value: %i \n", ptr->val);
        index++;
    }
}

void delete_node(node *target)
{

    node *before = target->prev;
    node *after = target->next;

    if (target->prev == NULL)
    {

        after->prev = NULL;
        free(target);
    }
    else if (target->next == NULL)
    {

        before->next = NULL;
        free(target);
    }
    else
    {

        before->next = after;
        after->prev = before;

        free(target);
    }
}
