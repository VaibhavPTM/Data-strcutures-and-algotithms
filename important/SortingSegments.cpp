// Link : https://www.codechef.com/SDELP21B/problems/SORTSEGS
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
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
#define endl "\n"

int helpr1(vec(int) ar, int n, int k) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(ar[i] != i+1) {
            res++;
            int l = i, r = min(i + k - 1, n - 1);
            sort(ar.begin()+l, ar.begin()+r+1); 
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(ar[i]  != i + 1) {
            int l = max(0, i - k + 1), r = i;
            sort(ar.begin()+l, ar.begin()+r+1); 
            res++;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(ar[i] != i+1) {
            res++;
            break;
        }
    }
    return res;
}
int helper2(vec(int) ar, int n, int k) {
    int res = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(ar[i]  != i + 1) {
            int l = max(0, i - k + 1), r = i;
            sort(ar.begin()+l, ar.begin()+r+1); 
            res++;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(ar[i] != i+1) {
            res++;
            int l = i, r = min(i + k - 1, n - 1);
            sort(ar.begin()+l, ar.begin()+r+1); 
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(ar[i] != i+1) {
            res++;
            break;
        }
    }
    return res;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vec(int) ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    cout << min(helpr1(ar,n,k), helper2(ar,n,k)) << endl;
}

int main() {
    SPEED
    TEST
    return 0;
}