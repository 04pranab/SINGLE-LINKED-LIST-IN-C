#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int ele;
    struct node *next;
} node;

node *getnode();
node *InsertAtRAN(node* head, int a, int p);
void display(node* head);

int main() {
    node *head = NULL;
    int choice, ele, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at random position\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                head = InsertAtRAN(head, ele, pos);
                break;
            case 2:
                display(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

node *getnode() {
    node *a;
    a = (node *) malloc(sizeof(node));

    if (a == NULL) {
        printf("Memory Allocating Fail.\n");
        return NULL;
    } else {
        return a;
    }
}

node *InsertAtRAN(node* head, int a, int p) {
    if (p < 0) {
        printf("Error: Index out of Range\n");
        return head;
    }

    node *x = getnode();
    if (x == NULL) {
        printf("Error Memory Allocation\n");
        return head;
    }
    x->ele = a;

    if (p == 0) {
        x->next = head;
        head = x;
        return head;
    }

    node *current = head;
    int c = 0;

    while (c < p - 1 && current != NULL) {
        current = current->next;
        c++;
    }

    if (current == NULL) {
        printf("Error: Index out of Range\n");
        free(x);
        return head;
    }

    x->next = current->next;
    current->next = x;

    return head;
}

void display(node* head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->ele);
        temp = temp->next;
    }
    printf("NULL\n");
}
