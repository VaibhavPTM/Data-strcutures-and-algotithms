// Link : https://cses.fi/problemset/task/1643
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
    int ar[n];
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    lli sum = 0, res = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum += ar[i];
        res = max(res,sum);
        sum = max(sum,(lli)0);
    }
    cout << res;
    return 0;
}