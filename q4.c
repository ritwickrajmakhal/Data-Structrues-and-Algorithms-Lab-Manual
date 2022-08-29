// 4. Write C program to implement a priority queue using Linked List with following functions:
// a) insert
// b) delete
// c) display
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    int priority;
    struct Node *next;
};
typedef struct Node Node;
Node *front = NULL;
Node *rear = NULL;
void insert(){
    Node *q = rear, *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%c",&newNode->data);
    printf("Enter priority value of %c ",newNode->data);
    scanf("%d",&newNode->priority);
    newNode->next = NULL;
    if(front==NULL){
        front = newNode;
        rear = newNode;
    }
    else{
        while(q->priority<newNode->priority){
            q = q->next;
        }
        newNode->next = q;
        q->next = newNode;
    }
}
int main() {
    // Incompleted
    return 0;

}