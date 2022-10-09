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
Node *createNode(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    printf("Enter a value ");
    scanf("%d",&newNode->data);
    return newNode;
}
void addFirst(){
    Node *newNode = createNode();
    if(front == NULL){
        front = newNode;
        rear = newNode;
        rear->next = front;
    }
    else
    {
        
    }

}

int main() {
    
    return 0;

}