// Link : https://codeforces.com/problemset/problem/1466/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool prime(ll n) {if(n == 1) return false; for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;return true;}
ll POW (ll a, ll p, ll m) { ll res = 1; while (p > 0) { if(p % 2 == 0){ p /= 2; a = ((a%m)*(a%m))%m; } else{ res = ((res%m)*(a%m))%m; p--; }}return res;}
#define TEST int t = 1; cin >> t; while(t--) solve();
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
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
#define print(x) for(auto it:x) cout<<it<<" ";cout << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define mem(n,i) memset(n, i,sizeof n)
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vec(int) w(n+1), d(n+1);
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        sum += w[i];
        d[i] = -1;
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        d[a]++, d[b]++;
    }
    maxhp(int) pq;
    for(int i = 1; i <= n; i++) {
        while(d[i]--) {
            pq.push(w[i]);
        }
    }
    cout << sum << " ";
    while(!pq.empty()) {
        sum += pq.top();
        cout << sum << " ";
        pq.pop();
    }
    cout << endl;

}   

int main() {
    SPEED
    TEST
    return 0;
}