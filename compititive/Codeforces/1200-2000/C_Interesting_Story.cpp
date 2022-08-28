// Link : https://codeforces.com/contest/1551/problem/C
// Topic : greedy    sortings    strings    *1500
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
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
    int n;
    cin >> n;
    vector<string> ar(n);
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int ans = 0;
    for(char c = 'a'; c <= 'e'; c++) {
        vector<int> v(n,0);
        for(int i = 0; i < n; i++) {
            for(char &cc : ar[i]) v[i] += c == cc ? 1 : -1;
        }
        sort(v.begin(),v.end());
        int cnt = 0, all = 0;
        for(int i = n; i--;) {
            all += v[i];
            if(all > 0)cnt++;
            else break;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
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