#include <stdio.h>
#include <stdlib.h>
typedef struct linked_list
{
    int num;
    struct linked_list *next;
} node;
node *list;
void create(node *p);
int count(node *p);
void print(node *p);
node *insert(node *numb, int x);
node *delet(node *numb, int x);
node *find(node *numb, int x);
void main()
{
    char a;
    int n;
    list = (node *)malloc(sizeof(node));
    // creating the list
    create(list);

    char choise;
    while (1) {
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
void create(node *numb)
{
    /*recursive mathod*/
    printf("->Enter the number which you wannt to add \n->Enter -1 At end\n>>");
    scanf("%d", &numb->num);
    if (numb->num == -1)
    {
        numb->next = list;
    }
    else
    {
        numb->next = (node *)malloc(sizeof(node));
        create(numb->next);
    }

    /*Alternative mathod*/
    // node *t;
    // t = numb;
    // while (1)
    // {
    //     t->next = (node *)malloc(sizeof(node));
    //     printf("->Enter the number which you wannt to add \n->Enter -1 At end\n>>");
    //     scanf("%d", &t->num);
    //     if (t->num == -1)
    //     {
    //         t->next = numb;
    //         break;
    //     }
    //     else{
    //         t = t->next;
    //     }
    // }
}
void print(node *numb)
{
    /*recursive mathod*/
    if (numb->next != list)
    {
        printf("%d--->", numb->num);
        if (numb->next->next == list)
        {
            printf(" List is circular from here");
        }
        print(numb->next);
    }
    return;


    /*Alternative mathod*/
    // node *t = numb;
    // do
    // {
    //     printf("%d--->", t->num);
    //     t = t->next;
    //     if(t->next == numb){
    //         printf(" List is circular from here");
    //     }
    // } while (t->next != numb);
}
int count(node *numb)
{
    /*recursive mathod*/
    if(numb->next == list)
        return 0;
    return (1 + count(numb->next));


    /*Alternative mathod*/
    // int count = 0;
    // node * t = numb;
    // do
    // {
    //     count++;
    //     t = t->next;
    // } while (t->next != numb);
    // return count;
}
node *insert(node *numb, int x)
{
    node *p1, *p2, *add,*last = numb;
    while (last->next != numb)
    {
        last = last->next;
    }
    p1 = NULL;
    p2 = numb;
    for (; p2->num < x; p2 = p2->next)
    {
        p1 = p2;
        if (p2->next->next == list)
        {
            p2 = p2->next;
            break;
        }
    }
    add = (node *)malloc(sizeof(node));
    add->num = x;
    add->next = p2;
    if (p1 == NULL)
    {
        numb = add;
        last->next = numb;
    }
    else
    {
        p1->next = add;
    }
    return (numb);
}
node *find(node *numb, int x)
{
    // while (numb != NULL)
    // {
    //     if (numb->num == x)
    //     {
    //         return numb;
    //     }
    //     numb = numb->next;
    // }
    // return numb;
    node *t = numb;
    do
    {
        if(t->num == x){
            return t;
        }
        t = t->next;
    } while (t->next != numb);
}
node *delet(node *numb, int x)
{
    node *delete,*last = numb;
    node *t1;
    node *temp;
    while (last->next != numb)
    {
        last = last->next;
    }

    if (numb->num == x)
    {
        delete = numb->next;
        last->next = delete;
        free(numb);
        numb = delete;
        return numb;
    }
    else
    {
        t1 = find(numb, x);
        if (t1 == NULL)
        {
            printf("Key not found\n");
        }
        for (temp = numb; temp->next != numb; temp = temp->next)
        {
            if (temp->next->num == x)
            {
                delete = temp->next->next;
                free(temp->next);
                temp->next = delete;
            }
        }
        return (numb);
    }
}