// Link : 
#include<bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll       long long
#define int       long long
#define TEST     int t = 1; cin >> t; while(t--) solve();
#define SPEED    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define p(A,B)   pair<A,B>
#define pb       push_back
#define all(v)   v.begin(), v.end()
#define allr(v)  v.rbegin(), v.rend()
#define vec(T)   vector<T>
#define vv(T)    vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define ff       first
#define ss       second
#define yes      cout << "YES" << endl;
#define no       cout << "NO" << endl;
#define ps(x,y)  fixed<<setprecision(y)<<x
#define mem(n,i) memset(n, i,sizeof n)
#define Case(i) cout << "Case #" << i << ": "
#define endl     "\n"
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
bool prime(ll n) {if(n == 1) return false; for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;return true;}
ll POW (ll a, ll p, ll m) { ll res = 1; while (p > 0) { if(p % 2 == 0){ p /= 2; a = ((a%m)*(a%m))%m;} else{ res = ((res%m)*(a%m))%m; p--; }}return res;}
ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
template <typename A, typename B>
void print (vec(p(A,B)) ar) { for(auto &i : ar) cout << i.ff << " " << i.ss << endl;}
template <typename A>
void print(vec(A) ar[], int n) { for(int i = 0; i < n; i++) {for(int j = 0; j < ar[i].size(); j++){cout << ar[i][j] << " "; } cout << endl; }}
template <typename T>
void print(vec(vec(T)) ar) { for(int i = 0; i < ar.size(); i++) { for(int j = 0; j < ar[i].size(); j++){ cout << ar[i][j] << " "; } cout << endl; } }
template <typename A>
void print (vec(A) ar) { for(A &i : ar)  cout << i << " "; cout << endl; }
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll getsum(ll n) {return (n*(n+1))/2;}
int tttt = 1;

int chain(int n) {
    int res = 1;
    while(n != 1) {
        if(n & 1) {
            n = (n * 3) + 1;
        }
        else {
            n /= 2;
        }
        res++;
    }
    return res;
}

void solve() {
    int res = INT_MIN;
    int res2 = INT_MAX;
    for(int i = 10000; i <= 1000000; i++) {
        int d = chain(i);
        if(res < d) {
            res = d;
            res2 = i;
        }
    }
    // cout << chain(13);
    cout << res2 << endl;
}
int32_t main() {
    SPEED
#ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
#endif
    // TEST
    solve();
    return 0;
}