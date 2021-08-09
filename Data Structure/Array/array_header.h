
#include<stdio.h>
#include<stdlib.h>
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
void createArray(struct myArray * a,int tsize, int usize){
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}
int deletArray(struct myArray * a){
    int index;
    printf("\nEnter yout elemnt : ");
    scanf("%d",&index);
    if (index < 0 || index > a->used_size)
    {
        return 0;
    }
    for (int i = index; i < a->used_size; i++)
    {
        (a->ptr)[i] = (a->ptr)[i+1];
    }
    (a->ptr)[a->used_size] = 0;
    a->used_size--; 

    return 1;   
}
void show(struct myArray * a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ",(a->ptr)[i]);
    }    
}
void setval(struct myArray * a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d : ",i);
        scanf("%d",&(a->ptr)[i]);
    }    
}
int ArrayInsrtion(struct myArray * a){
    int elem, index;
    printf("\nEnter your elemnt and index number : ");
    scanf("%d %d",&elem,&index);
    if(a->used_size >= a->total_size || index > a->used_size){
        return -1;
    }
    for (int i = a->used_size - 1; i >= index ; i--)
    {
        (a->ptr)[i + 1] = (a->ptr)[i];
    }
    (a->ptr)[index] = elem;
    a->used_size++;

    return 1;
}