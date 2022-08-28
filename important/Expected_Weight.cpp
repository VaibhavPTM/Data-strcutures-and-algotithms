// https://www.codechef.com/LTIME102B/problems/EXPWEI
#include<bits/stdc++.h>
#include <stdio.h>
#include "string.h"
using namespace std;
#define int long long 
#define float double 
#define pb push_back
#define all(x) x.begin(),x.end() 
#define con(s1,s2) strstr(s1.c_str(),s2.c_str())
#define foreach(x,y) for(auto &x:y)
#define allr(x) x.rbegin(),x.rend()
#define sum(a) accumulate(a.begin(), a.end(), (int)0)
#define ff first
#define ss second
#define pi pair<int,int>
int M = 998244353;
int fmpower(int a,int n) {
    int p=1;
    while(n>0) {
        if(n&1)
            p=((p%M)*(a%M))%M;
        a=((a%M)*(a%M))%M;
        n=n>>1;
    }
    return p;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(0)<<fixed;
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int ans = (n*(n+1))/2;
        int fi = n;
        int x = ans/__gcd(ans,fi);
        fi = fi/__gcd(fi,ans);
        int y = ans/__gcd(ans,fi);
        fi = fi/__gcd(fi,ans);
        ans = (y%M*x%M)%M;
        ans = (ans%M*fmpower(fi,M-2))%M;
        cout<<ans<<endl;
    }
    return 0;
}