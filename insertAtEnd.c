#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int ele;
    struct node *next;
} node;

node *getnode()
{
    node *a;
    a = (node *) malloc(sizeof(node));

    if (a == NULL)
    {
        printf("Memory Allocating Failed. \n");
        return NULL;
    }
    else
    {
        return a;
    }
}

node *InsertAtEnd(node* head, int a)
{
    node *x = getnode();
    if (x == NULL)
    {
        printf("Error Memory Allocation\n");
        return head;
    }

    node *current = head;

    x->ele = a;
    x->next = NULL;

    if (head == NULL)
    {
        return x;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = x;
    }

    return head;
}

void printList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->ele);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;
    int choice, value;

    while (1)
    {
        printf("Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Print List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = InsertAtEnd(head, value);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
