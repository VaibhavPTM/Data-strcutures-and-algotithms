// Link : https://codeforces.com/problemset/problem/1472/C
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
    int n, mx = 0;
    cin >> n;
    int ar[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for(int i = n; i >= 1; i--) {
        if(i + ar[i] <= n) {
            ar[i] = ar[i] + ar[i+ar[i]];
        }
        mx = max(mx,ar[i]);
    }
    cout << mx << endl;
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