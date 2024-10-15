#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
        int data;
        struct Node *next;
} node;

node *getnode()
{
        node *a;
        a = (node *) malloc(sizeof(node));

        if (a==NULL)
        {
                printf("Memory Allocting Fail. \n");
                return NULL;
        }

        else
        {
                a->next = NULL;
                return a;
        }
}

void printList(node *head)
{
        while (head != NULL)
        {
                printf("%d -> ", head->data);
                head = head->next;
        }
        printf("NULL\n");
}

node *insertAscOrder(node *h, int x)
{
        node *t = h;
        node *temp = getnode();
        if (temp == NULL)
        {
                return h;
        }

        temp->data = x;
        if (h == NULL || h->data >= x)
        {
                temp->next = h;
                h = temp;
                return h;
        }

        else
        {
                while (t != NULL)
                {
                        if(t->data < x && (t->next == NULL || t->next->data >=x))
                        {
                                temp->next = t->next;
                                t->next = temp;
                                break;
                        }

                        else
                        {
                                t = t->next;
                        }
                }
                return h;
        }
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

        head = insertAscOrder(head, 0);
        printf("After inserting 0: ");
        printList(head);

        head = insertAscOrder(head, 5);
        printf("After inserting 5: ");
        printList(head);

        head = insertAscOrder(head, 4);
        printf("After inserting 4: ");
        printList(head);


        return 0;
}
