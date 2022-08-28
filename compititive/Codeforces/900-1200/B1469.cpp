// Link : https://codeforces.com/problemset/problem/1469/B
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
int solve() {
    int n;
    cin >> n;
    int s = 0, res = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        res = max(res,s);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cout << solve() + solve() << endl;
    }
    return 0;
}