// 8. Write a c program to implement a circular linked list with following functions:
//  a) create
// b) insert a node at beginning of the linked list
// c) insert a node at any position
// d) insert a node at end of the linked list
// e) ) delete a node at beginning of the linked list
// f) delete a node at any position
// g) delete a node at end of the linked list
// h) display
// i) reverse

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node Node;
Node *tail = NULL;

int isEmpty()
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return 1;
    }
    return 0;
}
void addToEmpty()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &temp->info);
    tail = temp;
    tail->next = tail;
}
void addFirst()
{
    Node *newNode;
    if (tail == NULL)
    {
        addToEmpty();
        return;
    }
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &newNode->info);
    newNode->next = tail->next;
    tail->next = newNode;
}
void addLast()
{
    Node *newNode;
    if (tail == NULL)
    {
        addToEmpty();
        return;
    }
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter a value ");
    scanf("%d", &newNode->info);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}
void createList()
{
    Node *temp, *q = tail;
    int n, i;
    printf("Enter how many elements you want to add? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        if (tail == NULL)
        {
            addToEmpty();
        }
        else
        {
            addLast();
        }
    }
}

void display()
{
    Node *q = tail;
    if (isEmpty())
        return;
    do
    {
        q = q->next;
        printf("%d ", q->info);
    } while (q != tail);
    printf("\n");
}
void deleteFirst()
{
    Node *temp;
    if (isEmpty())
        return;
    temp = tail->next;
    if (tail->next == tail)
    {
        tail = NULL;
    }
    else
    {
        tail->next = temp->next;
    }
    printf("Deleted element is %d\n", temp->info);
    free(temp);
}
void deleteLast()
{
    Node *q, *temp;
    if (isEmpty())
        return;
    q = tail->next;
    if (q == tail)
    {
        deleteFirst();
        return;
    }
    while (q->next != tail)
    {
        q = q->next;
    }
    temp = q->next;
    q->next = tail->next;
    tail = q;
    printf("Deleted element is %d\n", temp->info);
    free(temp);
}
int count()
{
    int count = 0;
    Node *q = tail;
    do
    {
        count++;
        q = q->next;
    } while (q != tail);
    return count;
}
void search()
{
    int sv;
    Node *q = tail;
    printf("Enter a search value ");
    scanf("%d", &sv);
    do
    {
        q = q->next;
        if (q->info == sv)
        {
            printf("%d found\n", sv);
            return;
        }
    } while (q != tail);
    if (q == tail)
    {
        printf("%d not found\n", sv);
    }
}
void reverse()
{
    Node *curr = tail->next, *prev = tail, *next = NULL;
    while (curr != tail)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    next = curr->next;
    curr->next = prev;

    tail = next;
}
void deleteAny()
{
    int pos, i;
    Node *temp, *q;
    if (isEmpty())
        return;
    q = tail->next;
    printf("Enter a position ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        deleteFirst();
        return;
    }
    for (i = 0; i < pos - 1; i++)
    {
        q = q->next;
    }
    temp = q->next;
    if (temp == tail)
    {
        q->next = tail->next;
        tail = q;
    }
    else
    {
        q->next = temp->next;
    }
    printf("Deleted element is %d\n", temp->info);
    free(temp);
}
void addAny()
{
    int pos, i;
    Node *newNode = (Node *)malloc(sizeof(Node)), *q = tail->next;
    printf("Enter a position ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        addFirst();
        return;
    }
    for (i = 0; i < pos - 1; i++)
    {
        q = q->next;
    }
    printf("Enter the value ");
    scanf("%d", &newNode->info);
    newNode->next = q->next;
    q->next = newNode;
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
            printf("No of Nodes: %d\n", count());
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