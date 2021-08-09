// Here you have given a (a,b,n) and you have to find GCD of ((a^n+b^n),a-b) number
// and the problem is from codechef and the name is in title
#include <iostream>
using namespace std;
#define mod 1000000007
#define lli long long int
lli power(lli a, lli n, lli MOD)
{
    lli res = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            res = ((res % MOD) * (a % MOD)) % MOD;
            n--;
        }
        else
        {
            a = ((a % MOD) * (a % MOD)) % MOD;
            n /= 2;
        }
    }
    return res;
}
lli GCD(lli a, lli b, lli n)
{
    if (a == b)
    {
        return (power(a, n, mod) + power(b, n, mod)) % mod;
    }
    lli candidate = 1;
    lli num = a - b;
    for (lli i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            lli tamp = (power(a, n, i) + power(b, n, i)) % i;
            if (tamp == 0)
            {
                candidate = max(candidate, i);
            }
            tamp = (power(a, n, num / i) + power(b, n, num / i)) % (num / i);
            if (tamp == 0)
            {
                candidate = max(candidate, num / i);
            }
        }
    }
    return candidate % mod;
}

int main()
{
    lli a, b, n;
    int t;
    cin >> t;
    while (t--)
    {
        cin >>a>> b>> n;
        cout << GCD(a, b, n) << endl;
    }

    return 0;
}