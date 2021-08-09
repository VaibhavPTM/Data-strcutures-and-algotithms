#include<iostream>
using namespace std;
// The proble is from codeshaph called gcd queries
int arr[100001];
int pre[100005] , suff[100005];
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int t,q,n,l,r;
    cin>>t;
    while (t--)
    {
        cin>>n>>q;
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        pre[0] = suff[n+1] = 0;
        for (int i = 1; i <= n; i++)
        {
            pre[i] = gcd(pre[i - 1],arr[i]);
        }
        for (int i = n; i>=1; i--)
        {
            suff[i] = gcd(arr[i] , suff[i+1]);
        }
        while (q--)
        {
            cin>>l>>r;
            cout<<gcd(pre[l-1],suff[r+1])<<endl;
        }   
    }
    return 0;
}