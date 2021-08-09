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

    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80,90};
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
        cout << "The slope not found"
             << endl;
    }
    else
    {
        cout << "Slope of element is " << A1.binarySearch(arr, first, last, elem);
    }
}
int BinarySearch ::binarySearch(int arr[], int start, int end, int elem)
{
    int mid, temp, result;
    temp = end;
    if (arr[start]>elem)
    {
        return -1;
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
            if (arr[end] == elem || arr[end] < elem)
            {
                result = arr[end];
            }
        }
        else if (elem > arr[mid])
        {
            start = mid + 1;
            if (arr[start] > elem)
            {
                result = arr[start-1];
            }
            else if (start==temp)
            {
                result = arr[temp];
            }
        }
    }
    return result;
}