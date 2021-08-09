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

    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}; // 110
    int n, first = 0, last, elem;
    n = sizeof(arr) / sizeof(int);
    last = n - 1;
    // int x;
    // printf("Enter your number : ");
    // scanf("%d", &x);
    class BinarySearch A1;
    cout << "Enter you element which you want to search : ";
    cin >> elem;
    cout << "Nearest element of given element is " << A1.binarySearch(arr, first, last, elem);
}
int BinarySearch ::binarySearch(int arr[], int start, int end, int elem)
{
    int mid, temp, result;
    temp = end;
    if (arr[end] < elem)
    {
        return arr[end];
    }
    if (arr[start] > elem)
    {
        return arr[start];
    }
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == elem)
        {
            return arr[mid];
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
    //Here we got "end" at the left side of an element and
                // "start" at the right side of an element.  
    if ((elem - arr[end]) <= (arr[start]-elem))
    {
        return arr[end];
    }
    else
    {
        return arr[start];
    }
    return result;
}