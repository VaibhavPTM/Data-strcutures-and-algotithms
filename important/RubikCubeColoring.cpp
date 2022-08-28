// Link : https://codeforces.com/problemset/problem/1594/E1
#include<bits/stdc++.h>
using namespace std;
#define TEST int t = 1; while(t--) solve();
#define lli long long
#define p(A,B) pair<A,B>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define vec(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define mem(n,i) memset(n, i,sizeof n)
#define endl "\n"
const lli mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    lli res = 6;
    lli c = 4;
    while(n != 1) {
        c = (c%mod) * (c%mod) % mod;
        res = (res % mod) * (c % mod) % mod;
        n--;
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    TEST
    return 0;
}