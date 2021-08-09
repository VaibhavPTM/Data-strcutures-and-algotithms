#include <iostream>
#include <vector>
using namespace std;
int Bs(int[], int, int, int, int);
bool isValied(int[], int, int, int);
int maxElemet(int[], int);
int sumOfBooks(int[], int);

int main()
{
    int cases;
    cout << "Enter the number of cases : ";
    cin >> cases;
    while (cases--)
    {
        int st;
        cout << "Enter the number of student : ";
        cin >> st;
        int books;
        cout << "Enter the number of books : ";
        cin >> books;
        if (st > books)
        {
            cout << "Allocation of books is not possible" << endl;
            continue;
        }

        int arr[books];
        cout << "Enter the pages of books : " << endl;
        for (int i = 0; i < books; i++)
        {
            cin >> arr[i];
        }
        int start = maxElemet(arr, books);
        int end = sumOfBooks(arr, books);
        cout << "One Student got the " << Bs(arr, start, end, books, st) << " Pages" << endl;
    }
    return 0;
}
int maxElemet(int arr[], int max)
{
    int result;
    for (int i = 0; i < max; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            result = arr[i];
        }
    }
    return result;
}
int sumOfBooks(int arr[], int max)
{
    int sum = 0;
    for (int i = 0; i < max; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int Bs(int arr[], int start, int end, int n, int k)
{
    int mid, result = 0;

    while (start <= end)
    {  // 10 20 30 40 50 60
        mid = start + (end - start) / 2;
        if (isValied(arr, k, n, mid) == true)
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
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
    if (k > n)
    {
        return false;
    }
    int student = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > max)
        {
            student++;
            sum = arr[i];
        }
    }
    if (student > k)
    {
        return false;
    }
    return true;
}
