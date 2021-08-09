#include <iostream>
#define lli long long int
using namespace std;

lli mulmod(lli a, lli b, lli mod)
{
    lli x = 0, y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2LL) % mod;
        b /= 2;
    }
    return x % mod;
}
lli binpower(lli a, lli n, lli mod)
{
    lli res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = mulmod(res, a, mod);
        }
        n >>= 1; // this line devide n by 2
        a = mulmod(a, a, mod);
    }
    return res % mod;
}

bool isprime(int n, int instreturs = 5)
{
    if (n <= 4)
        return n == 2 || n == 3;

    for (int i = 1; i <= instreturs; i++)
    {
        lli a = 2 + rand() % (n - 3);
        lli res = binpower(a, n - 1, n);
        if (res != 1)
            return false;
    }
    return true;
}
int main()
{
    lli t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (isprime(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}