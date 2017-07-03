#include <stdio.h>
#include <stdlib.h>

struct btreenode
{
	int data;
	struct btreenode *lchild;
	struct btreenode *rchild;
};

void insert(struct btreenode **, int);
void inorder(struct btreenode *);
void preorder(struct btreenode *);
void postorder(struct btreenode *);

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

	printf("Inorder traversal:");
	inorder(bt);

	printf("\nPreorder traversal:");
	preorder(bt);

	printf("\nPostrder traversal:");
	postorder(bt);

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

void inorder(struct btreenode *head)
{
	if (head!=NULL)
	{
		inorder(head->lchild);
		printf("%d", head->data);
		inorder(head->rchild);
	}
}

void preorder(struct btreenode *head)
{
	if (head!=NULL)
	{
		printf("%d", head->data);
		preorder(head->lchild);
		preorder(head->rchild);
	}
}


void postorder(struct btreenode *head)
{
	if (head!=NULL)
	{
		postorder(head->lchild);
		postorder(head->rchild);
		printf("%d", head->data);
	}
}

