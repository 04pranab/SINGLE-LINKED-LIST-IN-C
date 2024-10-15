#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ele;
    struct node *next;
} node;

node *getnode()
{
    node *a;
    a = (node *)malloc(sizeof(node));

    if (a == NULL)
    {
        printf("Memory Allocating Failed.\n");
        return NULL;
    }
    else
    {
        return a;
    }
}

int count(node *head)
{
    int c = 0;
    node *current = head;

    if (head == NULL)
    {
        printf("LinkedList is Empty.\n");
    }
    else
    {
        while (current != NULL)
        {
            c++;
            current = current->next;
        }
    }

    return c;
}

int main()
{
    node *head = getnode();
    if (head == NULL) return 1;

    head->ele = 1;
    head->next = getnode();
    if (head->next == NULL) return 1;

    head->next->ele = 2;
    head->next->next = getnode();
    if (head->next->next == NULL) return 1;
    head->next->next->ele = 3;
    head->next->next->next = NULL;

    int node_count = count(head);
    printf("The number of nodes in the linked list: %d\n", node_count);

    node *current = head;
    node *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
