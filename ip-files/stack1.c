#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};

void push(struct node**, int);
int pop(struct node**);
void display(struct node*);

int main()
{
	struct node* p;
	p = NULL;
	push(&p, 1);
	push(&p, 2);
	push(&p, 3);
	push(&p, 4);
	push(&p, 5);

	display(p);

	printf("After Pop %d\n", pop(&p));
	printf("After Pop %d\n", pop(&p));
	display(p);
	return 0;
}

void push(struct node** top, int data)
{
	struct node* node = malloc(sizeof(struct node));

	if (node == NULL)
		printf("Out of Memory\n");	

	if (*top == NULL)
	{
		node->data = data;
		node->link = NULL;
		*top = node;
	}
	else
	{
		node->data = data;
		node->link = *top;
		*top = node;
	}
}

void display(struct node* node)
{
	while (node != NULL)
	{
		printf("%d\n", node->data);
		node = node->link;
	}
}

int pop(struct node** top)
{   
	int data = 0;

	if (*top == NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		data = (*top)->data;
		*top = (*top)->link;
	}

	return data;
}