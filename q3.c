// 3. Write C program to implement a circular queue using array with following functions: 
// a) insert 
// b) delete 
// c) display
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1, rear = -1, queue[MAX];
void insert(){
    //cheack queue is full or not
    if((front==rear+1) || (front==0 && rear==MAX-1)){
        printf("queue is full\n");
        return;
    }
    else{
        if(front==-1){
            front = 0;
        }
        rear = (rear+1)%MAX;
        printf("Enter a value ");
        scanf("%d",&queue[rear]);
    }
}
void display()
{
    //cheack queue is empty or not
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for(i=front;i!=rear;i=(i+1)%MAX){
        printf("%d ",queue[i]);
    }
    printf("%d",queue[i]);
    printf("\n");
}
void del(){
    //cheack queue is empty or not
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear){ // Atleast 1 element present in a queue
        front = rear = -1;
    }
    else{
        int val = queue[front];
        printf("Deleted element is %d\n",val);
        front = (front+1)%MAX;
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
            del();
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