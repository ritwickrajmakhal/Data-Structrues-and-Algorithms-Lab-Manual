// 2. Write C program to implement a Normal queue using array with following functions: 
// a) insert 
// b) delete 
// c) display 

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX], rear = -1, front = -1;

void insert()
{
    if (rear == MAX - 1) // queue full condition
    {
        printf("Queue is full\n");
        return;
    }
    if (rear == -1) // queue empty condition
    {
        rear = 0;
        front = 0;
    }
    else // If queue has 1 or more elements
    {
        rear++;
    }
    printf("Enter a value");
    scanf("%d", &queue[rear]);
}
void del()
{
    int element;
    // queue empty condion
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    element = queue[front];
    // if queue has only 1 element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    // if queue has more than 1 element
    else
    {
        front++;
    }
    printf("Deleted element is %d\n", element);
}
void display()
{
    int i;
    if (front == -1) // queue empty condition
    {
        printf("Queue is empty\n");
        return;
    }
    for (i = front; i <= rear; i++) // displaying all the elements present in a queue
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}