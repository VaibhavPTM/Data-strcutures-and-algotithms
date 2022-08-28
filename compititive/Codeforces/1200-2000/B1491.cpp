// Link : https://codeforces.com/problemset/problem/1491/B
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define v(T) vector<T>
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
    int n, u, v;
    cin >> n >> u >> v;
    int ar[n];
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int res = INT_MAX - 10;
    for(int i = 0; i < n-1; i++) {
        int t = abs(ar[i] - ar[i+1]);
        if(ar[i] == ar[i+1]) {
            res = min(res,min(u+v,v+v));
        }
        else if(t == 1){
            if(min(ar[i],ar[i+1]) == 0 || max(ar[i],ar[i+1]) == 1000001){
                res = min(res,u);
            }
            else {
                res = min(res,min(u,v));
            }
        }
        else if(abs(ar[i] - ar[i+1]) > 1) res = 0;
    }
    cout << (res == INT_MAX ? 0 : res) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}