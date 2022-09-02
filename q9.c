// 9. Write a c program to Implement a stack with following operations using linked list:
// a) Push
// b) Pop
// c) Display 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *top = NULL;
void push(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d",&newNode->data);
    newNode->next = top;
    top = newNode;
}
void pop(){
    Node *temp = top;
    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    top = top->next;
    printf("Deleted element is %d\n",temp->data);
    free(temp);
}
void display(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Displaying elements:\n");
    Node *q = top;
    while (q!=NULL)
    {
        printf("%d\n",q->data);
        q = q->next;
    }    
}
void createStack(){
    Node *q = top, *temp;
    int i,n;
    printf("How many eleemnts you want to insert? ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        push();
    }
}
int main() {
    while (1)
    {
        int choice;
        printf("1: CreateStack\n2: Push\n3: Pop\n4:Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createStack();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
 
    return 0;

}