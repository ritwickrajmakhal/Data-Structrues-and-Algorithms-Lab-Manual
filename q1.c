// 1. Write C program to implement a stack using array with following functions:
// a) push
// b) pop
// c) display
// Here push() is used to insert some data in the stack.
// pop() is used to delete some data from the stack.
// display() is used to display all the data in the stack.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX], top = -1;
void push()
{
    if (top == MAX - 1) // stack full condition
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter a value ");
    top++;
    scanf("%d", &stack[top]);
}
void pop()
{
    if (top == -1) // stack empty condition
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Poped element is %d\n", stack[top]);
    top--;
}
void display()
{
    int i;
    if (top == -1) // stack empty condition
    {
        printf("Stack is empty\n");
        return;
    }
    for (i = 0; i <= top; i++) // printing all the elements present in between 0 to top
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("1: Push\n2: Pop\n3: Display\n4: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}