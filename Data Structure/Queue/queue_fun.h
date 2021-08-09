#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int *arr;
    int size;
    int first;
    int last;
} Q;
void create(Q *q)
{
    // This function will create a queue untill you enter the -1
    int num;
    q->last = 0;
    q->first = 0;
    while (1)
    {
        printf("Enter The number to be inserted : ");
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
        q->arr[q->last++] = num;
    }
}
void printqueue(Q q)
{
    while (q.first != q.last)
    {
        printf("%d -->", q.arr[q.first++]);
    }
    printf("Queue ends here");
}
int isEmpty(Q q)
{
    if (q.first == q.last)
    {
        return 1;
    }
    return 0;
}
int isFull(Q q)
{
    if ((q.last - q.first) == q.size)
    {
        return 1;
    }
    return 0;
}
int count(Q q){
    return q.last - q.first;
}
void enqueue(Q *q, int num)
{
    if (isFull(*q))
    {
        printf("Queue is Full, can't do this opration.\n");
        return;
    }
    q->arr[q->last] = num;
    q->last++;
    return;
}
void dequeue(Q *q)
{
    if (isEmpty(*q))
    {
        printf("Queue is empty, can't do this opration.\n");
        return;
    }
    q->arr[q->first++] = -1;
    return;
}