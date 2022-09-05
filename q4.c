// 4. Write C program to implement a priority queue using Linked List with following functions:
// a) insert
// b) delete
// c) display
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};
typedef struct Node Node;
Node *front = NULL;
Node *rear = NULL;
void insert()
{
    Node *q = rear, *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value and it's priority ");
    scanf("%d %d", &newNode->data, &newNode->priority);
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        while (q->next != NULL && q->next->priority < newNode->priority)
        {
            q = q->next;
        }
        if (q->priority > newNode->priority && q == rear)
        {
            newNode->next = q;
            rear = newNode;
        }
        else
        {
            newNode->next = q->next;
            q->next = newNode;
        }
        if (newNode->next == NULL)
        {
            front = front->next;
        }
    }
}
void Delete()
{
    Node *q = rear, *temp;
    if (front == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Deleted element is %d\n", front->data);
    if (front == rear)
    {
        front = rear = NULL;
        return;
    }
    while (q->next->next != NULL)
    {
        q = q->next;
    }
    front = q;
    temp = q->next;
    q->next = NULL;
    free(temp);
}

void display()
{
    Node *q = rear;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}
void createQueue()
{
    int n, i;
    printf("Enter how many elements you want to insert? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        insert();
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("1: CreateQueue\n2: insert\n3: Delete\n4:Display\n5: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createQueue();
            break;
        case 2:
            insert();
            break;
        case 3:
            Delete();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}