#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
    int size;
    int top;
    int *arr;
}stack;
int isEmpty(stack s){
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(stack s){
    if (s.top == s.size - 1)
    {
        return 1;        
    }
    else
    {
        return 0;
    }
}
stack* creat(){
    stack * s1;
    s1->size = 80;
    s1->top = -1;
    s1->arr = (int*)malloc(s1->size * sizeof(int));
    int n;
    int i = 0;
    while (1)
    {
        printf("\nEnter a number which you want to add\nEnter -1 for last Element\n");
        scanf("%d",&n);
        if (n == -1)
        {
            return s1;
        }
        s1->arr[i] = n;
        s1->top++;
        i++;
    }
}
int top(stack s1){
    return s1.arr[s1.top];
}
void pop(stack * s){
    if (isEmpty(*s))
    {
        printf("Stack is empty, can't do this opration.\n");
    }
    else{
        int val = s->arr[s->top];
        s->top--;
    }
}
void push(stack * s,int x){
    if(isFull(*s)){
        printf("Stack is full, can't do this opration.\n");
    }
    else{
        s->top++;
        s->arr[s->top] = x;
        printf("%d is pushed\n",x);
    }
}
int size(stack s){
    return s.top + 1;
}
void print(stack s1){
    printf("\n\nPrinting stack from down to top\n\n");
    while (!isEmpty(s1))
    {
        printf("|%5d   |\n",top(s1));
        printf("----------\n");
        pop(&s1);
    }
}
// void print(stack s1){
//     if (isEmpty(s1))
//     {
//         printf("Stack is empty, can't do this opration.\n");
//     }
//     int i = s1.top;
//     printf("\n\nPrinting stack from down to top\n\n");
//     while (i != -1)
//     {
//         printf("|%5d   |\n",s1.arr[i]);
//         printf("----------\n");
//         i--;
//     }
// }