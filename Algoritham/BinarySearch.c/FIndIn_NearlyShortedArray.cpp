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

    int arr[] = {20, 10, 30, 50, 40, 70, 90, 80};
    int n, first = 0, last, elem;
    n = sizeof(arr) / sizeof(int);
    last = n - 1;
    // int x;
    // printf("Enter your number : ");
    // scanf("%d", &x);
    class BinarySearch A1;
    cout << "Enter you element which you want to search : ";
    cin >> elem;
    if (A1.binarySearch(arr, first, last, elem) == -1)
    {
        cout << "The element not found"
             << endl;
    }
    else
    {
        cout << "Your Element is " << A1.binarySearch(arr, first, last, elem);
    }
}
int BinarySearch ::binarySearch(int arr[], int start, int end, int elem)
{
    int mid, temp;
    temp = end;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == elem)
        {
            return mid;
        }
        else if ((mid - 1) >= 0 && elem == arr[mid - 1])
        {
            return (mid - 1);
        }
        else if ((mid + 1) <= temp && elem == arr[mid + 1])
        {
            return (mid + 1);
        }
        else if (elem < arr[mid])
        {
            end = mid - 2;
        }
        else if (elem > arr[mid])
        {
            start = mid + 2;
        }
    }
    return -1;
}