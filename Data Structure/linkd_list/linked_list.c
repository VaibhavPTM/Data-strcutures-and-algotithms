#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list{
    int num;
    struct linked_list * next;
}L;
void create(L * node);
void traves(L * node);
int main(){
    L * first;
    first = (L*) malloc(sizeof(L));
    create(first);
    traves(first);
    return 0;
}

void create(L * node){
    printf("Enter you element to be added : ");
    scanf("%d",&node->num);
    if (node->num == -1)
    {
        node->next = 0;
    }
    else{
        node->next = (L*)malloc(sizeof(L));
        create(node->next);
    }
}
void traves(L * node){
    if (node->next != 0)
    {
        printf("%d--->",node->num);
        if (node->next->next == 0)
        {
            printf("List is ended hear");
        }
        traves(node->next);
    }
}
