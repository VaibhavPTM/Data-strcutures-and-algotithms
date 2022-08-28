// Link : https://codeforces.com/problemset/problem/1473/B
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
    string a, b;
    cin >> a >> b;
    if(b.size() > a.size()) swap(a,b);
    int t = b.size();
    int tt = a.size();
    int x = 0;
    while(1) {
        x++;
        int y = tt * x;
        if(y % t == 0) break;
    }
    string aa = a;
    for(int i = 0; i < x-1; i++) {
        a += aa;
    }
    for(int i = 0; i < a.size(); i += t) {
        if(b != a.substr(i,t)) {
            cout << -1 << endl;
            return;
        }
    }
    cout << a << endl;
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