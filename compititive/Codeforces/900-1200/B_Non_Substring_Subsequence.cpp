// Link : https://codeforces.com/problemset/problem/1451/B
// Topic : 
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "#" + s;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        bool f = 0;
        for(int i = 1; i < l; i++) if(s[i] == s[l]) f = 1;
        for(int i = r+1; i <= n; i++) if(s[i] == s[r]) f = 1;
        cout << (f ? "YES" : "NO") << endl;
    }

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