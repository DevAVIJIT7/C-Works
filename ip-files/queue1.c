#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};

void addQueue(struct node**, struct node**, int);
int deleteQueue(struct node**, struct node**);
void display(struct node*);

int main()
{
	struct node *front, *rear;
	int item;

	front = rear = NULL;

	addQueue(&front, &rear, 10);
	addQueue(&front, &rear, 20);
	addQueue(&front, &rear, 30);
	addQueue(&front, &rear, 40);
	addQueue(&front, &rear, 50);

	display(front);

	item = deleteQueue(&front, &rear);
	printf("Item %d deleted from Queue\n", item);

	item = deleteQueue(&front, &rear);
	printf("Item %d deleted from Queue\n", item);

	display(front);

	return 0;
}

void addQueue(struct node** front, struct node** rear, int data)
{
	struct node *node = malloc(sizeof(struct node));
	node->data = data;
	node->link = NULL;

	if (*front == NULL)
		*front = node;
	else
		(*rear)->link = node;

	*rear = node;
}

int deleteQueue(struct node** front, struct node** rear)
{
	struct node *temp;
	int item;

	if (*front == NULL)
		printf("Queue is Empty\n");
	else
	{

		temp = *front;

		item = temp->data;
		*front = temp->link;
		free(temp);

		if (*front == NULL)
			*rear = NULL;

		return item;
	}	
}

void display(struct node *q)
{
	printf("front->");

	while(q!=NULL)
	{
		if (q->link == NULL)
			printf("<-rear");

		printf("%2d", q->data);
		q=q->link;
	}
	printf("\n");
}