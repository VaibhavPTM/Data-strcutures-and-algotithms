// Link : https://codeforces.com/problemset/problem/1485/B
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, k;
    cin >> n >> q >> k;
    int ar[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << k + (ar[r] - ar[l] + 1) - 2 * (r - l + 1) << endl;
    }
    return 0;
}