// Link : https://cses.fi/problemset/task/2216
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
    int t[n+1], res = 1;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        t[x] = i;
    }
    for(int i = 2; i <= n; i++) {
        if(t[i-1] > t[i]) res++;
    }
    cout << res;
    return 0;
}