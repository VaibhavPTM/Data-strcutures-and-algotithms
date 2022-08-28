// Link : 
#include<bits/stdc++.h>
using namespace std;
bool prime(int n) {if(n == 1) return false; for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;return true;}
#define TEST int t = 1; cin >> t; while(t--) solve();
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
#define print(x) for(auto it:x) cout<<it<<" ";cout << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"

void solve() {
    lli n;
    cin >> n;
    vec(lli) ar(n+1, 0);
    for(int i = 0; i < n; i++) {
        lli x;
        cin >> x;
        ar[x]++;
    }
    lli res = 0;
    for (int i = 1; i <= n; i++) {
        res += ar[i] * (ar[i] - 1) * (ar[i] - 2) / 6;
    }
    for (int i = 2; i < n; i++) {
        res += ar[i - 1] * ar[i] * ar[i + 1];
    }
    for(int i = 2; i < n; i++) {
        res += ar[i-1] * ar[i+1] * (ar[i+1]-1) / 2;
    }
    for(int i = 2; i < n; i++) {
        res += ar[i+1] * ar[i-1] * (ar[i-1]-1) / 2;
    }
    for (int i = 1; i < n; i++) {
        res += ar[i] * (ar[i] - 1) / 2 * ar[i + 1];
    }
    for (int i = 2; i <= n; i++) {
        res += ar[i - 1] * ar[i] * (ar[i] - 1) / 2;
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