// 5. Write a c program to implement a single linked list with following functions:
//  a) create
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
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node Node;
Node *head = NULL;
void createList()
{
    Node *temp, *q = head;
    int n, i;
    printf("Enter how many elements you want to add? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        printf("Enter a value ");
        scanf("%d", &temp->info);
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            q = head;
        }
        else
        {
            while (q->next!=NULL)
            {
                q = q->next;
            }
            q->next = temp;
            q = q->next;
        }
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
void addfirst()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &temp->info);
    temp->next = head;
    head = temp;
}
void addLast()
{
    if (head == NULL)
    {
        addfirst();
        return;
    }
    Node *q = head;
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = temp;

}
void addAny()
{
    Node *prev = head, *temp;
    int pos, i;
    printf("Enter a position ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        addfirst();
        return;
    }
    for (i = 1; i <= pos - 1; i++)
    {
        if (prev == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        prev = prev->next;
    }
    temp = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &temp->info);
    temp->next = prev->next;
    prev->next = temp;
}
void reverse()
{
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void deleteFirst()
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    head = head->next;
    printf("deleted element is %d\n", temp->info);
    free(temp);
}
void deletedLast()
{
    Node *q = head, *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (q->next == NULL)
    {
        deleteFirst();
        return;
    }
    while (q->next->next != NULL)
    {
        q = q->next;
    }
    temp = q->next;
    printf("Deleted element is %d\n", temp->info);
    q->next = NULL;
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
    printf("Deleted element is %d\n",temp->info);
    free(temp);
}
void display()
{
    Node *q = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (q != NULL)
    {
        printf("%d ", q->info);
        q = q->next;
    }
    printf("\n");
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
    printf("Enter a search value");
    scanf("%d", &sv);
    while (q != NULL)
    {
        if (q->info == sv)
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
int main()
{
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
            addfirst();
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
            deletedLast();
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