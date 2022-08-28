// Link : https://codeforces.com/problemset/problem/1471/B
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
    lli n, x;
    cin >> n >> x;
    bool flg = true;
    queue<pair<lli,lli>> pq;
    lli sum = 0;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        sum += t;
        if((t % x) == 0 && flg) {
            t /= x;
            sum += t * x;
            pq.push({t,x});
        }
        else flg = false;
    }
    while(!pq.empty() && flg) {
        pair<lli,lli> p = pq.front();
        pq.pop();
        if(p.first % x != 0) {
            cout << sum << endl;
            return;
        }
        else {
            lli tt = p.first / x;
            sum += tt * (x*p.second);
            pq.push(make_pair(tt,p.second*x));
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