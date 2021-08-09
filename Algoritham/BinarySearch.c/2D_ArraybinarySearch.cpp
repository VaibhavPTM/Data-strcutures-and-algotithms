#include <iostream>
using namespace std;
int m=4,n=4;
class BinarySearch
{
public:
    static int temp;
    int binarySearch(int[4][4], int, int, int);
};
int BinarySearch ::temp;
int main()
{
    
    int m=4,n=4;
    int arr[4][4] = {
        {10, 20, 30, 40},
        {21, 31, 41, 51},
        {32, 42, 52, 62},
        {45, 55, 65, 75}
        };
    int first = 0, last, elem;
    n = sizeof(arr) / sizeof(int);
    last = n - 1;
    class BinarySearch A1;
     cout << "Enter you element which you want to search : ";
    cin >> elem;
    if (A1.binarySearch(arr, first, last, elem)==-1)
    {
        cout<<"Element is not prasent";
    }
} 
int BinarySearch ::binarySearch(int arr[4][4], int start, int end, int elem)
{
    int mid,m=4,n=4;
    int i = 0, j = m-1;
    while (i>=0 && j>=0 && i < n && j<m)
    {
        if (arr[i][j] == elem)
        {
            cout<<"Your Element is at ("<<i<<","<<j<<") th Index";
            return 1;
        }
        else if (arr[i][j]>elem)
        {
            j--;
        }
        else
        {
            i++;
        }
        
    }
    return -1;
}