// Link : 
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

int help(int b, int a) {
    if(a == 1) return true;
    if(__gcd(a,b) == 1) return false;
    return help(b, a / __gcd(a,b));
}
void solve() {

    lli a, b;
    cin >> a >> b;
    if(help(b,a)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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