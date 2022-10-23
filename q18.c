/*
18. Write C program to implement a circular queue using Linked List with following functions:
a) insert
b) delete
c) display
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *rear, *front;

void insert(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d",&newNode->data);
    if(front == NULL){
        front = newNode;
        rear = newNode;   
    }
    else{
        rear->next = newNode;
        rear = rear->next;
    }   
    newNode->next = front;
}
void Delete(){
    Node *temp = front;
    if(front != NULL){
        if(front == rear){
            front = NULL;
            rear = NULL;
        }
        else{
            front = front->next;
        }
        printf("Deleted element is %d\n",temp->data);
    }
    else{
        printf("Queue is empty\n");
    }
    free(temp);
}
void display(){
    Node *q = front;
    if(front != NULL){
        do{
            printf("%d ",q->data);
            q = q->next;
        }while(q!=rear->next);
        printf("\n");
    }
    else{
        printf("Queue is empty\n");
    }
}
int main() {
    while (1)
    {
        int choice;
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            Delete();
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