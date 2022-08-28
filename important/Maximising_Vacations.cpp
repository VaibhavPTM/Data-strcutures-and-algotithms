// Link : https://www.codechef.com/START23B/problems/MAXVAC
#include<bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll       long long
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


void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int prefix[n] = {}, postfix[n] = {};
    prefix[0] = (s[0] == '0');
    for(int i = 1; i < n; i++) {
        if(s[i] == '0') {
            prefix[i] = prefix[i-1]+1;
        }
        else {
            prefix[i] = 0;
        }
    }
    postfix[n-1] = (s[n-1] == '0');
    for(int i = n-2; i >= 0; i--) {
        if(s[i] == '0') {
            postfix[i] = postfix[i+1]+1;
        }
        else {
            postfix[i] = 0;
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(prefix[i] == 0 && i > 0) {
            res += prefix[i-1] / k;
        }
    }
    res += prefix[n-1] / k;
    int orig_ans = res;
    for(int i = 0; i < n; i++) {
        if(s[i] != '0') {
            int o_l = 0, o_r = 0;
            if(i > 0) {
                o_l = prefix[i-1];
            }
            if(i < n-1) {
                o_r = postfix[i+1];
            }
            int c = (o_r + o_l + 1) / k - o_r / k - o_l / k;
            res = max(res, orig_ans + c);
        }
    }
    cout << res << endl;
}
int main() {
    SPEED
#ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
#endif
    TEST
    // solve();
    return 0;
}