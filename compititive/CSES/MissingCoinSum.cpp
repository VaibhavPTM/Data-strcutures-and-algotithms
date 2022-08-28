// Link : https://cses.fi/problemset/task/2183
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
    sort(ar,ar+n);
    lli res = 1;
    for(int i = 0; i < n; i++) {
        if(res < ar[i]) {
            break;
        }
        else {
            res += ar[i];
        }
    }
    cout << res;
    return 0;
}