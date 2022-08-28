// Link : https://codeforces.com/problemset/problem/1534/C
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
int a[400005], b[400005], to[400005], v[400005];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        v[i] = 0;
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        to[a[i]] = b[i];
    }
    lli res = 1;
    for(int i = 1; i <= n; i++) {
        if(v[i]) continue;
        res = (res * 2ll) % MOD;
        v[i] = 1;
        int p = i;
        while(!v[to[p]]) {
            p = to[p];
            v[p] = 1;
        }
    }
    cout << res << endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    TEST
    return 0;
}