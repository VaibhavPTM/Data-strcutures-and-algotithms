// Link : 
// Topic : 
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
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"
#define MAX 100001


void solve() {
    lli n, k, x;
    cin >> n >> k >> x;
    v(lli) ar(n), diff;
    for(int i= 0; i < n; i++) {
        cin >> ar[i];
    }
    int res = 1;

    sort(ar.begin(),ar.end());
    for(int i = 1; i < n; i++) {
        lli dff = ar[i] - ar[i-1];
        if(dff > x) {
            if(k == 0) res++;
            else {
                diff.push_back(dff);
            }
        }
    }
    sort(diff.begin(),diff.end());
    for(lli i : diff) {
        i = i % x == 0 ? i / x - 1 : i / x;
        if(i > k) res++;
        else {
            k -= i;
        }
    }
    cout << res << endl;
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