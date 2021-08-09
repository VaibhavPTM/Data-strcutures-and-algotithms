#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[1001];
    int sum = 0;
    int n;
    cin >> n;
    sort(arr, arr + n, greater<int>());
    for (int i = 1; i <= n; i++)
    {
        cout<<"Enter : ";
        cin >> arr[i];
        
    }
    for (int i = 0; i < 31 /*maximum bit of int*/ ; i++)
    {
        int countZ = 0, countO = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] & (1 << i))
            {
                countO++;
            }
            else
            {
                countZ++;
            }
            int p = countZ * countO;
            sum += (1 << i) * p;
        }
    }
    cout<<sum; 
    return 0;
}