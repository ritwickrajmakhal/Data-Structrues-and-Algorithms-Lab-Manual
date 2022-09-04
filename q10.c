// 10. Write C program to implement a Normal queue using linked list with following functions:
// a) insert
// b) delete
// c) display
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *front = NULL;
Node *rear = NULL;

void insert()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = rear->next;
    }
}
void createQueue()
{
    Node *newNode;
    int i, n;
    printf("How many eleemnts you want to insert? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter a value ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = rear->next;
        }
    }
}
void Delete()
{
    Node *temp = front;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    front = front->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}
void display()
{
    Node *q = front;
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("1: CreateStack\n2: insert\n3: Delete\n4:Display\n");
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