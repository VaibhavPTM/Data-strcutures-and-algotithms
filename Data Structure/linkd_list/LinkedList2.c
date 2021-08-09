#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list
{
    int num;
    struct linked_list *next;
} node;
void craet(node *numb)
{
    printf("->Enter the number which you wannt to add \n->Enter -1 At end\n>>");
    scanf("%d", &numb->num);
    if (numb->num == -1)
    {
        numb->next = NULL;
    }
    else
    {
        numb->next = (node *)malloc(sizeof(node));
        craet(numb->next);
    }
}
void print(node *numb)
{
    if (numb->next != NULL)
    {
        printf("%d--->", numb->num);
        if (numb->next->next == 0)
        {
            printf(" List is ended here");
        }
        print(numb->next);
    }
    return;
}
node *insert(node *numb, int x)
{
    node *p1, *p2, *p;
    p1 = NULL;
    p2 = numb;
    for (; p2->num < x; p2 = p2->next)
    {
        p1 = p2;
        if (p2->next->next == NULL)
        {
            p2 = p2->next;
            break;
        }
    }
    p = (node *)malloc(sizeof(node));
    p->num = x;
    p->next = p2;
    if (p1 == NULL)
    {
        numb = p;
    }
    else
    {
        p1->next = p;
    }
    return (numb);
}
node *find(node *numb, int x)
{
    while (numb != NULL)
    {
        if (numb->num == x)
        {
            return numb;
        }
        numb = numb->next;
    }
    return numb;
}
node *delet(node *numb, int x)
{
    node *p;
    node *t1;
    node *temp;

    if (numb->num == x)
    {
        p = numb->next;
        free(numb);
        numb = p;
    }
    else
    {
        t1 = find(numb, x);
        if (t1 == NULL)
        {
            printf("Key not found\n");
        }
        for (temp = numb; temp->next != NULL; temp = temp->next)
        {
            if (temp->next->num == x)
            {
                p = temp->next->next;
                free(temp->next);
                temp->next = p;
            }
        }
        return (numb);
    }
}
int count(node *numb)
{
    if (numb->next == 0)
    {
        return 0;
    }
    else
    {
        return (1 + count(numb->next));
    }
}
void main()
{
    char a;
    int n;
    node *list;
    list = (node *)malloc(sizeof(node));
    // creating the list
    craet(list);

    char choise;
    while (1)
    {
        printf("\n\np for print, d for delete, i for insert and q for quit : ");
        scanf(" %c", &choise);

        switch (choise)
        {
        case 'p':
            printf("list.... \n");
            print(list);
            printf("\nNumber of elements is %d", count(list));
            break;
        case 'd':
            printf("Enter you number : ");
            scanf("%d", &n);
            list = delet(list, n);
            printf("Number is deleted");
            break;
        case 'i':
            printf("Enter you number : ");
            scanf("%d", &n);
            list = insert(list, n);
            printf("Number is inserted");
            break;
        case 'q':
            exit(0);
            break;
        }
    }
}
