// Link : https://codeforces.com/problemset/problem/1547/C
// Topic :  greedy    two pointers    *1100
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
    int k, n, m;
    int i = 0, j = 0;
    cin >> k >> n >> m;
    int nn[n], mm[m];
    v(int) res;
    for(int i = 0; i < n; i++) {
        cin >> nn[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> mm[i];
    } 
    while(i < n || j < m) {
        if(i < n && nn[i] <= k) {
            res.push_back(nn[i]);
            if(nn[i++] == 0) k++;
        }
        else if(j < m && mm[j] <= k) {
            res.push_back(mm[j]);
            if(mm[j++] == 0) k++;
        }
        else break;
    }
    if(res.size() != n+m) cout << "-1";
    else print(res);
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