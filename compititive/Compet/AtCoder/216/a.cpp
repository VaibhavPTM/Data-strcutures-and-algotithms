// Link : https://atcoder.jp/contests/abc216/tasks/abc216_a
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
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
    string s;
    cin >> s;
    int n = s.size();
    if(s[n-1] >= '0' && s[n-1] <= '2') {
        cout << s.substr(0,n-2) + "-" << endl;
    }
    else if(s[n-1] >= '3' && s[n-1] <= '6') {
        cout << s.substr(0,n-2) << endl;
    }
    else {
        cout << s.substr(0,n-2) + "+" << endl;
    }
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