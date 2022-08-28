// Here the time complexity is O(sqrt(N))
// This function couts the numver of posutuve integers up to n to coprime to n
// copirme to n means GCD(n,x) = 1
#include <iostream> 
using namespace std;
int phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) {
            res /= i;
            res *= (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
    {
        res /= n;
        res *= (n - 1);
    }
    return res;
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << "ETF of N = " << phi(n) << endl;
    }

    return 0;
}