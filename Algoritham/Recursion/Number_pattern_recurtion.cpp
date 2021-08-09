#include <iostream>
using namespace std;
void solve(int n, int t, int t1, int t3)
{
    if (t <= 0 && n == t1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    if (n <= 0)
    {
        t3 = n;
    }
    if (t3 <= 0)
    {
        t = t3;
        solve(n + 5, t, t1, t3);
    }
    else
    {
        solve(n - 5, t, t1, t3);
    }
    return;
}
int main()
{
    int cas;
    cin >> cas;
    int arr[cas];
    int t = 1;
    int t3 = 1;
    for (int i = 0; i < cas; i++)
    {
        cin>>arr[i];
    }
    
    int t1[cas];
    for (int i = 0; i < cas; i++)
    {
        t1[i] = arr[i];
    }
    

    for (int i = 0; i < cas; i++)
    {
        solve(arr[i], t, t1[i], t3);
        cout<<"\n";
    }
    return 0;
}