// 7. Write a c program to implement a doubly linked list with following functions:
// a) create
// b) insert a node at beginning of the linked list
// c) insert a node at any position
// d) insert a node at end of the linked list
// e) ) delete a node at beginning of the linked list
// f) delete a node at any position
// g) delete a node at end of the linked list
// h) reverse the list
// i) display 

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next, *prev;
};
typedef struct Node Node;
Node *head = NULL;
void createList(){
    Node *newNode, *q = head;
    int n,i; 
    printf("Enter how many elements you want to insert? ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter a value ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        if(head==NULL){
            head = newNode;
            newNode->prev = NULL;
            q = head;
        }
        else{
            q->next = newNode;
            newNode->prev = q;
            q = q->next;
        }
    }
    
}
void display(){
    Node *q = head;
    while(q!=NULL){
        printf("%d ",q->data);
        q = q->next;
    }
    printf("\n");
}
void addFirst(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d",&newNode->data);
    newNode->prev = NULL;
    newNode->next = head;
    head = newNode;
}
void addLast(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *q = head;
    while(q->next!=NULL){
        q = q->next;
    }
    printf("Enter a value ");
    scanf("%d",&newNode->data);
    q->next = newNode;
    newNode->prev = q;
    newNode->next = NULL;
}
void deleteFirst(){
    Node *temp = head;
    head = head->next;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Deleted element is %d\n",temp->data);
    free(temp);
}
void search()
{
    Node *q = head;
    int sv;
    if (head == NULL)
    {
        printf("List is empty nothing to search\n");
        return;
    }
    printf("Enter a search value ");
    scanf("%d", &sv);
    while (q != NULL)
    {
        if (q->data == sv)
        {
            printf("%d found!\n", sv);
            break;
        }
        q = q->next;
    }
    if (q == NULL)
    {
        printf("%d not found\n", sv);
    }
}
int count()
{
    Node *q = head;
    int count = 0;
    while (q != NULL)
    {
        count++;
        q = q->next;
    }
    return count;
}
void reverse(){
    Node *curr = head, *prev = NULL, *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void deleteLast(){
    Node *q = head, *temp;
    if(q->next==NULL){
        deleteFirst();
        return;
    }
    while(q->next->next!=NULL){
        q = q->next;
    }
    temp = q->next;
    printf("Deleted element is %d\n",temp->data);
    q->next = temp->next;
    free(temp);
}
void deleteAny(){
    int pos,i;
    Node *q = head, *temp;
    printf("Enter the position of the node ");
    scanf("%d",&pos);
    if(pos==0){
        deleteFirst();
        return;
    }
    if(pos>=count()){
        printf("Invalid position\n");
        return;
    }
    for(i=0;i<=pos-2;i++){
        q = q->next;
    }
    temp = q->next;
    q->next = temp->next;
    temp->next->prev = q;
    printf("Deleted element is %d\n",temp->data);
    free(temp);
}
void addAny()
{
    Node *q = head, *temp;
    int pos, i;
    printf("Enter a position ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        addFirst();
        return;
    }
    for (i = 1; i <= pos - 1; i++)
    {
        if (q == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        q = q->next;
    }
    temp = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &temp->data);
    temp->next = q->next;
    q->next->prev = temp;
    q->next = temp;
    temp->prev = q;
}

int main() {
    int choice;
    while (1)
    {
        printf("1: createList\n2: addFirst\n3: addLast\n4: addAny\n5: deleteFirst\n6: deleteLast\n7: deleteAny\n8: Display\n9:reverse\n10: count\n11: search\n12:exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createList();
            break;
        case 2:
            addFirst();
            break;
        case 3:
            addLast();
            break;
        case 4:
            addAny();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteLast();
            break;
        case 7:
            deleteAny();
            break;
        case 8:
            display();
            break;
        case 9:
            reverse();
            break;
        case 10:
            printf("No of Nodes: %d\n",count());
            break;
        case 11:
            search();
            break;
        case 12:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;

}