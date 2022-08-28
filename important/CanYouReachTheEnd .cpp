// Link : 
#include<bits/stdc++.h>
using namespace std;
#define TEST int t = 1; cin >> t; while(t--) solve();
#define lli long long
#define p(A,B) pair<A,B>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define vec(T) vector<T>
#define vv(T) vector<vector<T> >
#define maxhp(T) priority_quecoutue<T>
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
    vector<pair<int,int>> ar;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ar.push_back({a,b});
    }
    if(n <= 2) {
        cout << "NO" << endl;
        return;
    }
    sort(all(ar));
    int x = 1, y = ar[0].second;
    bool flg = true, flg2 = true;
    for(int i = 0; i < ar.size() && y > 0; i++,x++,y--) {
        if(ar[i].first != x || ar[i].second != y) {
            flg = false;
            break;
        }
    }
    x = n, y = ar[n-1].second;
    for (int i = ar.size()-1; i >= 0 && y <= n; i--, x--, y++) {
        if(ar[i].first != x || ar[i].second != y) {
            flg2 = false;
            break;
        }
    }
    if(!flg && !flg2) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    TEST
    return 0;
}