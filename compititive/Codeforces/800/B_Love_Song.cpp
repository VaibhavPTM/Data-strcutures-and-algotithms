// Link : https://codeforces.com/problemset/problem/1539/B
// Topic : dp, implementation, strings	
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
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    int dp[n+1];
    dp[0] = 0;
    for(int i = 0;i < n; i++) {
        dp[i+1] = dp[i] + ((s[i] - 'a') + 1);
    }
    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << endl;
    }
    return 0;
}