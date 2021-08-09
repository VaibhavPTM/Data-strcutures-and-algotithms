#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
static int n;
int find(vector<int> arr,int num){
    int last,first=0,mid;
    last = arr.size() - 1;
    while(first<=last)
    {
        mid = (last+first)/2;
        if(num == arr[mid]){
            return mid;            
        }
        else if(num < arr[mid])
        {
            last = mid - 1;
        }
        else if(num > arr[mid])
        {
            first = mid +1;
        }
    }
    return -1;
}

int main()
{
    int b;
    vector<int> arr = {1,2,3,5,6,7,8,9,10,34,96,998};
    printf("Enter the element you want to search\n");
    scanf("%d",&b);
    int index = find(arr,b);
    if (index != -1)
    {
        printf("\nYore arry index is %d",find(arr,b));
    }
    else{
        printf("not found");
    }
    return 0;
}
