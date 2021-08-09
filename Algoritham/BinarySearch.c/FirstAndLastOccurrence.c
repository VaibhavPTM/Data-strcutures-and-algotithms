#include<stdio.h>
#include<stdlib.h>
void main()
{
    int c,b,a[] = {3,8,8,8,8,10,10,10,34,96},last,first=0,mid,temp=-1;
    printf("Enter the element you wnat to search\n");
    scanf("%d",&b);
    last = sizeof(a)/sizeof(int);
    // it's first Occurrence
    while(first<=last)
    {
        mid = first + (last-first)/2;
        if(b == a[mid]){
            temp = mid;
            last = mid -1;
        }
        else if(b < a[mid])
        {
            last = mid - 1;
        }
        else if(b > a[mid])
        {
            first = mid +1;
        }
    }
    if (temp != -1)
    {
        printf("Your array index is %d",temp);
    }
    else
    {
        printf("not found");
    }
    // it's last Occurrence
    printf("\nEnter the element you wnat to search\n");
    scanf("%d",&b);
    first = 0;
    last = sizeof(a)/sizeof(int);
    while(first<=last)
    {
        mid = first + (last-first)/2;
        if(b == a[mid]){
            temp = mid;
            first = mid +1;
        }
        else if(b < a[mid])
        {
            last = mid - 1;
        }
        else if(b > a[mid])
        {
            first = mid +1;
        }
    }
    if (temp !=-1)
    {
        printf("Your array index is %d",temp);
    }
    else
    {
        printf("not found");
    }
}