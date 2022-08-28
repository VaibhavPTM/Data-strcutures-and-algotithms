// Link : https://codeforces.com/problemset/problem/1480/B
// Topic : 
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
    lli heroA, heroH, numM;
    lli sum = 0, mx = 0;
    cin >> heroA >> heroH >> numM;
    lli ar[numM + 1];
    for(int i = 1; i <= numM; i++) {
        cin >> ar[i];
        mx = max(mx,ar[i]);
    }
    for(int i = 1; i <= numM; i++) {
        int q, ls;
        cin >> q;
        ls = (q/heroA) + (q%heroA == 0 ? 0 : 1);
        sum += ls*ar[i];
    }
    if(sum - mx >= heroH) cout << "NO" << endl;
    else cout << "YES" << endl;
    
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