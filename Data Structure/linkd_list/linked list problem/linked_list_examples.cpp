#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct linked_list
{
    int num;
    struct linked_list *next;
} node;
node *list;
void craet(node *numb)
{
    int temp;
    scanf("%d", &temp);
    if (temp == -1)
    {
        numb->next = NULL;
        return;
    }
    numb->num = temp;
    numb->next = (node *)malloc(sizeof(node));
    craet(numb->next);
}
void print(node *numb)
{
    if (numb->next != NULL)
    {
        printf("%d--->", numb->num);
        if (numb->next->next == NULL)
        {
            printf(" List is ended here\n");
        }
        print(numb->next);
    }
    return;
}
void print2(node *numb)
{
    if (numb->next != NULL)
        if (numb)
            cout << numb->num << " ";
    print2(numb->next);
    return;
}
int DoseLikedListHasACycle(node *numb)
{
    node *slowPtr = numb;
    node *fastPtr = numb;
    while (slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            return 1;
        }
    }

    return 0;
}
node *reversList(node *list)
{
    node *temp = NULL, *nextNode = NULL;
    while (list)
    {
        nextNode = list->next;
        list->next = temp;
        temp = list;
        list = nextNode;
    }
    return temp;
}
node *FindMid(node *list)
{
    node *fNode = list, *SNode = list;
    int i = 0;
    while (SNode->next != NULL)
    {
        if (!i)
        {
            SNode = SNode->next;
            i = 1;
        }
        else
        {
            SNode = SNode->next;
            fNode = fNode->next;
            i = 0;
        }
    }
    return fNode;
}
// Merge a linked list in sorted order
node *mergeTwoLists(node *l1, node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    node *res = NULL;
    if (l1->val <= l2->val)
    {
        res = l1;
        res->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        res = l2;
        res->next = mergeTwoLists(l2->next, l1);
    }
    return res;
}
node *swapPairs(node *head)
{
    node *temp = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp;
        head->next->next = swapPairs(head->next->next);

        return head;
    }
}
node *detectCycle(node *head)
{
    node *fnode = head, *snode = head;
    int flag = 0;
    while (snode && snode->next && fnode)
    {
        fnode = fnode->next;
        snode = snode->next->next;
        if (fnode == snode)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        fnode = head;
        while (fnode != snode)
        {
            fnode = fnode->next;
            snode = snode->next;
        }
        return fnode;
    }
    return NULL;
}

int main()
{
    list = (node *)malloc(sizeof(node));
    // creating the list
    craet(list);
    // print2(list);
    node *mid = FindMid(list);
    cout << mid->num;
    return 0;
}

// Cheak whater linkes list has a cycle or not
// if(DoseLikedListHasACycle(list)){
//     cout<<"yes"<<endl;
// }
// else{
//     cout<<"no"<<endl;
// }