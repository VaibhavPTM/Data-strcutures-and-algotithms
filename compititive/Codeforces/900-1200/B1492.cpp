// Link : https://codeforces.com/problemset/problem/1492/B
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
    priority_queue<pair<int,int>> pq;
    int n , mn = INT_MAX;
    cin >> n;
    int ar[n];
    vector<int> res;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        pq.push({ar[i],i});
    }
    while (!pq.empty()) {
        if(pq.top().second > mn) {
            pq.pop();
            continue;
        }
        mn = pq.top().second;
        for(int i = mn; i < n; i++) {
            res.push_back(ar[i]);
        }
        n = mn;
        pq.pop();
    }
    
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