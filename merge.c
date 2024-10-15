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

node *merge(node *h1, node *h2) {
    if (h1 == NULL && h2 == NULL) {
        return NULL;
    } else if (h1 == NULL && h2 != NULL) {
        node *h3 = NULL, *t = h2, *p, *a;

        a = getnode();
        a->data = t->data;
        h3 = a;
        p = h3;
        t = t->next;

        while (t != NULL) {
            a = getnode();
            a->data = t->data;
            p->next = a;
            p = a;
            t = t->next;
        }

        return h3;
    } else if (h2 == NULL && h1 != NULL) {
        node *h3 = NULL, *t = h1, *p, *a;

        a = getnode();
        a->data = t->data;
        h3 = a;
        p = h3;
        t = t->next;

        while (t != NULL) {
            a = getnode();
            a->data = t->data;
            p->next = a;
            p = a;
            t = t->next;
        }

        return h3;
    } else {
        node *h3 = NULL, *t1 = h1, *t2 = h2, *a, *p;

        if (t1->data < t2->data) {
            a = getnode();
            a->data = t1->data;
            h3 = a;
            p = a;
            t1 = t1->next;
        } else {
            a = getnode();
            a->data = t2->data;
            h3 = a;
            p = a;
            t2 = t2->next;
        }

        while (t1 != NULL && t2 != NULL) {
            if (t1->data < t2->data) {
                a = getnode();
                a->data = t1->data;
                p->next = a;
                p = a;
                t1 = t1->next;
            } else {
                a = getnode();
                a->data = t2->data;
                p->next = a;
                p = a;
                t2 = t2->next;
            }
        }

        while (t1 != NULL) {
            a = getnode();
            a->data = t1->data;
            p->next = a;
            p = a;
            t1 = t1->next;
        }

        while (t2 != NULL) {
            a = getnode();
            a->data = t2->data;
            p->next = a;
            p = a;
            t2 = t2->next;
        }

        return h3;
    }
}

void printList(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main() {
    node *h1 = getnode();
    h1->data = 1;
    h1->next = getnode();
    h1->next->data = 5;
    h1->next->next = getnode();
    h1->next->next->data = 8;
    h1->next->next->next = NULL;

    node *h2 = getnode();
    h2->data = 2;
    h2->next = getnode();
    h2->next->data = 7;
    h2->next->next = NULL;

    node *h3 = merge(h1, h2);

    printList(h3);

    return 0;
}
