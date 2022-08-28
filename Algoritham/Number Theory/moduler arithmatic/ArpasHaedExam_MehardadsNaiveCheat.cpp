// Here you have n in input and you have to find last digit of (8 ^ n) using moduler arithmatic
// n can be 0 <= n >= 100000
#include <iostream>
using namespace std;
#define lli long long int
lli find(lli a, lli n, lli mod)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % mod;
            n--;
        }
        else
        {
            a = (a * a) % mod;
            n /= 2;
        }
    }
    return res;
}
lli find(lli a, lli n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a);
            n--;
        }
        else
        {
            a = (a * a);
            n /= 2;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << find(8, n) << endl;
    cout << find(8, n, 10);

    return 0;
}