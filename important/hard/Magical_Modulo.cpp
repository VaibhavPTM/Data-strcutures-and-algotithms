// Link : https://www.codechef.com/LTIME105B/problems/MAGICMOD
#include<bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll       long long
#define TEST     int t = 1; cin >> t; while(t--) solve();
#define SPEED    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define p(A,B)   pair<A,B>
#define all(v)   v.begin(), v.end()
#define allr(v)  v.rbegin(), v.rend()
#define vec(T)   vector<T>
#define vv(T)    vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define ff       first
#define ss       second
#define pb       push_back
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
template <typename T>
void print(vec(vec(T)) ar) { for(int i = 0; i < ar.size(); i++) { for(int j = 0; j < ar[i].size(); j++){ cout << ar[i][j] << " "; } cout << endl; } }
template <typename A>
void print (vec(A) ar) { for(A &i : ar)  cout << i << " "; cout << endl; }


void solve() {
    ll n;
    cin >> n;
    vec(int) ar(n), big, mp(n+1);
    set<int> s;
    ll sum = 0;
    ll main_sum = n * (n+1) / 2;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
        s.insert(ar[i]);
        if(ar[i] <= n) {
            mp[ar[i]]++;
        }
        else {
            big.pb(ar[i]);
        }
    }
    if(s.size() != n) {
        no
    }
    else {
        if(big.size() == 0) {
            cout << "YES" << " " << n+1 << endl;
            return;
        }
        sort(allr(big));
        int num = big.back();
        for(int i = n+1; i < num; i++) {
            if(abs(main_sum - sum) % i != 0) continue;
            vec(int) tt = mp;
            bool flg = true;
            for(int &j : big) {
                if(j % i == 0 || j%i > n || tt[j%i] > 0) {
                    flg = false;
                    break;
                }
                else {
                    tt[j%i]++;
                }
            }
            if(flg) {
                cout << "YES" << " " << i << endl;
                return;
            }
        }
        no
    }
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