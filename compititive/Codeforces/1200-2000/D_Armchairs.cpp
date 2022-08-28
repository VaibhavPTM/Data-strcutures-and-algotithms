// Link : https://codeforces.com/contest/1525/problem/D
// Topic : dp    flows    graph matchings    greedy    1800*
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
#define endl "\n"
#define MAX 5001

int arr[MAX];

void solve() {
    int nn, x;
    cin >> nn;
    v(int) one = {0} ,zero = {0};
    for(int i = 0; i < nn; i++) {
        cin >> x;
        if(x) one.pb(i);
        else zero.pb(i);
    }
    int n = one.size();
    int m = zero.size();
    if(n == 1 || m == 1) cout << '0' << endl;
    else  {
        vv(int) dp(n, vector<int> (m,INT_MAX / 10));
        for(int i = 0; i < m; i++) {
            dp[0][i] = 0;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i][j-1],abs(zero[j] - one[i]) + dp[i-1][j-1]);
            }
        }
        cout << dp[n-1][m-1] << endl;
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