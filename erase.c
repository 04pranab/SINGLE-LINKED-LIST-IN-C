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

void printList(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *erase(node *head)
{
    node *t;
    while (head != NULL)
    {
        t = head;
        head = head->next;

        free(t);
    }
    return NULL;
}

int main() {

    node *head = getnode();
    if (head == NULL) return 1;
    head->data = 1;

    head->next = getnode();
    if (head->next == NULL) return 1;
    head->next->data = 2;


    head->next->next = getnode();
    if (head->next->next == NULL) return 1;
    head->next->next->data = 3;
    head->next->next->next = NULL;


    printf("Original List: ");
    printList(head);


    head = erase(head);


    printf("List after erasing: ");
    printList(head);

    return 0;
}
