// Link : https://codeforces.com/problemset/problem/1497/C1
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
    int n, k;
    cin >> n >> k;
    if(n&1)
        cout << 1 << " " << (n-1)/2 << " " << (n-1) / 2 << endl;
    else {
        int t = (n-2)/2;
        if((t & 1) == 0) {
            cout << 2 << " " << t << " " << t << endl;
        }
        else {
            cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
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