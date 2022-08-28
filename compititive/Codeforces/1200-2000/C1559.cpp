// Link : https://codeforces.com/problemset/problem/1559/C
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
    int n;
    cin >> n;
    int t = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(!x) t = i;
    }
    if(!t) cout << n+1 << " ";
    for(int i = 1; i <= n; i++) {
        cout << i << " ";
        if(t == i) cout << n+1 << " ";
    }
    cout << endl;

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