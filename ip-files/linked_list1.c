#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node* link;
};

void addEnd(struct node** head, int data);
void addBegining(struct node** head, int data);
void delete(struct node**, int );
int count(struct node* head);
void display(struct node* head);

int main() 
{
	struct node* p;
	p = NULL;

	printf("Total No of Node %d\n", count(p));

	addEnd(&p, 100);
	addEnd(&p, 200);
	addEnd(&p, 300);
	addEnd(&p, 400);

	printf("Total No of Node %d\n", count(p));
    
    addBegining(&p, 5);
	addBegining(&p, 10);
	addBegining(&p, 20);
	addBegining(&p, 30);
	addBegining(&p, 40);
	addBegining(&p, 50);

	printf("Total No of Node %d\n", count(p));
	display(p);
	delete(&p, 5);
	display(p);
}

void addEnd(struct node** head, int data)
{   
	struct node* temp;
	struct node* node = malloc(sizeof(struct node));

	if (node == NULL)
		printf("Out of Memory\n");	
    
	if (*head == NULL)
	{
		node->data = data;
		node->link = NULL;
		*head = node;
	}
	else
	{
		temp = *head;

		while (temp->link != NULL)
			temp = temp->link;

		node->data = data;
		node->link = NULL;
		temp->link = node;
	}	

} 

void addBegining(struct node** head, int data)
{   
	struct node* node = malloc(sizeof(struct node));

	if (node == NULL)
		printf("Out of Memory\n");	

	node->data = data;
	node->link = *head;
	*head = node;

} 

void delete(struct node** head, int data)
{
	struct node* temp, *old;
    temp = *head;

	while (temp != NULL)
	{
		if (temp->data == data)
		{
			if (temp == *head)
			{
				*head = temp->link;
				free(temp);
			}
			else
			{
				old->link = temp->link;
				free(temp);
			}
		}
		else
		{
			old = temp;
			temp=temp->link;
		}	
	}

	printf("Node %d not found\n", data);
}

int count(struct node* head)
{
	int count = 0;

	while (head != NULL)
	{	
		head = head->link;
		count++;
	}

	return count;
}

void display(struct node* head)
{
	int count = 0;

	while (head != NULL)
	{	
		printf("%d\t", head->data);
		head = head->link;
	}
}