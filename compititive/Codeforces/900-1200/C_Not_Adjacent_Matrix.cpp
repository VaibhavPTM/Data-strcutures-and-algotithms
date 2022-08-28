// Link : https://codeforces.com/problemset/problem/1520/C
// Topic :  constructive algorithms    *1000
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
    cin >> n;
    if(n == 1) cout << 1 << endl;
    else if(n == 2) cout << -1 << endl;
    else {
        int f = 1, s = (n*n+1)/2 + 1;
        bool fp = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(fp) cout << f++ << " ", fp = !fp;
                else cout << s++ << " ",fp = !fp; 
            }
            cout << endl;
        }
    }
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