#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *getnode() {
    node *a = (node *)malloc(sizeof(node));
    if (a == NULL) {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }
    return a;
}

node *delete(node *head, int x)
{
    node *temp = NULL, *current = head;

    if (head->data == x)
        {
            head = head->next;
            free(current);
            return head;
        }
    else
    {
            while (current != NULL)
        { 
            if ((current->next->data) == x)
            {
                temp = current -> next;
                current -> next = temp -> next;
                free(temp);
                return head;
            }
            else
            {
                current = current->next;
            }
        }
    }
    

    return head;
}

void printList(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main()
{
    node *head = getnode();
    head->data = 1;
    head->next = getnode();
    head->next->data = 2;
    head->next->next = getnode();
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Original List: ");
    printList(head);

    head = delete(head, 2);

    printf("List after deleting 2: ");
    printList(head);

    return 0;
}