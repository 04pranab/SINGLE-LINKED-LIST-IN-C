#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int ele;
    struct node *next;
} node;

node *getnode() {
    node *a;
    a = (node *) malloc(sizeof(node));

    if (a == NULL) {
        printf("Memory Allocating Fail. \n");
        return NULL;
    } else {
        return a;
    }
}

node *InsertAtBeg(node *head, int a) {
    node *x = getnode();
    if (x == NULL) {
        printf("Error Memory Allocation\n");
        return head;
    }

    x->ele = a;
    x->next = head;
    return x;
}

void printList(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->ele);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;
    int choice, value;

    while (1) {
        printf("1. Insert at Beginning\n");
        printf("2. Print List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = InsertAtBeg(head, value);
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
