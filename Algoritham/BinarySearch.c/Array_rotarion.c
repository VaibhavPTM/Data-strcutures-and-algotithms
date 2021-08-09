#include <stdio.h>

int main()
{ 
    int arr[] = {2,2,2,3,2,2,2}; //  2 2 2 3 2 2 2
    int n, first = 0, last, mid, temp;
    n = sizeof(arr) / sizeof(int);
    last = n - 1;
    printf("Start");
    while (first <= last)
    {
        mid = first + (last - first) / 2;
        if (arr[first] < arr[last])
        {
            temp = first;
            break;
        }
        else if (arr[mid] < arr[(mid + n - 1) % n] && arr[mid] <= arr[(mid + 1) % n])
        {
            temp = mid;
            break;
        }
        else if (arr[mid] > arr[(mid + n - 1) % n] && arr[mid] > arr[(mid + 1) % n])
        {
            temp = mid + 1;
            break;
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
    printf("Array is roteted %d times", temp);
    return 0;
}