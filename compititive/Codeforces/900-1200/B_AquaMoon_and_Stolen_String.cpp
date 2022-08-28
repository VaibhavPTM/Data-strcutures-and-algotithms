// Link : https://codeforces.com/problemset/problem/1546/B
// Topic :   interactive    math    *1200
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
    int n, m;
    cin >> n >> m;
    char res[MAX] = {};
    for(int i = 0; i <2* n-1; i++) {
        string s;
        cin >> s;
        for(int i = -1; ++i < s.size();) {
            res[i] ^= s[i];
        }
    }
    puts(res);
    fflush(stdout);
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