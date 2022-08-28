// Link : https://cses.fi/problemset/task/1072
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    lli n;
    cin >> n;
    for(lli i = 1; i <= n; i++) {
        // (n - 1)(n + 4)(n^2 - 3n + 4)/2
        // https://oeis.org/A172132
        cout << ((i-1) * (i+4) * ((i*i) - (3*i) + 4)) / 2 << endl;
    }
    return 0;
}