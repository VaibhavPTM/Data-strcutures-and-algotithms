#include<stdio.h>

void main(){
    int arr[] ={2,3,3,3,4,4,4,4,4,4,4,4,4,10,10,21,22},last,first = 0,mid,ele,count=0,temp,temp2;
    printf("Enter youe Elemet : ");
    scanf("%d",&ele);
    // mathod 1
    last = sizeof(arr)/sizeof(int);
    while (first<=last)
    {
        mid = first + (last - first)/2;
        if (arr[mid]==ele)
        {
            temp = mid;
            count++;
            last = mid -1;
        }
        else if (ele < arr[mid])
        {
            last = mid - 1;
        }
        else if (ele > arr[mid])
        {
            first = mid + 1;
        }
    }
    first = 0;
    last = sizeof(arr)/sizeof(int);
    while (first<=last)
    {
        mid = first + (last - first)/2;
        if (arr[mid]==ele)
        {
            temp2 = mid;
            first = mid +1;
        }
        else if (ele < arr[mid])
        {
            last = mid - 1;
        }
        else if (ele > arr[mid])
        {
            first = mid + 1;
        }
    }
    // Mathod 2
    /*
    for (int i = temp;; i++)
    {
        if (arr[i]!=ele)
        {
            break;
        }
        count++;
    }
    */
    if (count!=0)
    {
        count = temp2 - temp +1;
        printf("\nThe element is repeted %d times",count);
    }
    else
    {
        printf("\nElement not found");
    }
}