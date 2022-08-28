// Link : https://codeforces.com/problemset/problem/1509/B
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
    string s;
    cin >> n >> s;
    int t = 0, m = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'M') {
            m++;
            if(t < m) {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            t++;
        }
    }
    int tt = 0, mm = 0;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'M') {
            mm++;
            if(tt < mm) {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            tt++;
        }
    }

    cout << (t == m*2 ? "YES" : "NO") << endl;

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