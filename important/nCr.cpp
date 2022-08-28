// Link : https://codeforces.com/contest/1475/problem/E
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
#define ps(x,y) fixed<<setprecision(y)<<x
#define mem(n,i) memset(n, i,sizeof n)
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define endl "\n"
int fmpower(int a,int n) {
    int p=1;
    while(n>0) {
        if(n&1)
            p=((p%M)*(a%M))%M;
        a=((a%M)*(a%M))%M;
        n=n>>1;
    }
    return p;
}
ll f(int n) {
    ll res = 1;
    for(int i = 2; i <= n; i++) {
        res = (res*i )%M;
    }
    return res;
}
ll C(ll n, ll k) {
  return f(n) * fmpower(f(k), M - 2) % M * fmpower(f(n - k), M - 2) % M;
}
void solve() {
    int n, k;
    cin >> n >> k;
    int ar[n+1] = {};
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ar[x]++;
    }
    vec(p(int,int)) a;
    int t = k;
    for(int i = n; i >= 1 && t > 0; i--) {
        if(ar[i] != 0) {
            a.pb({i,ar[i]});
            t -= ar[i];
        } 
    }
    sort(all(a));
    int sum = 0;
    for(int i = 1; i < a.size(); i++) {
        sum += a[i].ss;
    }
    int k1 = a[0].ss;
    cout << C(k1,k-sum) << endl;
}

int main() {
    SPEED
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif
    TEST
    return 0;
}