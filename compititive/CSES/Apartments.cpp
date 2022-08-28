// Link : https://cses.fi/problemset/task/1084
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    lli n, m, k;
    cin >> n >> m >> k;
    lli nar[n], mar[m];
    for(int i = 0; i < n; i++) {
        cin >> nar[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> mar[i];
    }
    sort(nar,nar+n);
    sort(mar,mar+m);
    int res = 0;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(nar[i] - k <= mar[j] && nar[i]+k >= mar[j]) {
            res++;
            i++;
            j++;
        }
        else if(nar[i]+k < mar[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    cout << res;

    return 0;
}