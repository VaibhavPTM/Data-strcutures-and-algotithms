// Link : https://codeforces.com/problemset/problem/1511/C
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
    int n, q, x, i = 1, ar[51]{};
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        ar[x] += (!ar[x]) * i;
    }
    while(q--) {
        cin >> x;
        for(int i = 1; i<= 50; i++) {
            if(ar[i] < ar[x]) ar[i]++;
        }
        cout << ar[x] << " ";
        ar[x] = 1;
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