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
             //  0  1  2  3  4  5  6  7  8  9 
    int arr[] = {0, 0, 0, 0,0,0,0,0,0, 0, 1, 1, 1, 1, 1};
    int n, first = 0, last, elem;
    n = sizeof(arr) / sizeof(int);
    last = 1;
    // int x;
    // printf("Enter your number : ");
    // scanf("%d", &x);
    class BinarySearch A1;
    // cout << "Enter you element which you want to search : ";
    // cin >> elem;
    elem = 1;
    if (A1.binarySearch(arr, first, last, elem) == -1)
    {
        cout << "The slope not found"
             << endl;
    }
    else
    {
        cout << "First one occurce on " << A1.binarySearch(arr, first, last, elem) << " th Index.";
    }
}
int BinarySearch ::binarySearch(int arr[], int start, int end, int elem)
{
    int mid, temp, result;
    temp = end;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (elem > arr[end])
        {
            start = end;
            end = end * 2;
        }
        else if (arr[mid] == elem)
        {
            result = mid;
            end = mid - 1;
        }
        else if (elem < arr[mid])
        {
            end = mid - 1;
        }
        else if (elem > arr[mid])
        {
            start = mid + 1;
        }
    }
    if (arr[result] == 1)
    {
        return result;
    }

    return -1;
}