// Link : https://www.codechef.com/START11C/problems/COUNTA
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
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
const lli t = 1e5;
const lli mod = 998244353;
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    lli sum = 0;
    int prev = 0;
    v(int) ar(n);
    for(int i = 1; i < n; i++) {
        cin >> ar[i];
    }
    if(n == 2) {
        sum = ((t - ar[1]) + (t - ar[1] + 1)) % MOD;
        cout << sum << endl;
        return;
    }
    else if(n == 3) {
        if(ar[1] != ar[2]) {
            int tt = max(ar[1],ar[2]);
            sum = ((t - tt) + (t - tt + 1)) % MOD;
        }
        else {
            sum = ((t - ar[1]) + (t - ar[1] + 1) + (t - ar[1])) % MOD;
        }
        cout << sum << endl;
        return;
    }
    for(int i = 1; i <= n-1; i++) {
        if(ar[i] > ar[i+1]) {
            sum = (t - ar[i]) % MOD;
            break;
        }
        else if(i == n-1) {
            sum = ((t - ar[i]) + (t - ar[i] + 1)) % MOD;
        }
        else if(i > 1 && ar[i] > ar[i-1] && ar[i] > ar[i+1]) {
            sum = ((t - ar[i]) + (t - ar[i] + 1)) % MOD;
            break;
        }
        else if(ar[i] == ar[i+1]) {
            if(prev) {
                sum = (sum +(t - ar[i])) % MOD;
            }
            else {
                sum = (sum + ((t - ar[i]) + (t - ar[i] + 1))) % MOD;
            }
            prev = 1;
        }
    }

    cout << sum << endl;
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