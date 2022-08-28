#include <iostream>
#define mod 1000000007
using namespace std;
int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        res = (res * 1LL * a) % mod;

        a = (a * 1LL * a) % mod;
        n /= 2;
    }
    return res;
}
int arr[1000001];
int C(int n, int k)
{
    if (n < k){
        return 0;
    }
    int res = arr[n];
    // now we need to to arr[n] / arr [k] * arr[n - k] and we are working in modulo system so we need to do
    // res = arr[n] * invrse(arr[n - k])
    res = (res * 1LL * power(arr[k], mod - 2)) % mod;
    res = (res * 1LL * power(arr[n - k], mod - 2)) % mod;
    return res;
}
int main()
{
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        arr[i] = (arr[i - 1] * 1LL * i) % mod;
    }
    int t;
    int n, k;
    cin>>t;
    while (t--)
    {
        cin >> n >> k; // you have to enter the number that k < n will be
        cout << C(n, k) << endl;
    }

    return 0;
}
