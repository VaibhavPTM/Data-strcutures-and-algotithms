#include"queue_fun.h"
int main()
{
    Q q;
    printf("Enter the size of queue : ");
    scanf("%d",&q.size);
    q.arr = (int*) malloc (q.size * (sizeof(int)));
    create(&q);
    char c;
    int num;
    while (1)
    {
        printf("\nEnter d for dequeue, i for enqueue, p for print, s for current size, q for quit : ");
        scanf(" %c", &c);
        switch (c)
        {
        case 'p':
            if (isEmpty(q))
            {
                printf("Queue is empty, can't do this opration.\n");
                break;
            }
            printqueue(q);
            break;
        case 'i':
            printf("Enter a number which you want to enqueue : ");
            scanf("%d", &num);
            enqueue(&q,num);
            break;
        case 'd':
            dequeue(&q);
            break;
        case 's':
            printf("Size of queue is %d",count(q));
            break;
        case 'q':
            exit(0);
            break;
        }
    }
    // Circular queue and DEqueue and thaire oprations is remain to do.
    return 0;
}