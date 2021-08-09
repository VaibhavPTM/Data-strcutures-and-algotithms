#include<stdio.h>
#include<stdlib.h>
void main()
{
    int c,last,first=0,mid;
    char b,a[] = {'a','c','e','h','k','p','r','z'};
    printf("Enter the element you wnat to search\n");
    scanf("%c",&b);
    last = sizeof(a)/sizeof(char);

    while(first<=last)
    {
        mid = (last+first)/2;
        if(b == a[mid]){
            printf("your array index is %d",mid);
            c=10;
            break;
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
    if(!c)
    printf("not found");
}