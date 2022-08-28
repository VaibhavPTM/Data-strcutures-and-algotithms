#include "Stack_header.h"
int main()
{
    stack *s1 = creat();
    char c;
    int num;
    while (1)
    {
        printf("\nEnter d for pop, i for push, p for print, s for size, q for quit : ");
        scanf(" %c", &c);
        switch (c)
        {
        case 'p':
            if (isEmpty(*s1)) {
                printf("Stack is empty, can't do this opration.\n");
                break;
            }
            print(*s1);
            break;
        case 'i':
            printf("Enter a number which you want to push : ");
            scanf("%d", &num);
            push(s1, num);
            break;
        case 'd':
            pop(s1);
            break;
        case 's':
            printf("Size of stack is %d\n", size(*s1));
            break;
        case 'q':
            exit(0);
            break;
        }
    }

    return 0;
}
