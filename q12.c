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
            q->next = temp;
            q = q->next;
        }
    }
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

int main() {
    createList();
    search();
    return 0;

}