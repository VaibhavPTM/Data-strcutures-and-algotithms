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
    int n, m;
    cin >> n >> m;
    vec(p(int,int)) ar(m*n);
    for(int i = 0; i < m*n; i++) {
        cin >> ar[i].ff;
        ar[i].ss = i;
    }
    sort(all(ar));
    for (int i = 0; i < n * m; i++) {
        ar[i].ss = -ar[i].ss;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        sort(ar.begin() + (i*m), ar.begin() + (i*m+m));
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < j; k++) {
                if(ar[i*m+k].ss > ar[i*m+j].ss) res++;
            }
        }
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