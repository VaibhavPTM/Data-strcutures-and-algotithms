// Link : https://codeforces.com/problemset/problem/1490/D
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
void solve(int i, int j, v(int) &res, vector<int> ar, int curr_depth) {
    if(i > j) return;
    int mx = -1;
    int mxIdx = i;
    for(int k = i; k <= j; k++) {
        if(mx < ar[k]) {
            mx = ar[k];
            mxIdx = k;
        }
    }
    // divide and conquer
    res[mxIdx] = curr_depth;
    solve(i,mxIdx-1,res,ar,curr_depth+1);
    solve(mxIdx+1,j,res,ar,curr_depth+1);
}
void solve() {
    int n;
    cin >> n;
    v(int) res(n,-1), ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    solve(0,n-1,res,ar,0);
    print(res);
    cout << endl;
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