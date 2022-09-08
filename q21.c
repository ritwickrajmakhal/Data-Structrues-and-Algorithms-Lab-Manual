/*Implement a binary search tree with the following functions -
1. Creation of a BST
2. Traversal of a BST - Inorder, Preorder, postorder
3. Searching in a BST
(Not includeed in lab manual)*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left, *right;
};
typedef struct Node Node;
Node *createNode()
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	printf("Enter a value ");
	scanf("%d", &newNode->data);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
int bstSearch(Node *root, int sv)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->data == sv)
	{
		return 1;
	}
	if (sv > root->data)
	{
		bstSearch(root->right, sv);
	}
	else
	{
		bstSearch(root->left, sv);
	}
}
void addNode(Node *root, Node *newNode)
{
	if (newNode->data < root->data)
	{
		if (root->left == NULL)
		{
			root->left = newNode;
			return;
		}
		else
		{
			addNode(root->left, newNode);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = newNode;
			return;
		}
		else
		{
			addNode(root->right, newNode);
		}
	}
}
void preOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}
void inOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}
void main()
{

	int sv, n, i;
	Node *root, *newNode;
	// Creation
	printf("Enter how many elements you want to insert? ");
	scanf("%d", &n);
	root = createNode();
	for (i = 0; i < n - 1; i++)
	{
		newNode = createNode();
		addNode(root, newNode);
	}
	// Traversal
	printf("Pre Order Traversal: ");
	preOrder(root);
	printf("\n");
	printf("Post Order Traversal: ");
	postOrder(root);
	printf("\n");
	printf("In Order Traversal: ");
	inOrder(root);
	printf("\n");
	// searching
	printf("Enter a search value ");
	scanf("%d", &sv);
	if (bstSearch(root, sv))
	{
		printf("%d found\n", sv);
	}
	else
	{
		printf("%d not found\n", sv);
	}
}