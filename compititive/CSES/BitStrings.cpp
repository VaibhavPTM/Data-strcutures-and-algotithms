// Link : https://cses.fi/problemset/task/1617
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
    int res = 1;
    while(n--) {
        res = (res << 1) % MOD;
    }
    cout << res << endl;
    return 0;
}