#include <iostream>
using namespace std;

class BinarySearch
{
public:
    static int temp;
    int binarySearch(int[], int, int, int);  
};
int BinarySearch ::temp;
int main()
{

    int arr[] = {10, 20 ,30,40,50};
    int n, first = 0, last, elem;
    n = sizeof(arr) / sizeof(int);
    last = n - 1;
    class BinarySearch A1;
    // cout << "Enter you element which you want to search : ";
    // cin >> elem;
    cout << "Peak element is " << A1.binarySearch(arr, first, last, elem);
}
int BinarySearch ::binarySearch(int arr[], int start, int end, int elem)
{
    int mid, temp, result;
    temp = end;

    while (start <= end)
    {
        mid = start + (end - start)/2;
        if (mid > 0 && mid < temp)
        {
            if (arr[mid]>arr[mid-1] && arr[mid] > arr[mid+1])
            {
                return arr[mid];
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
                return arr[0];
            }
            else
            {
                return arr[1];
            }
        }
        else if(mid == temp)
        {
            if (arr[temp] > arr[temp-1])
            {
                return arr[temp];
            }
            else
            {
                return arr[temp-1];
            }
        }
    }
    return -1;
}