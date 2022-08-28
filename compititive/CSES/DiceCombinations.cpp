// Link : https://cses.fi/problemset/task/1633
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    lli dp[n];
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(i <= 6)
            dp[i] = (dp[i-1] * 2) % MOD;
        if(i > 6) {
            //         i-6-1;
            dp[i] = (((dp[i-1] * 2) % MOD) - dp[i-7]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}