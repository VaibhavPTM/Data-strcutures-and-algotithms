#include <iostream>
using namespace std;

class BinarySearch
{
public:
    static int temp;
    int ArryRoteted(int[], int, int, int);
};
int BinarySearch ::temp;
int main()
{

    int arr[] = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    int n, first = 0, last;
    n = sizeof(arr) / sizeof(int);
    last = n - 1;
    // int x;
    // printf("Enter your number : ");
    // scanf("%d", &x);
    class BinarySearch A1;
    if (A1.ArryRoteted(arr, first, last, n)==-1)
    {
        printf("Element not found!");
    }
    else
    {
        printf("Array is roteted %d times", A1.ArryRoteted(arr, first, last, n));
    }
    return 0;
}
int BinarySearch ::ArryRoteted(int arr[], int first, int last, int n)
{
    int mid;

    while (first <= last)
    {
        mid = first + (last - first) / 2;
        if (arr[first] <= arr[last])
        {
            return first;
        }
        else if (arr[mid] < arr[(mid + n - 1) % n] && arr[mid] < arr[(mid + 1) % n])
        {
            return mid;
        }
        else if (arr[first] <= arr[mid])
        {
            first = mid + 1;
        }
        else if (arr[mid] <= arr[last])
        {
            last = mid - 1;
        }
    }
    return -1;
}
