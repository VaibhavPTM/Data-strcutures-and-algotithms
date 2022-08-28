// Link : https://codeforces.com/problemset/problem/1419/A
// Topic :  games    greedy    implementation    *900
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
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int odd = false, even =false;
    for (int i = 1; i <= n; i++) {
        if(i & 1) odd |= ((s[i-1] - '0') & 1);
        else even |= (((s[i-1] - '0') & 1) == 0);
    }
    if(n&1) cout << (odd ? 1 : 2) << endl;
    else cout << (even ? 2 : 1) << endl;
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
