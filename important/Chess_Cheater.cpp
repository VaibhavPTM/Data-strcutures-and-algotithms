// https://codeforces.com/problemset/problem/1427/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353llllll
#define pb push_back
#define endl "\n"
#define MAX 100002
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T=1;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> v;
        int w=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='W')
                w++;
        }
        if(w==0)
        {
            cout<<max(2*k-1,0)<<endl;
            continue;
        }
        w+=k;
        if(w>=n)
        {
            cout<<2*n-1<<endl;
            continue;
        }
        int l=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
                l++;
            else
            {
                v.pb(l);
                l=0;
            }
        }
        if(l!=0)
            v.pb(l);
        if(s[0]=='L')
            v.erase(v.begin());
        if(s[n-1]=='L')
            v.erase(v.begin()+v.size()-1);
        sort(v.begin(),v.end());
        int sp=0;
        int i;
        for(i=0;i<v.size();i++)
        {
            if(sp+v[i]>k)
                break;
            sp+=v[i];
        }
        int wl = v.size()-i;
        cout<<2*w - wl - 1<<endl;
    }
}