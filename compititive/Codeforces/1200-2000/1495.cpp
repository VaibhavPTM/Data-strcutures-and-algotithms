// Link : https://codeforces.com/problemset/problem/1495/A
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
#define d double 
#define mem(n,i) memset(n, i,sizeof n)
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
const lli mod = 998244353;
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    int miner[100003], mine[100003], x, y;
    x = y = 0;
    for(int i = 1; i <= n*2; i++) {
        int  a,b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        if(a == 0) {
            miner[x++] = b;
        }
        else mine[y++] = a;
    }
    sort(miner, miner + n);
    sort(mine,mine+n);
    d res = 0;
    for(int i = 0; i < n; i++) {
        res += sqrt((long long)miner[i]*miner[i] + (long long) mine[i] * mine[i]);
   }
    printf("%.15lf\n",res);
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