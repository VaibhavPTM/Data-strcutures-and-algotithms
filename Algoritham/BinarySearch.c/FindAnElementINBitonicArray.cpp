#include <iostream>
using namespace std;

class BinarySearch
{
public:
    static int temp;
    int binarySearch(int[], int, int, int);  
    int bsAsending(int[], int, int, int);
    int bsDicseding(int[], int, int, int);

};
int BinarySearch ::temp;
int main()
{

    int arr[] = {10,20,30,33,34,37,40,42,47,48,45,24,11,1};
    int n, first = 0, last, elem;
    n = sizeof(arr) / sizeof(int);
    last = n - 1;
    class BinarySearch A1;
    cout << "Enter you element which you want to search : ";
    cin >> elem;
    if (A1.binarySearch(arr, first, last, elem)==-1)
    {
        cout<<"Element is not prasent";
    }
    
    cout << "Peak element is " << A1.binarySearch(arr, first, last, elem);
}
int BinarySearch ::binarySearch(int arr[], int start, int end, int elem)
{
    int mid, temp, result,a1,a2;
    temp = end;
    // Find peak element
    while (start <= end)
    {
        mid = start + (end - start)/2;
        if (mid > 0 && mid < temp)
        {
            if (arr[mid]>arr[mid-1] && arr[mid] > arr[mid+1])
            {
                result = mid;
                break;
            }
            else if (arr[mid-1]> arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }   
        }
        else if(mid == 0)
        {
            if (arr[0]>arr[1])
            {
                result = 0;
                break;
            }
            else
            {
                result = 1;
                break;
            }
        }
        else if(mid == temp)
        {
            if (arr[temp] > arr[temp-1])
            {
                result = temp;
                break;
            }
            else
            {
                result = temp-1;
                break;
            }
        }
    }
    a1 = bsAsending(arr,0,result,elem);
    a2 = bsDicseding(arr,result+1,temp,elem);
    if (a1!=-1)
    {
        return a1;
    }
    else
    {
        return a2;
    }
    
    
    return -1;
}
int BinarySearch::bsAsending(int arr[],int start, int end, int elem){
    int mid;
    while (start<=end)
    {
        mid = start + (end - start)/2;
        if (elem==arr[mid])
        {
            return mid;
        }
        else if (elem>arr[mid])
        {
            start = mid + 1; 
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int BinarySearch::bsDicseding(int arr[],int start, int end, int elem){
    int mid;
    while (start<=end)
    {
        mid = start + (end - start)/2;
        if (elem==arr[mid])
        {
            return mid;
        }
        else if (elem>arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1; 
        }
    }
    return -1;
}