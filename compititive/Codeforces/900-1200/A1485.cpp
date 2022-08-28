// Link : https://codeforces.com/problemset/problem/1485/A
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
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
int cal(int a, int b) {
    if(b == 1) return mod;
    int cnt = 0;
    while(a) a/=b,cnt++;
    return cnt;
}
void solve() {
    lli a, b;
    cin >> a >> b;
    int res = 1e5;
    for(int i = 0; i < 30; i++) {
        res = min(res,cal(a,b+i)+i);
    }
    cout << res << endl;
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