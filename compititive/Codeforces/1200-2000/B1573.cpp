// Link : https://codeforces.com/problemset/problem/1573/B
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
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
    int n;
    cin >> n;
    int odd[n], even[n];
    for(int i = 0;i < n; i++) cin >> odd[i];
    for(int i = 0; i < n; i++) cin >> even[i];
    map<int,int> m;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        m[odd[i]] = i;
        v.push_back({even[i],i});
    }
    sort(v.begin(), v.end());
    int t = INT_MAX;
    for(int i = v.size()-1;i >= 0; i--) {
        t = min(t,v[i].second);
        v[i].second = t;
    }
    int res = INT_MAX;
    int j = 0;
    for(int i = 1; i < 2*n; i+=2) {
        int x = m[i];
        x += v[j].second;
        res = min(res,x);
        j++;
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}