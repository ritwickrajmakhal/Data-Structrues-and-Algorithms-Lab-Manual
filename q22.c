/* Implementation of binary tree */

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

int main() {
    Node *root = createNode();
    Node *p1 = createNode();
    Node *p2 = createNode();
    Node *c1 = createNode();
    Node *c2 = createNode();
    Node *c3 = createNode();
    Node *c4 = createNode();
//linking
    root->left = p1;
    root->right = p2;

    p1->left = c1;
    p1->right = c2;

    p2->left = c3;
    p2->right = c4;

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

    return 0;

}