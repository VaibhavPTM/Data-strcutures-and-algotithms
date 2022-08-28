// Link : https://atcoder.jp/contests/abc215/tasks/abc215_d
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
v(int) getSmalestDeviser(int x){
    v(int) res;
    for(int i = 2; i * i <= x; i++) {
        if((x % i) == 0) {
            while((x % i )== 0) x /= i;
            res.push_back(i);
        }
    }
    if(x != 1) res.push_back(x);
    return res;
}
void solve() {
    int n, m;
    cin >> n >> m;
    v(bool) seiav(m+2,true);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v(int) t = getSmalestDeviser(x);
        for(int &i : t) {
            if(seiav[i]) {
                for(int j = i; j <= m; j+=i) seiav[j] = false;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        if(seiav[i]) cnt++;
    }
    cout << cnt << endl;
    for(int i = 1; i <= m; i++) {
        if(seiav[i]) cout << i << endl;
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