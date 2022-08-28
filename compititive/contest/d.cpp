// Link : 
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
    int n;
    cin >> n;
    vector<pair<int,int>> ar(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> ar[i].first;
        ar[i].second = i;
    }
    sort(ar.begin()+1,ar.end());
    vector<pair<int,int>> res;
    int l = n-1, r = n;
    while(l > 0 && r > 0) {
        if(l == r) l--;
        else if(ar[l].first > 0 && ar[r].first > 0) {
            res.push_back({ar[l].second, ar[r].second});
            ar[l].first--;
            ar[r].first--;
        }
        else if(ar[l].first <= 0) {
            l--;
        }
        else {
            r--;
        }
    }
    if(res.empty()) {
        cout << "0" << endl;
        return;
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
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