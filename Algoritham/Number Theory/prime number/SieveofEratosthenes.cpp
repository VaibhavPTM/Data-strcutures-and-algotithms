// Link : 
#include<bits/stdc++.h>
using namespace std;
#define lli long long
bool prime(int n) {if(n == 1) return false; for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;return true;}
lli POW (lli a, lli p, lli m) { lli res = 1; while (p > 0) { if(p % 2 == 0){ p /= 2; a = ((a%m)*(a%m))%m; } else{ res = ((res%m)*(a%m))%m; p--; }}return res;}
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
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
int pp[1000001];
void sieve(void) {
    int maxN = 1e6 + 1;
    for (int i = 1; i <= maxN; i++) {
        pp[i] = 1;
    }
    pp[0] = pp[1] = 0;
    for (int i = 2; i * i <= maxN; i++) {
        if (pp[i]) {
            for (int j = i * i; j <= maxN; j+=i) {
                pp[j] = 0;
            }
        }
    }
}

void solve() {

}
int main() {
    SPEED
    sieve();
    TEST
    return 0;
}