// Link : https://codeforces.com/problemset/problem/1519/B
// Topic :  dp    math    *800
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
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
#define MAX 100001

void solve() {
    int n, m ,k;
    cin >> n >> m >> k;
    vv(int) dp(n,vector<int> (m));
    dp[0][0] = 0;
    for(int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i-1] + 1;
    }
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[i][j] = (i+1) + dp[i][j-1];
        }
    }
    if(dp[n-1][m-1] == k) cout << "YES" << endl;
    else cout << "NO" << endl;

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