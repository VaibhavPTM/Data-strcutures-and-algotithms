// Link : 
#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define pii pair<int,int>
#define pll pair<lli,lli>
#define v(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T> , greater<T> >
#define pb push_back
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
void solve() {
    int n, k, mx = 0;
    cin >> n >> k;
    lli res = 0;
    unordered_map<lli, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx,x);
        mp[x]++;
    }
    int i = mp[mx];
    while(k > 0 && mx > 0) {
        if(i <= k) {
            res += (mx * i) % mod;
            mx--;
            k -= i;
            if(mp.find(mx) != mp.end()) i += mp[mx];
            // cout << mx << " " << i << endl;
        }
        else {
            res += (mx * k) % mod;
            break;
        }
    }
    cout << res;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}