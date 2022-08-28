#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list {
    int num;
    struct linked_list *next;
    struct linked_list *prev;
} node;
node *head, *tail = NULL;

// functions in this program
void creat(int);
void PriNode(node*);    
int count(node *);
void insert(int);
node* findNode(int);
void delet(int);

int main() {
    // Creating a doubly linked list
    int i;

    while (1)
    {
        printf("->Enter the number which you wannt to add \n->Enter -1 At end\n>>");
        scanf("%d", &i);
        if (i == -1)
        {
            break;
        }
        creat(i);
    }

    // Opration on linked list
    char choise;
    while (1)
    {
        printf("\n\np for print, d for delete, i for insert and q for quit : ");
        scanf(" %c", &choise);

        switch (choise)
        {
        case 'p':
            printf("list.... \n");
            PriNode(head);
            break;
        case 'd':
            printf("Enter you number : ");
            scanf("%d", &i);
            delet(i);
            break;
        case 'i':
            printf("Enter you number : ");
            scanf("%d", &i);
            insert(i);
            printf("Number is inserted");
            break;
        case 'q':
            exit(0);
            break;
        }
    }
    return 0;
}

void creat(int x)
{
    node * insert;
    insert = (node *)malloc(sizeof(node));
    insert->num = x;
    if (head == NULL)
    {
        head = tail = insert;
        head->prev = NULL;
        tail->next = NULL;
    }
    else{
        tail->next = insert;
        insert->prev = tail;
        tail = insert;
        insert->next = NULL;
    }
}
int count(node * countVar){
    if(countVar == NULL){
        return 0;
    }
    else{
        return (1 + count(countVar->next));
    }
}
void PriNode(node* start){
    node * temp = head;
    if (count(head) == 0 || head == NULL)
    {
        printf("Linked List is empty");
        return;
    }
    do
    {
        printf("%d-->",temp->num);
        temp = temp->next;
        if(temp == NULL){
            printf(" List is ended");
        }
    } while (temp != NULL);
    printf("\nTotal numbers is %d in this linked list",count(head));
}
void insert(int x){
    node * h = head;
    node *temp = NULL;
    node * insert = (node *)malloc(sizeof(node));
    insert->num = x;
    if(x > tail->num){
        tail->next = insert;
        insert->prev = tail;
        tail = insert;
        insert->next = NULL;
        return;
    }
    while (h->num < x)
    {
        temp = h;
        h = h->next;
    }
    if(temp == NULL){
        insert->prev = NULL;
        insert->next = head;
        head->prev = insert;
        head = insert;
        return;
    }
    else{
        insert->prev = temp;
        insert->next = h;
        temp->next = insert;
        h->prev = insert;
        return;
    }
}
node* findNode(int x){
    node* find = head;
    while (find != NULL)
    {
        if (find->num == x)
        {
            return find;
        }
        find = find->next;
    }
    return NULL;
    
}
void delet(int x){

    if (count(head) == 1 && head->num == x)
    {
        head = tail = NULL;
        return;
    }
    if (head == NULL)
    {
        printf("Linked List is empty");
        return;
    }
    node * delet,*temp,*temp2;
    if (head->num == x)
    {
        delet = head->next;
        free(head);
        head = delet;
        head->prev = NULL;
        printf("Number is deleted");
        return;
    }
    else if(tail->num == x)
    {
        delet = tail->prev;
        free(tail);
        tail = delet;
        tail->next = NULL;
        printf("Number is deleted");
        return;
    }
    delet = findNode(x);
    if (delet == NULL)
    {
        printf("Key Not Found\n");
        return;
    }
    else{
        temp = delet->prev;
        temp2 = delet->next;
        free(delet);
        temp->next = temp2;
        temp2->prev = temp;
        printf("Number is deleted");
        return;
    }
    return;
}