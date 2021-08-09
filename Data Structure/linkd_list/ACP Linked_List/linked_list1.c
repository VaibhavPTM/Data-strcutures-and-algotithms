#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list
{
    int num;
    struct linked_list *next;
} L;
L *head;
void create(int n)
{
    L *temp, *insert;
    int num;
    head = (L *)malloc(sizeof(L));
    if (head == NULL)
    {
        printf("Memory Allocation fauled");
    }
    else
    {
        head->next = NULL;
        printf("Enter number 1 : ");
        scanf("%d", &num);
        head->num = num;
        temp = head;
        for (int i = 2; i <= n; i++)
        {
            insert = (L *)malloc(sizeof(L));
            if (insert == NULL)
            {
                printf("Memory Allocation fauled");
                break;
            }
            else
            {
                printf("Enter number %d : ", i);
                scanf("%d", &num);
                insert->num = num;
                insert->next = NULL;

                temp->next = insert;
                temp = temp->next;
            }
        }
    }
}
void traves(L *node)
{
    L *temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Data : %d\n", temp->num);
            temp = temp->next;
        }
    }
}
void insertAtbigin(int num)
{
    L *insert = (L *)malloc(sizeof(L));
    insert->num = num;
    insert->next = head;
    head = insert;
}
void insertAtEnd(int num)
{
    L *insert = head;
    L *temp = (L *)malloc(sizeof(L));
    while (insert->next != NULL)
    {
        insert = insert->next;
    }
    temp->num = num;
    insert->next = temp;
    temp->next = NULL;
}
void deleteAtbigin(void)
{
    L *delet;
    delet = head->next;
    free(head);
    head = delet;
}
void deleteAtEnd(void)
{
    L *delet = head, *temp;
    while (delet->next->next != NULL)
    {
        delet = delet->next;
    }
    temp = delet;
    free(delet->next);
    temp->next = NULL;
}
int main()
{
    int n, choise;
    printf("How many number do you want to add : ");
    scanf("%d", &n);
    create(n);
    insertAtbigin(34);
    insertAtEnd(50);
    traves(head);
    printf("Deleting....\n");
    deleteAtEnd();
    deleteAtbigin();
    traves(head);
    return 0;
}
