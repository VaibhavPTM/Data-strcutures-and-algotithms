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
template <typename A>
void print (set<A> ar) { for(A &i : ar)  cout << i << " "; cout << endl; }

ll ceilDiv(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll getsum(ll n) {return (n*(n+1))/2;}
int nextGratDivNum(int l, int i) {return (ceilDiv(l, i)) * i;}

bool c(vec(vec(int)) &ar, int l, int r, int n, int m) {
    for(int i = 0; i < n; i++) {
        swap(ar[i][l], ar[i][r]);
        if(!is_sorted(all(ar[i]))) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vec(vec(int)) ar(n, vec(int) (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ar[i][j];
        }
    }
    set<p(int,int)> t;
    for(int i = 0; i < n; i++) {
        int l = 0, r = 0;
        bool f = true;
        for(int j = 1; j < m; j++) if(ar[i][j-1] > ar[i][j]) {
                if(!f) { r = j; break; }
                else { f = false; l = j-1; r = j;}
            }
        while(l-1 >= 0 && ar[i][l-1] == ar[i][l]) l--;
        while(r+1 < m && ar[i][r+1] == ar[i][r]) r++;
        if(!f) t.insert({l, r});
    }
    if(t.size() == 0) cout << 1 << " " << 1 << endl;
    else if(t.size() > 1) cout << -1 << endl;
    else {
        auto ii = *t.begin();
        if(c(ar, ii.ff, ii.ss, n, m)) {
            cout << ii.ff+1 << " " << ii.ss+1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}
int32_t main() {
    SPEED
#ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
#endif
    TEST
    // solve();
    return 0;
}