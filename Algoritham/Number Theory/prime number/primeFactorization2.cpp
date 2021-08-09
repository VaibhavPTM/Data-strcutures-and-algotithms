// In this approch we will get prime factors suing sieve do the the time complxity will be O(log(n))
#include <iostream>
using namespace std;
int primef[1000001];
void sieve()
{
    int maxn = 1000000;
    for (int i = 0; i <= maxn; i++)
        primef[i] = -1;

    for (int i = 2; i <= maxn; i++)
        if (primef[i] == -1)
        {
            for (int j = i; j <= maxn; j += i)
                if (primef[j] == -1)
                    primef[j] = i;
        }
    int n;
    cin >> n;
    while (n > 1)
    {
        cout << primef[n] << " ";
        n /= primef[n];
    }
}
int main()
{
    sieve();
    return 0;
}