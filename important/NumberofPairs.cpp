// Link : https://codeforces.com/problemset/problem/1538/C
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
    int n, l1, r1;
    cin >> n >> l1 >> r1;
    vec(lli) ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(all(ar));
    lli res = 0;
    int l = 1, r = n-1;
    for(int i = 0; i < n-1 && l <= r; i++) {
        while(l <= i) l++;
        while(i < l-1 && ar[i]+ar[l-1] >= l1) l--;
        while(l < r && ar[i]+ar[l] < l1) l++; 
        while(r > l && ar[i]+ar[r] > r1) r--;
        // cout << i << " " << l << " " << r << endl;
        if(ar[i]+ar[l] >= l1 && ar[i]+ar[r] <= r1){ 
            // cout << i << " " << l << " " << r << endl;
            res += ((r-l) + 1);
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