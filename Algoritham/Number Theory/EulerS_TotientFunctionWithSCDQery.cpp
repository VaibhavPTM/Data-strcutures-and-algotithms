#include <iostream>
using namespace std;
int phi[1000001];
void intn(int maxn)
{
    for (int i = 1; i <= maxn; i++)
    {
        phi[i] = i;
    }
    for (int i = 2; i <= maxn; i++)
    {
        if(phi[i] == i){
            for (int j = i; j <= maxn; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }     
        }
    }
}
int getcoaunt(int d , int n){
    intn(1000000);
    return phi[n/d];
}
int main()
{
    int t, n;
    int res = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0){
                int d1 = i;
                int d2 = n / i;
                res += d1 * getcoaunt(d1 , n);
                if(d1 != d2)
                res += d2 * getcoaunt(d2 , n);
            }
        }
    }
    return 0;
}