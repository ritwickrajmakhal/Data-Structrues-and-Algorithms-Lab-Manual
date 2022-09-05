// 8. Write a c program to implement a circular linked list with following functions:
//  a) create
// b) insert a node at beginning of the linked list
// c) insert a node at any position
// d) insert a node at end of the linked list
// e) ) delete a node at beginning of the linked list
// f) delete a node at any position
// g) delete a node at end of the linked list
// h) display
// i) reverse

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node Node;
Node *tail = NULL;

void addToEmpty()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &temp->info);
    tail = temp;
    tail->next = tail;
}
void addFirst()
{
    Node *newNode;
    if(tail==NULL)
    {
        addToEmpty();
        return;
    }
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &newNode->info);
    newNode->next = tail->next;
    tail->next = newNode;
}
void addLast()
{
    Node *newNode;
    if(tail==NULL)
    {
        addToEmpty();
        return;
    }
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &newNode->info);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}
void createList()
{
    Node *temp, *q = tail;
    int n, i;
    printf("Enter how many elements you want to add? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        if (tail == NULL)
        {
            addToEmpty();
        }
        else
        {
            addLast();
        }
    }
}

void display()
{
    Node *q = tail;
    if (q == NULL)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        q = q->next;
        printf("%d ", q->info);
    } while (q != tail);
    printf("\n");
}

int main()
{
    createList();
    display();

    addFirst();
    display();

    addLast();
    display();
    return 0;
}