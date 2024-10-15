
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	float data;
	struct Node *next;
} node;

node *getnode()
{
	node *temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("Memory Allocation failed.");
		return NULL;
	}
	
	temp->next = NULL;
	return temp;
}

node *insertASC(node *head, float x)
{
	node *temp = getnode();
	node *t = head;
	
	if(temp == NULL)
	{
		printf("Malloc Failed");
		free(temp);
		return head;
	}
	else
	{
		temp->data = x;
		temp->next = NULL;
		
		if (head == NULL)
		{
			return temp;
		}
		
		else if(head->data > x)
		{
			temp->next = head;
			return temp;
		}
		
		else
		{
			while(t->next != NULL)
			{
				if(t->data < x && t->next->data >= x)
				{
					temp->next = t->next;
					t->next = temp;
					return head;
				}
				t = t->next;
			}
			
			t->next = temp;
			return head;
		}
	}
}

void PrintLL(node *head)
{
	while(head != NULL)
	{
		printf("%.2f -> ",head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int isPrime(float x)
{
	if (x==1)
	{
		return 0;
	}
	for (int i = 2; i<((x/2)+1); i++)
	{
		if ((int)x/i==0)
		{
			return 0;
		}
	}
	
	return 1;
}

node *deletePrime(node *head)
{
	if (head == NULL)
	{
		return head;
	}
	
	
	else
	{
		node *t=head, *p, *temp;

		t=t->next;
		while(t != NULL)
		{
			if(isPrime(t->data))
			{
				temp = t;
				p->next = t->next;
				free(temp);
				p = t;
				t = t->next;
				
			}
			
			else
			{
				p = t;
				t = t->next;
			}
		}
		
		return head;
	}
}


int main()
{
	node *head = getnode();
	if (head == NULL)
	{
		printf("Malloc failed");
		exit(1);
	}
	head = NULL;
	int n,i=0;
	
	float x;
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	printf("Enter list elements:");
	if(n>0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%f",&x);
			head = insertASC(head,x);
		}
	}
	printf("\n");
	printf("Initial list:");
	printf("\n");
	PrintLL(head);
	printf("After deleting prime position elements:");
	printf("\n");
	head = deletePrime(head);
	PrintLL(head);
	
	return 0;
}

