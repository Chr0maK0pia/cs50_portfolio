#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{

    int val;
    struct list *next;

} node;

node *create(int VAL);
bool find(node *head, int VAL);
node *insert(node *head, int node_val);
void print_list(node *head);
void destroy(node *head);

int main()
{
    node *new_list = create(7);
    new_list = insert(new_list, 8);
    new_list = insert(new_list, 9);
    print_list(new_list);
    find(new_list, 10);
    find(new_list, 8);
    destroy(new_list);
}

// returns a pointer to the head of the list, returns NULL if
//  the list couldn't be created.
node *create(int VAL)
{
    node *head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Could not create list, no space.");
        return NULL;
    }

    head->val = VAL;
    head->next = NULL;
    // this is the only node in the list as it
    // was the first to be created, its the head.
    return head;
}

// looks through the list provided in first parameter
// to find the value in the second, returns true/false
// depending if the value is found (I think also returning the node
// index in which it was found would be useful but i'm just going
// along witht the vid, so I'll print it instead.
bool find(node *head, int VAL)
{
    int find_index = 0;
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {

        if (ptr->val == VAL)
        {
            printf("%i ", VAL);
            printf("is at index %i \n", find_index);
            return true;
        }

        find_index++;
    }

    printf("%i is not found in list.\n", VAL);
    return false;
}

// returns new head of list, NULL if it couldn't be created.
node *insert(node *head, int node_val)
{

    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {

        return NULL;
    }

    new_node->val = node_val;
    new_node->next = head;
    head = new_node;

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
// so this really confused me at first but i figured out why it works.
// basically when the function calls it's self it pauses at there
// and is waiting in the call stack for it to be processed
// so when the function returns all the piled up destory() calls
// resume in a lifo order
// they resume AFTER the destroy call basically just running the free(ptr)
// so then it goes all the way back free each of the pointers.
// this destroys the list, preventing mem leaks
// the video did a very bad job of explaining this becuase THEY DIDN'T EXPLAIN ANYTHING ABOUT WHAT A
// CALL STACK WAS OR THAT IT EVEN EXISTED KJFHSKJDHfK so I thought i had to figure out how to
// program my own call stack without
//  even knowing what it was. but it's okay, i figured out with the help of stack overflow :). its
//  beautiful i know
void destroy(node *head)
{

    node *ptr = head;

    if (ptr == NULL)
    {

        return;
    }

    destroy(ptr->next);

    free(ptr);
}
