// Link : https://codeforces.com/problemset/problem/1421/B
#include<bits/stdc++.h>
using namespace std;
#define TEST int t = 1; cin >> t; while(t--) solve();
#define lli long long
#define p(A,B) pair<A,B>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define vec(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vec(string) ar(n);
    for(auto &i : ar) {
        cin >> i;
    }
    vec(p(int,int)) res;
    if(ar[0][1] == ar[1][0]) {
         if(ar[0][1] == '0') {
            if(ar[n-1][n-2] == '0') {
                res.pb({n,n-1});
            }
            if(ar[n-2][n-1] == '0') {
                res.pb({n-1,n});
            }
         }
         else {
            if(ar[n-1][n-2] == '1') {
                res.pb({n,n-1});
            }
            if(ar[n-2][n-1] == '1') {
                res.pb({n-1,n});
            }
         }
    }
    else if(ar[n-1][n-2] == ar[n-2][n-1]){
        if(ar[n-1][n-2] == '0') {
            if(ar[0][1] == '0') {
                res.pb({1,2});
            }
            if(ar[1][0] == '0') {
                res.pb({2,1});
            }
         }
         else {
            if(ar[0][1] == '1') {
                res.pb({1,2});
            }
            if(ar[1][0] == '1') {
                res.pb({2,1});
            }
         }
    }
    else { 
        char c = ar[0][1];
        res.pb({2,1});
        if(ar[n-1][n-2] == c) res.pb({n,n-1});
        else res.pb({n-1,n});

    }
    cout << res.size() << endl;
    for(p(int,int) &i : res) {
        cout << i.ff << " " << i.ss << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    TEST
    return 0;
}