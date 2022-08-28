// Link : https://codeforces.com/problemset/problem/1450/B
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
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
    int n, k;
    cin >> n >> k;
    vector<pair<lli,lli> > ar(n);
    v(bool) vis(n,false);
    for(int i = 0; i < n; i++) {
        cin >> ar[i].first >> ar[i].second;
    }
    for(int i = 0; i < n; i++) {
        bool mila = true;
        for(int j = 0; j < n; j++){
            if(abs(ar[i].first - ar[j].first) + abs(ar[i].second - ar[j].second) > k) {
                mila = false;
            }
        }
        if(mila) {
            cout << "1" << endl;
            return;
        }
    }
    cout << "-1" << endl;
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