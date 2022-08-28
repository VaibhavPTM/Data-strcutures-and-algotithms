// Link : https://codeforces.com/problemset/problem/1409/C
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
    int n;
    cin >> n;
    lli ar[n];
    lli res = 1;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar,ar+n);
    res = max(ar[0]*ar[1]*ar[2]*ar[3]*ar[n-1],ar[0]*ar[1]*ar[n-1]*ar[n-2]*ar[n-3]);
    res = max(res,ar[n-1]*ar[n-2]*ar[n-3]*ar[n-4]*ar[n-5]);
    cout << res << endl;
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