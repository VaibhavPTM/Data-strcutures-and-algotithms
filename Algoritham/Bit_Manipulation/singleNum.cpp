#include<iostream>
using namespace std;
void singlenumber(int arr[],int n){
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }
    int i = 0;
    int temp = res;
    while (temp > 0)
    {
        if(temp & 1){
            break;
        }
        i++;
        temp = temp >> 1;
    }
    int mask = (1 << i);
    int firstNo = 0;
    for (i = 0; i < n; i++)
    {
        if ((mask & arr[i]) != 0)
        {
            firstNo = firstNo ^ arr[i];
        }
    }
    int secondNo = res ^ firstNo;
    cout<<firstNo<<endl<<secondNo;
    
    
    
}
int main()
{
    int arr[10] = {11,2,11,31,4,31,4,55,6,6};
    singlenumber(arr,10);
    return 0;
}