// Link : https://codeforces.com/contest/1574/problem/C
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
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
    int n, q;
    cin >> n;
    v(lli) ar(n);
    lli sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    sort(ar.begin(), ar.end());
    cin >> q;
    while(q--) {
        vector<lli> res;
        lli x, y;
        cin >> x >> y;
        int l = 0, r = n-1, mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if(ar[mid]>x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(ar[r] >= 0) {
            lli t = max(0ll, x - ar[r]) + max(0ll, y - (sum - ar[r]));
            res.push_back(t);
        }
        if(r+1 < n) {
            lli t = max(0ll, x - ar[r+1]) + max(0ll, y - (sum - ar[r+1]));
            res.push_back(t);
        }
        sort(res.begin(),res.end());
        cout << res[0] << endl;
    }
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