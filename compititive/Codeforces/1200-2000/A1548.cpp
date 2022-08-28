// Link : https://codeforces.com/problemset/problem/1548/A
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
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
    int ar[1000010], u, v, n, m, q, a, ans = 0;
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        ar[min(u,v)]++;
    }
    for(int i = 1; i <= n; i++) {
        if(ar[i] == 0) ans++;
    }
    cin >> q;
    while(q--) {
        cin >> a;
        if(a == 3) {
            cout << ans << endl;
        }
        else if(a == 1) {
            cin >> u >> v;
            if(ar[min(u,v)] == 0) ans--;
            ar[min(u,v)]++;
        }
        else {
            cin >> u >> v;
            if(ar[min(u,v)] == 1) ans++;
            ar[min(u,v)]--;
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}