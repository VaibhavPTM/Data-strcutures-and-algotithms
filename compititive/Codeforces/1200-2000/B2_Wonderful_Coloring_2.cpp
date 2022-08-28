// Link : https://codeforces.com/contest/1551/problem/B2
// Topic : binary search    constructive algorithms    data structures    greedy    *1400
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
#define MAX 100001 * 2

int arr[MAX];

void solve() {
    int n, k;
    cin >> n >> k;
    v(int) res(n,0);
    pair<int,int> p[n+1];
    int m = 0;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(mp[arr[i]] < k) {
            mp[arr[i]]++;
            p[m++] = make_pair(arr[i],i);
        }
    }
    sort(p, p + m);
    m -= m % k;
    for(int i = 0; i < m; i++) res[p[i].second] = i % k + 1;
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