// Link : https://codeforces.com/contest/1409/problem/B
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
void solve() {
    lli a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    lli diff1 = a - x;
    lli diff2 = b - y;
    if(diff1 + diff2 <= n) {
        cout << x * y << endl;
        return;
    }
    lli res = 9223372036854775807;
    if(diff1 >= n) {
        res = min(res,(a-n)*b);
    }
    if(diff2 >= n){
        res = min(res,(b-n)*a);
    }
    if(diff1 < n) {
        res = min(res,x*(b-(n-diff1)));
    }
    if(diff2 < n) {
        res = min(res,y * (a-(n-diff2)));
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