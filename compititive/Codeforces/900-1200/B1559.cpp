// Link : https://codeforces.com/problemset/problem/1559/B
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
    int n;
    string s;
    cin >> n >> s;
    int i = 0;
    while(i < n && s[i] == '?') i++;
    if(i == n) {
        for(int j = 0; j < n; j++) {
            s[j] = ((j&1) ? 'R' : 'B');
        }
        cout << s << endl;
        return;
    }
    for(int j = i-1; j >= 0; j--) {
        s[j] = (s[j+1] == 'R' ? 'B' : 'R');
    }
    for(;i < n; i++) {
        if(s[i] == '?') {
            s[i] = (s[i-1] == 'R' ? 'B' : 'R');
        }
    }
    cout << s << endl;
    
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