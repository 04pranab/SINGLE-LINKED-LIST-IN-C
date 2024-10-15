#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *getnode() {
    node *a;
    a = (node *)malloc(sizeof(node));

    if (a == NULL) {
        printf("Memory Allocation Failed.\n");
        return NULL;
    } else {
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



node *InsertAtEnd(node* head, int a)
{
    node *x = getnode();
    if (x == NULL)
    {
        printf("Error Memory Allocation\n");
        return head;
    }

    node *current = head;

    x->data = a;
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


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(node *head) 
{
    node *p;
    int n = count(head);
    for(int i = 0; i < n;i++)
    {
        p = head;
        for(int j = 0; j < n-i-1; j++)
        {
            if (p->data > p->next->data)
            {
                swap(&(p->data),&(p->next->data));
            }

            p = p->next;
        }

    }
}

void printList(node *head) 
{
    node *temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main()
{
    int n, a;
    printf("Enter Length for Linked-List :");
    scanf("%d",&n);

    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data(%d): ",i+1);
        scanf("%d",&a);

        head = InsertAtEnd(head, a);
    }

    printf("Intial List is :\n");
    printList(head);

    printf("After Bubble Sort :\n");
    bubble(head);
    printList(head);
    printf("\n");
    
}

