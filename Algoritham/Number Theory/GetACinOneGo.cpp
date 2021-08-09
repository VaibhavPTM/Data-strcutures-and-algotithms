// This problem is from codechef and name of this problem is get ac in one go
// prolem is releted to LDA
#include <iostream>
using namespace std;
int gcd(int m, int n)
{
    if (n == 0)
    {
        return m;
    }
    else
        return gcd(n, m % n);
}
int main()
{
    long long int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int gcd1 = gcd(n, m);
        if (gcd1 > 1)
            cout << -1 << endl;
        else
            cout << (m * n - m - n + 1) << endl;
    }
    return 0;
}