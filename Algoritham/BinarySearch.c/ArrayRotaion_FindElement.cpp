#include <iostream>
using namespace std;

class BinarySearch
{
public:
    static int temp;
    int ArryRoteted(int[], int, int, int, int);
    int binarySearch(int[], int, int, int);
};
int BinarySearch ::temp;
int main()
{
              // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
    int arr[] = {1,1,1,1,1,1,1,1,1,13,1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1};
    int n, first = 0, last, elem;
    n = sizeof(arr) / sizeof(int);
    last = n - 1;
    // int x;
    // printf("Enter your number : ");
    // scanf("%d", &x);
    class BinarySearch A1;
    cout << "Enter you element which you want to search : ";
    cin >> elem;
    if (A1.ArryRoteted(arr, first, last, n, elem) == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "The index of Element is "
             << A1.ArryRoteted(arr, first, last, n, elem);
    }
    return 0;
}
int BinarySearch ::ArryRoteted(int arr[], int first, int last, int n, int elem)
{
    int mid, min_index;
    int temp1, temp2, last2;
    last2 = last;
    while (first <= last)
    {
        mid = first + (last - first) / 2;
        if (arr[first] < arr[last])
        {
            min_index = first;
            break;
        }
        else if (arr[mid] < arr[(mid + 1) % n] && arr[mid] <= arr[(mid + n - 1) % n])
        {
            min_index = mid;
            break;
        }
        else if (arr[mid] > arr[(mid + 1) % n] && arr[mid] > arr[(mid + n - 1) % n])
        {
            min_index = mid + 1;
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
    // cout<<min_index<<endl;
    temp1 = binarySearch(arr, 0, ((min_index + n - 1) % n), elem);
    temp2 = binarySearch(arr, min_index, last2, elem);
    if (temp1 != -1)
    {
        return temp1;
    }
    else
    {
        return temp2;
    }
    return -1;
}
int BinarySearch ::binarySearch(int arr[], int start, int end, int elem)
{
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == elem)
        {
            return mid;
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
    return -1;
}