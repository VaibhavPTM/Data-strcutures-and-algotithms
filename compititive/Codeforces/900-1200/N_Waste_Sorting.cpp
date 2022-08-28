// Link : https://codeforces.com/problemset/problem/1468/N
// Topic : 
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
    int c1, c2, c3;
    int ar[5];
    cin >> c1 >> c2 >> c3;
    cin >> ar[0] >> ar[1] >> ar[2] >> ar[3] >> ar[4];

    if(c1 < ar[0] || c2 < ar[1] || c3 < ar[2]) {
        cout << "NO" << endl;
        return;
    }
    c1 -= ar[0];
    c2 -= ar[1];
    c3 -= ar[2];
    int x = 0, y = 0;
    if(ar[3] > c1) x = ar[3] - c1;
    if(ar[4] > c2) y = ar[4] - c2;
    if(x + y > c3) cout << "NO" << endl;
    else cout << "YES" << endl;
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