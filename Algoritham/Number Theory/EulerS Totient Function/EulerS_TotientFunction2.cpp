// // in this algorithe, the time complexity is constent is O(1) or O(Nlog(logN))
// https://www.youtube.com/watch?v=Fv77-SOTxy8&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=27
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
int main()
{
    intn(1000000);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << phi[n]<<endl;
    }
    return 0;
}