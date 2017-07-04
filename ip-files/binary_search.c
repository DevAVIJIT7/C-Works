#include <stdio.h>
#include <stdlib.h>

struct btreenode
{
	int data;
	struct btreenode *lchild;
	struct btreenode *rchild;
};

void insert(struct btreenode **, int);
int btreeSearch(struct btreenode **, int);

int main()
{
	struct btreenode *bt;
	int req, i = 1, num;

	bt = NULL;

	printf("Specify No of data to be inserted\n");
	scanf("%d", &req);

	while (i++ <= req)
	{
		printf("Enter the data:");
		scanf("%d", &num);
		insert(&bt, num);
	}

	printf("Enter data to search:");
	scanf("%d", &num);
	if ( btreeSearch(&bt, num) == 1)
		printf("Found\n");
	else
		printf("Not Found\n");

	return 0;
}

void insert(struct btreenode **head, int data)
{

	if (*head == NULL)
	{
		struct btreenode *node = malloc(sizeof(struct btreenode));

		node->data = data;
		node->lchild = NULL;
		node->rchild = NULL;
		*head = node;
	}
	else
	{
		if (data < (*head)->data)
			insert(&((*head)->lchild), data);
		else
			insert(&((*head)->rchild), data);
	}
}

int btreeSearch(struct btreenode **head, int data)
{

	if ((*head)->data == data)
	{	
		return 1;
	}	
	else
	{
		if (data < (*head)->data)
			if (((*head)->lchild)!= NULL)
			  btreeSearch(&((*head)->lchild), data);
			else
			  return 0;	
		else
			if (((*head)->rchild) != NULL)
			  btreeSearch(&((*head)->rchild), data);
			else
			  return 0;	
	}

}

