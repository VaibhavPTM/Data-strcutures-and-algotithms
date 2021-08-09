#include <iostream>
using namespace std;

class BinarySearch
{
public:
    static int temp;
    char binarySearch(char[], int, int, char);
};
int BinarySearch ::temp;
int main()
{

    char arr[] = {'a', 'c', 'e', 'f', 'g', 'j', 'l', 'r'};
    int n, first = 0, last;
    char elem;
    n = sizeof(arr) / sizeof(char);
    last = n - 1;
    class BinarySearch A1;
    cout << "Enter you element which you want to search : ";
    cin >> elem;
    if (A1.binarySearch(arr, first, last, elem) == '@')
    {
        cout << "The alphabate not found"
             << endl;
    }
    else
    {
        printf( "The next element of this alphabate is %c" , A1.binarySearch(arr, first, last, elem));
    }
    return 0;
}
char BinarySearch ::binarySearch(char arr[], int start, int end, char elem)
{
    int mid;
    char result;
    if (elem >= arr[end])
    {
        return '@';
    }

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (elem == arr[mid])
        {
            start = mid + 1;
        }
        else if (elem < arr[mid])
        {
            end = mid - 1;
            result = arr[mid];
        }
        else if (elem > arr[mid])
        {
            start = mid + 1;
        }
    }
    return result;
}
