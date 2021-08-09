#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Bs(int[], int, int, int, int);
bool isValied(int[], int, int, int);

int main()
{
    int cases;
    cout << "Enter the number of cases : ";
    cin >> cases;
    while (cases--)
    {
        int st;
        cout << "Enter the number of bulls : ";
        cin >> st;
        int books;
        cout << "Enter the number of stoles : ";
        cin >> books;
        if (st > books)
        {
            cout << "Allocation of books is not possible" << endl;
            continue;
        }

        int arr[books];
        cout << "Enter the distance between stoles : " << endl;
        for (int i = 0; i < books; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + books);
        // sort(arr[0],arr[books-1]);
        int start = arr[0];
        int end = arr[books - 1];
        cout << "The minimum distance of nothces is " << Bs(arr, start, end, books, st) << endl;
    }
    return 0;
}
int Bs(int arr[], int start, int end, int n, int k)
{
    int mid, result = 0;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isValied(arr, k, n, mid) == true)
        {
            result = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (result != 0)
    {
        return result;
    }
    return -1;
}
bool isValied(int arr[], int k, int n, int max)
{
    int cows = 1, last_pos = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - last_pos) >= max)
        {
            if (++cows == k)
                return true;
            last_pos = arr[i];
        }
    }
    return false;
}