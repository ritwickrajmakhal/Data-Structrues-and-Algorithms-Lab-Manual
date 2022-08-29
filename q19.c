// 19. Write C program to implement a de queue queue using array with following functions:
// a) insert
// b) delete
// c) display 

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1;
int rear = -1;
int DEQueue[MAX];

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if (rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}
void addLast()
{
    if (isFull() && (front == 0))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else if(!isFull())
    {
        rear++;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            DEQueue[i - 1] = DEQueue[i];
        }
        front--;
    }
    
    printf("Enter a value ");
    scanf("%d", &DEQueue[rear]);
}
void addFirst()
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else if(front != 0)
    {
        front--;
    }
    else
    {
        for (int i = rear; i >= front; i--)
        {
            DEQueue[i + 1] = DEQueue[i];
        }
        rear++;
    }
    
    printf("Enter a value ");
    scanf("%d", &DEQueue[front]);
}
void removeFirst()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    int element = DEQueue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    printf("Deleted element is %d\n", element);
}

void removeLast()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    int element = DEQueue[rear];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
    printf("Deleted element is %d\n", element);
}
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Displaying elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", DEQueue[i]);
    }
    printf("\n");
}
int main()
{
    while (1)
    {
        int choice;
        printf("1: addFirst\n2: addLast\n3: removeFirst\n4: removeLast\n5: Display\n6: exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addFirst();
            break;
        case 2:
            addLast();
            break;
        case 3:
            removeFirst();
            break;
        case 4:
            removeLast();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}